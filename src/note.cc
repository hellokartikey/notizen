#include "note.h"

#include <QSqlError>

Note::Note(QObject* parent) : QObject(parent) {}

auto Note::fromQuery(const QSqlQuery& query, QObject* parent) -> Note* {
  using namespace Qt::Literals::StringLiterals;

  auto readInt = [&](const QString& name) { return query.value(name).toInt(); };

  auto readString = [&](const QString& name) {
    return query.value(name).toString();
  };

  auto readBool = [&](const QString& name) {
    return query.value(name).toBool();
  };

  auto readColor = [&](const QString& name) {
    return QColor(readString(name));
  };

  auto readTime = [&](const QString& name) {
    return QDateTime::fromSecsSinceEpoch(readInt(name));
  };

  auto* note = new Note(parent);

  note->m_note_id = readInt(u"id"_s);
  note->m_notebook = readInt(u"notebookId"_s);
  note->m_name = readString(u"name"_s);
  note->m_content = readString(u"content"_s);
  note->m_color = readColor(u"color"_s);
  note->m_creation_date = readTime(u"creationDate"_s);
  note->m_modified_date = readTime(u"modifiedDate"_s);
  note->m_is_archived = readBool(u"isArchived"_s);
  note->m_is_hidden = readBool(u"isHidden"_s);
  note->m_is_pinned = readBool(u"isPinned"_s);
  note->m_is_deleted = readBool(u"isDeleted"_s);

  return note;
}

auto Note::sync() -> void {
  using namespace Qt::Literals::StringLiterals;

  m_modified_date = QDateTime::currentDateTime();

  auto query = QSqlQuery{};
  query.prepare(
      u"UPDATE notes SET  \
      notebookId   = :notebookId,   \
      name         = :name,         \
      content      = :content,      \
      color        = :color,        \
      creationDate = :creationDate, \
      modifiedDate = :modifiedDate, \
      isArchived   = :isArchived,   \
      isHidden     = :isHidden,     \
      isPinned     = :isPinned,     \
      isDeleted    = :isDeleted     \
    WHERE id = :id;"_s);

  query.bindValue(u":id"_s, id());
  query.bindValue(u":notebookId"_s, notebookId());
  query.bindValue(u":name"_s, name());
  query.bindValue(u":content"_s, content());
  query.bindValue(u":color"_s, color());
  query.bindValue(u":creationDate"_s, creationDate().toString());
  query.bindValue(u":modifiedDate"_s, modifiedDate().toString());
  query.bindValue(u":isArchived"_s, isArchived());
  query.bindValue(u":isHidden"_s, isHidden());
  query.bindValue(u":isPinned"_s, isPinned());
  query.bindValue(u":isDeleted"_s, isDeleted());

  query.exec();
}

auto Note::id() const -> int { return m_note_id; }

auto Note::notebookId() const -> int { return m_notebook; }

auto Note::setNotebookId(int notebookId) -> void {
  if (m_notebook == notebookId) {
    return;
  }

  m_notebook = notebookId;
  sync();
  Q_EMIT sigNotebookId();
}

auto Note::name() const -> QString { return m_name; }

auto Note::setName(const QString& name) -> void {
  if (name == m_name) {
    return;
  }

  m_name = name;
  sync();
  Q_EMIT sigName();
}

auto Note::content() const -> QString { return m_content; }

auto Note::setContent(const QString& content) -> void {
  if (content == m_content) {
    return;
  }

  m_content = content;
  sync();
  Q_EMIT sigContent();
}

auto Note::color() const -> QColor { return m_color; }

auto Note::setColor(const QColor& color) -> void {
  if (color == m_color) {
    return;
  }

  m_color = color;
  sync();
  Q_EMIT sigColor();
}

auto Note::creationDate() const -> QDateTime { return m_creation_date; }

auto Note::setCreationDate(const QDateTime& date) -> void {
  if (date == m_creation_date) {
    return;
  }

  m_creation_date = date;
  sync();
  Q_EMIT sigCreationDate();
}

auto Note::modifiedDate() const -> QDateTime { return m_modified_date; }

auto Note::setModifiedDate(const QDateTime& date) -> void {
  if (date == m_modified_date) {
    return;
  }

  m_modified_date = date;
  sync();
  Q_EMIT sigModifiedDate();
}

auto Note::isArchived() const -> bool { return m_is_archived; }

auto Note::setArchived(bool isArchived) -> void {
  if (m_is_archived == isArchived) {
    return;
  }

  m_is_archived = isArchived;
  sync();
  Q_EMIT sigArchived();
}

auto Note::isHidden() const -> bool { return m_is_hidden; }

auto Note::setHidden(bool isHidden) -> void {
  if (m_is_hidden == isHidden) {
    return;
  }

  m_is_hidden = isHidden;
  sync();
  Q_EMIT sigHidden();
}

auto Note::isPinned() const -> bool { return m_is_pinned; }

auto Note::setPinned(bool isPinned) -> void {
  if (m_is_pinned == isPinned) {
    return;
  }

  m_is_pinned = isPinned;
  sync();
  Q_EMIT sigPinned();
}

auto Note::isDeleted() const -> bool { return m_is_deleted; }

auto Note::setDeleted(bool isDeleted) -> void {
  if (m_is_deleted == isDeleted) {
    return;
  }

  m_is_deleted = isDeleted;
  sync();
  Q_EMIT sigDeleted();
}

#include "moc_note.cpp"
