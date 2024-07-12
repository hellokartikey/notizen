#include "notebook.h"

#include <QSqlQuery>
#include <QSqlRecord>

#include "note.h"

using namespace Qt::Literals::StringLiterals;

Notebook::Notebook(QObject* parent) : QObject(parent) {}

auto Notebook::id() const -> int { return m_id; }

auto Notebook::setId(int id) -> void {
  if (id == m_id) return;
  m_id = id;
  Q_EMIT sigId();
}

auto Notebook::name() const -> QString { return m_name; }

auto Notebook::setName(const QString& name) -> void {
  if (name == m_name) return;
  m_name = name;
  Q_EMIT sigName();
}

auto Notebook::children() -> NotebookList { return m_children; }

auto Notebook::readChildren() -> void {
  auto query = QSqlQuery{};

  query.prepare(u"SELECT id, name FROM notebooks WHERE parent IS :notebookId;"_s);
  query.bindValue(u":notebookId"_s, id());
  query.exec();

  while (query.next()) {
    auto* notebook = new Notebook(this);
    notebook->setId(query.value(u"id"_s).toInt());
    notebook->setName(query.value(u"name"_s).toString());
    notebook->readChildren();
    m_children << notebook;
  }

  Q_EMIT sigChildren();
}

auto Notebook::notes() -> NoteList { return m_notes; }

auto Notebook::readNotes() -> void {
  auto query = QSqlQuery(u"SELECT * FROM notes \
    WHERE notebookId = :notebookId;"_s);
  query.bindValue(u":notebookId"_s, id());

  while (query.next()) {
    auto* tmpNote = Note::fromQuery(query, this);

    m_notes << tmpNote;
  }
}
