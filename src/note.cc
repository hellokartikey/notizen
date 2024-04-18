#include "note.h"

Note::Note(QObject* parent) : QObject(parent) {}

auto Note::id() -> int { return m_note_id; }

auto Note::setId(int id) -> void {
  if (m_note_id == id) {
    return;
  }

  m_note_id = id;
  Q_EMIT sigId();
}

auto Note::notebookId() -> int { return m_notebook; }

auto Note::setNotebookId(int notebookId) -> void {
  if (m_notebook == notebookId) {
    return;
  }

  m_notebook = notebookId;
  Q_EMIT sigNotebookId();
}

auto Note::title() -> QString { return m_title; }

auto Note::setTitle(const QString& title) -> void {
  if (title == m_title) {
    return;
  }

  m_title = title;
  Q_EMIT sigTitle();
}

auto Note::content() -> QString { return m_content; }

auto Note::setContent(const QString& content) -> void {
  if (content == m_content) {
    return;
  }

  m_content = content;
  Q_EMIT sigContent();
}

auto Note::color() -> QColor { return m_color; }

auto Note::setColor(const QColor& color) -> void {
  if (color == m_color) {
    return;
  }

  m_color = color;
  Q_EMIT sigColor();
}

auto Note::creationDate() -> QDateTime { return m_creation_date; }

auto Note::setCreationDate(const QDateTime& date) -> void {
  if (date == m_creation_date) {
    return;
  }

  m_creation_date = date;
  Q_EMIT sigCreationDate();
}

auto Note::modifiedDate() -> QDateTime { return m_modified_date; }

auto Note::setModifiedDate(const QDateTime& date) -> void {
  if (date == m_modified_date) {
    return;
  }

  m_modified_date = date;
  Q_EMIT sigModifiedDate();
}

auto Note::isArchived() -> bool { return m_is_archived; }

auto Note::setArchived(bool isArchived) -> void {
  if (m_is_archived == isArchived) {
    return;
  }

  m_is_archived = isArchived;
  Q_EMIT sigArchived();
}

auto Note::isHidden() -> bool { return m_is_hidden; }

auto Note::setHidden(bool isHidden) -> void {
  if (m_is_hidden == isHidden) {
    return;
  }

  m_is_hidden = isHidden;
  Q_EMIT sigHidden();
}

auto Note::isPinned() -> bool { return m_is_pinned; }

auto Note::setPinned(bool isPinned) -> void {
  if (m_is_pinned == isPinned) {
    return;
  }

  m_is_pinned = isPinned;
  Q_EMIT sigPinned();
}

auto Note::isDeleted() -> bool { return m_is_deleted; }

auto Note::setDeleted(bool isDeleted) -> void {
  if (m_is_deleted == isDeleted) {
    return;
  }

  m_is_deleted = isDeleted;
  Q_EMIT sigDeleted();
}

#include "moc_note.cpp"
