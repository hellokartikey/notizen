#ifndef NOTIZEN_NOTE_H
#define NOTIZEN_NOTE_H

#include <QDate>
#include <QList>
#include <QObject>
#include <QString>

class Attachment;

class Note : public QObject {
  Q_OBJECT

 public:
  explicit Note(QObject* parent = nullptr);

 private:
  int m_note_id;

  QString m_title;
  QString m_notebook;
  QString m_content;

  QString m_color;

  QDate m_creation_date;
  QDate m_modified_date;

  bool m_is_archived;
  bool m_is_hidden;
  bool m_is_pinned;
  bool m_is_deleted;

  QList<Attachment*> m_attachments;
};

using NoteList = QList<Note*>;

#endif
