#include "backend.h"

#include <QApplication>
#include <QSqlQuery>
#include <QSqlRecord>
#include <algorithm>

using namespace Qt::Literals::StringLiterals;

Backend::Backend(QObject* parent) : QObject(parent) {
  m_db = QSqlDatabase::addDatabase(u"QSQLITE"_s);
  m_db.setDatabaseName(u"test.db"_s);

  m_ok = m_db.open();

  initDb();

  readNotes();
  readNotebooks();
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
}

auto Backend::readNotes() -> void {
  auto query = QSqlQuery(u"SELECT * FROM notes;"_s);

  while (query.next()) {
    auto* tmpNote = Note::fromQuery(query, this);

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

void Backend::addNote(const QString& name) {
  auto query = QSqlQuery{};

  query.prepare(
      u"INSERT INTO notes (notebookId, name) VALUES (:notebookId, :name);"_s);
  if (currentNotebook() && currentNotebook()->id() != 0) {
    query.bindValue(u":notebookId"_s, currentNotebook()->id());
  }
  query.bindValue(u":name"_s, name);
  query.exec();

  query.prepare(u"SELECT * FROM notes WHERE name = :name;"_s);
  query.bindValue(u":name"_s, name);
  query.exec();
  query.first();

  auto* note_ptr = Note::fromQuery(query, this);
  note_ptr->setCreationDate();
  note_ptr->setModifiedDate();

  m_notes << note_ptr;
  Q_EMIT sigNotes();

  setCurrentNote(note_ptr);
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

auto Backend::readNotebooks() -> void {
  auto query = QSqlQuery{};

  query.prepare(u"SELECT id, name FROM notebooks;"_s);
  query.exec();

  while (query.next()) {
    auto* notebook = new Notebook(this);
    notebook->setId(query.value(u"id"_s).toInt());
    notebook->setName(query.value(u"name"_s).toString());
    m_notebooks << notebook;
  }

  auto* other = new Notebook(this);
  other->setId(0);
  other->setName(u"Others"_s);
  m_notebooks << other;

  setCurrentNotebook(other);

  Q_EMIT sigNotebooks();
}

auto Backend::notebooks() -> NotebookList { return m_notebooks; }

auto Backend::notebook(const QString& name) -> Notebook* {
  auto iter =
      std::find_if(m_notebooks.begin(), m_notebooks.end(),
                   [&](auto notebook) { return notebook->name() == name; });

  if (iter == m_notebooks.end()) {
    return nullptr;
  }

  return *iter;
}

auto Backend::currentNotebook() -> Notebook* { return m_current_notebook; }

auto Backend::setCurrentNotebook(Notebook* notebook) -> void {
  if (m_current_notebook == notebook) {
    return;
  }

  m_current_notebook = notebook;
  Q_EMIT sigCurrentNotebook();
}

auto Backend::notesInNotebook(const Notebook* notebook) -> NoteList {
  auto list = NoteList{};

  for (auto* note: m_notes) {
    if (note->notebookId() == notebook->id()) {
      list << note;
    }
  }

  return list;
}

auto Backend::addNotebook(const QString& name) -> void {
  if (notebook(name) != nullptr) return;

  auto query = QSqlQuery{};

  query.prepare(u"INSERT INTO notebooks (name) VALUES (:name);"_s);
  query.bindValue(u":name"_s, name);
  query.exec();

  query.prepare(u"SELECT id, name FROM notebooks WHERE name = :name;"_s);
  query.bindValue(u":name"_s, name);
  query.exec();
  query.first();

  auto* notebook_ptr = new Notebook(this);
  notebook_ptr->setId(query.value(u"id"_s).toInt());
  notebook_ptr->setName(query.value(u"name"_s).toString());

  m_notebooks << notebook_ptr;
  Q_EMIT sigNotebooks();
}

auto Backend::quit() -> void { QApplication::quit(); }

#include "moc_backend.cpp"
