#include "backend.h"

#include <QSqlQuery>

Backend::Backend(QObject* parent) : QObject(parent) {
  using namespace Qt::Literals::StringLiterals;

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
  using namespace Qt::Literals::StringLiterals;

  auto query = QSqlQuery{};

  // meta table
  query.prepare(u"CREATE TABLE IF NOT EXISTS notizen (version TEXT);"_s);
  query.exec();

  // notes table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS notes (                       \
        id           INT     PRIMARY KEY,                        \
        notebookId   INT     DEFAULT NULL,                       \
        title        TEXT    DEFAULT NULL,                       \
        content      TEXT    DEFAULT NULL,                       \
        color        TEXT    DEFAULT NULL,                       \
        creationDate INT     DEFAULT CURRENT_TIMESTAMP NOT NULL, \
        modifiedDate INT     DEFAULT CURRENT_TIMESTAMP NOT NULL, \
        isArchive    BOOLEAN DEFAULT FALSE NOT NULL,             \
        isHidden     BOOLEAN DEFAULT FALSE NOT NULL,             \
        isPinned     BOOLEAN DEFAULT FALSE NOT NULL,             \
        isDeleted    BOOLEAN DEFAULT FALSE NOT NULL              \
      );"_s);
  query.exec();

  // notebooks table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS notebooks ( \
        id   INT  PRIMARY KEY,                 \
        name TEXT NOT NULL UNIQUE              \
      );"_s);
  query.exec();

  // attachments table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS attachments ( \
        id      INT  PRIMARY KEY,                \
        content BLOB NOT NULL,                   \
        sha256  TEXT NOT NULL UNIQUE             \
      );"_s);
  query.exec();

  // hash tags table
  query.prepare(
      u"CREATE TABLE IF NOT EXISTS hash_tags ( \
        id INT PRIMARY KEY,                    \
        name TEXT NOT NULL                     \
      )"_s);
  query.exec();
}

auto Backend::hashTags() -> QStringList { return {}; }

#include "moc_backend.cpp"
