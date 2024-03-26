#include "backend.h"

#include <QSqlQuery>

using namespace Qt::Literals::StringLiterals;

Backend::Backend(QObject* parent) : QObject(parent) {
  m_db = QSqlDatabase::addDatabase(u"QSQLITE"_s);
  m_db.setDatabaseName(u"test.db"_s);

  m_ok = m_db.open();

  initDb();
}

auto Backend::inst() -> Backend* {
  static auto backend = Backend{};

  return &backend;
}

auto Backend::isDbOk() const -> bool { return m_ok; }

auto Backend::initDb() -> void {
  auto query = QSqlQuery{};

  // meta table
  query.prepare(u"CREATE TABLE IF NOT EXISTS notizen (version TEXT);"_s);
  query.exec();

  // notes table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS notes (                       \
        id           INTEGER PRIMARY KEY,                        \
        notebookId   INTEGER DEFAULT NULL,                       \
        name         TEXT    DEFAULT NULL,                       \
        content      TEXT    DEFAULT NULL,                       \
        color        TEXT    DEFAULT NULL,                       \
        creationDate INTEGER DEFAULT CURRENT_TIMESTAMP NOT NULL, \
        modifiedDate INTEGER DEFAULT CURRENT_TIMESTAMP NOT NULL, \
        isArchive    BOOLEAN DEFAULT FALSE NOT NULL,             \
        isHidden     BOOLEAN DEFAULT FALSE NOT NULL,             \
        isPinned     BOOLEAN DEFAULT FALSE NOT NULL,             \
        isDeleted    BOOLEAN DEFAULT FALSE NOT NULL              \
      );"_s);
  query.exec();

  // notebooks table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS notebooks ( \
        id   INTEGER PRIMARY KEY,              \
        name TEXT    NOT NULL UNIQUE           \
      );"_s);
  query.exec();

  // attachments table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS attachments ( \
        id      INTEGER PRIMARY KEY,             \
        content BLOB    NOT NULL,                \
        sha256  TEXT    NOT NULL UNIQUE          \
      );"_s);
  query.exec();

  // hash tags table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS hash_tags ( \
        id   INTEGER PRIMARY KEY,              \
        name TEXT    NOT NULL                  \
      )"_s);
  query.exec();
}

auto Backend::tags() -> QStringList {
  auto query = QSqlQuery{};

  query.prepare(u"SELECT DISTINCT name FROM hash_tags;"_s);
  query.exec();

  auto list = QStringList{};

  while (query.next()) {
    list << query.value(u"name"_s).toString();
  }

  return list;
}

auto Backend::notebooks() -> QStringList {
  auto query = QSqlQuery{};

  query.prepare(u"SELECT name FROM notebooks;"_s);
  query.exec();

  auto list = QStringList{};

  list << u"Other"_s;
  while (query.next()) {
    list << query.value(u"name"_s).toString();
  }

  return list;
}

auto Backend::addNotebook(const QString& name) -> void {
  auto query = QSqlQuery{};

  query.prepare(u"INSERT INTO notebooks (name) VALUES (:name);"_s);
  query.bindValue(u":name"_s, name);

  if (query.exec()) {
    Q_EMIT sigNotebooks();
  }
}

#include "moc_backend.cpp"
