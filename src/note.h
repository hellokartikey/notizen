#ifndef NOTIZEN_NOTE_H
#define NOTIZEN_NOTE_H

#include <QColor>
#include <QDateTime>
#include <QList>
#include <QObject>
#include <QSqlQuery>
#include <QString>

class Attachment;

class Note : public QObject {
  Q_OBJECT

  // clang-format off
  Q_PROPERTY(int id
             READ id
             CONSTANT)

  Q_PROPERTY(int notebookId
             READ notebookId
             WRITE setNotebookId
             NOTIFY sigNotebookId)

  Q_PROPERTY(QString name
             READ name
             WRITE setName
             NOTIFY sigName)

  Q_PROPERTY(QString content
             READ content
             WRITE setContent
             NOTIFY sigContent)

  Q_PROPERTY(QDateTime creationDate
             READ creationDate
             WRITE setCreationDate
             NOTIFY sigCreationDate)

  Q_PROPERTY(QDateTime modifiedDate
             READ modifiedDate
             WRITE setModifiedDate
             NOTIFY sigModifiedDate)

  Q_PROPERTY(bool isArchived
             READ isArchived
             WRITE setArchived
             NOTIFY sigArchived)

  Q_PROPERTY(bool isHidden
             READ isHidden
             WRITE setHidden
             NOTIFY sigHidden)

  Q_PROPERTY(bool isPinned
             READ isPinned
             WRITE setPinned
             NOTIFY sigPinned)

  Q_PROPERTY(bool isDeleted
             READ isDeleted
             WRITE setDeleted
             NOTIFY sigDeleted)
  // clang-format on

 public:
  explicit Note(QObject* parent = nullptr);

  static auto fromQuery(const QSqlQuery& query,
                        QObject* parent = nullptr) -> Note*;

  auto sync() -> void;

  auto id() const -> int;

  auto notebookId() const -> int;
  auto setNotebookId(int notebookId) -> void;

  auto name() const -> QString;
  auto setName(const QString& name) -> void;

  auto content() const -> QString;
  auto setContent(const QString& content) -> void;

  auto color() const -> QColor;
  auto setColor(const QColor& color) -> void;

  auto creationDate() const -> QDateTime;
  auto setCreationDate(const QDateTime& date = QDateTime::currentDateTime())
      -> void;

  auto modifiedDate() const -> QDateTime;
  auto setModifiedDate(const QDateTime& date = QDateTime::currentDateTime())
      -> void;

  auto isArchived() const -> bool;
  auto setArchived(bool isArchived = true) -> void;

  auto isHidden() const -> bool;
  auto setHidden(bool isHidden = true) -> void;

  auto isPinned() const -> bool;
  auto setPinned(bool isPinned = true) -> void;

  auto isDeleted() const -> bool;
  auto setDeleted(bool isDeleted = true) -> void;

 Q_SIGNALS:
  auto sigNotebookId() -> void;

  auto sigName() -> void;
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

  QString m_name;
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
