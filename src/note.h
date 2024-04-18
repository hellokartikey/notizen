#ifndef NOTIZEN_NOTE_H
#define NOTIZEN_NOTE_H

#include <QColor>
#include <QDateTime>
#include <QList>
#include <QObject>
#include <QString>

class Attachment;

class Note : public QObject {
  Q_OBJECT

  Q_PROPERTY(int id READ id WRITE setId NOTIFY sigId)
  Q_PROPERTY(
      int notebookId READ notebookId WRITE setNotebookId NOTIFY sigNotebookId)
  Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY sigTitle)
  Q_PROPERTY(QString content READ content WRITE setContent NOTIFY sigContent)

  Q_PROPERTY(QDateTime creationDate READ creationDate WRITE setCreationDate NOTIFY sigCreationDate)
  Q_PROPERTY(QDateTime modifiedDate READ modifiedDate WRITE setModifiedDate NOTIFY sigModifiedDate)

 public:
  explicit Note(QObject* parent = nullptr);

  auto id() -> int;
  auto setId(int id) -> void;

  auto notebookId() -> int;
  auto setNotebookId(int notebookId) -> void;

  auto title() -> QString;
  auto setTitle(const QString& title) -> void;

  auto content() -> QString;
  auto setContent(const QString& content) -> void;

  auto color() -> QColor;
  auto setColor(const QColor& color) -> void;

  auto creationDate() -> QDateTime;
  auto setCreationDate(const QDateTime& date) -> void;

  auto modifiedDate() -> QDateTime;
  auto setModifiedDate(const QDateTime& date) -> void;

  auto isArchived() -> bool;
  auto setArchived(bool isArchived = true) -> void;

  auto isHidden() -> bool;
  auto setHidden(bool isHidden = true) -> void;

  auto isPinned() -> bool;
  auto setPinned(bool isPinned = true) -> void;

  auto isDeleted() -> bool;
  auto setDeleted(bool isDeleted = true) -> void;

 Q_SIGNALS:
  auto sigId() -> void;
  auto sigNotebookId() -> void;

  auto sigTitle() -> void;
  auto sigContent() -> void;

  auto sigColor() -> void;

  auto sigCreationDate() -> void;
  auto sigModifiedDate() -> void;

  auto sigArchived() -> void;
  auto sigHidden() -> void;
  auto sigPinned() -> void;
  auto sigDeleted() -> void;

 private:
  int m_note_id;
  int m_notebook;

  QString m_title;
  QString m_content;

  QColor m_color;

  QDateTime m_creation_date;
  QDateTime m_modified_date;

  bool m_is_archived;
  bool m_is_hidden;
  bool m_is_pinned;
  bool m_is_deleted;

  QStringList m_tags;
  QList<Attachment*> m_attachments;
};

using NoteList = QList<Note*>;

#endif
