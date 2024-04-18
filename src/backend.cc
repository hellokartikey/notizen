#include "backend.h"

#include <QApplication>
#include <QSqlQuery>
#include <QSqlRecord>

using namespace Qt::Literals::StringLiterals;

Backend::Backend(QObject* parent) : QObject(parent) {
  m_db = QSqlDatabase::addDatabase(u"QSQLITE"_s);
  m_db.setDatabaseName(u"test.db"_s);

  m_ok = m_db.open();

  initDb();
  readNotes();
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
        isArchived   BOOLEAN DEFAULT FALSE NOT NULL,             \
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
      u"CREATE TABLE IF NOT EXISTS tags (      \
        id   INTEGER PRIMARY KEY,              \
        name TEXT    NOT NULL                  \
      );"_s);
  query.exec();
}

auto Backend::readNotes() -> void {
  auto query = QSqlQuery(u"SELECT * FROM notes;"_s);

  auto readRecord = [&](const QString& column) {
    return query.value(query.record().indexOf(column));
  };

  while (query.next()) {
    auto* tmpNote = new Note(this);

    tmpNote->setId(readRecord(u"id"_s).toInt());
    tmpNote->setNotebookId(readRecord(u"notebookId"_s).toInt());
    tmpNote->setTitle(readRecord(u"name"_s).toString());
    tmpNote->setContent(readRecord(u"content"_s).toString());
    tmpNote->setColor(QColor(readRecord(u"color"_s).toString()));
    tmpNote->setCreationDate(
        QDateTime::fromSecsSinceEpoch(readRecord(u"creationDate"_s).toInt()));
    tmpNote->setModifiedDate(
        QDateTime::fromSecsSinceEpoch(readRecord(u"modifiedDate"_s).toInt()));
    tmpNote->setArchived(readRecord(u"isArchived"_s).toBool());
    tmpNote->setHidden(readRecord(u"isHidden"_s).toBool());
    tmpNote->setPinned(readRecord(u"isPinned"_s).toBool());
    tmpNote->setDeleted(readRecord(u"isDeleted"_s).toBool());

    m_notes << tmpNote;
  }
}

auto Backend::notes() -> NoteList { return m_notes; }

auto Backend::currentNote() -> Note* { return m_current_note; }

auto Backend::setCurrentNote(Note* note) -> void {
  if (note == m_current_note) {
    return;
  }

  m_current_note = note;
  Q_EMIT sigCurrentNote();
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

auto Backend::quit() -> void { QApplication::quit(); }

#include "moc_backend.cpp"
