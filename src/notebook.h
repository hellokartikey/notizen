#ifndef NOTIZEN_NOTEBOOK_H
#define NOTIZEN_NOTEBOOK_H

#include <QList>
#include <QObject>

#include "fwd.h"

class Notebook : public QObject {
  Q_OBJECT;

  // clang-format off
  Q_PROPERTY(int          id
             READ         id
             WRITE        setId
             NOTIFY       sigId)

  Q_PROPERTY(QString      name
             READ         name
             WRITE        setName
             NOTIFY       sigName)

  Q_PROPERTY(NotebookList children
             READ         children
             NOTIFY       sigChildren)

  Q_PROPERTY(NoteList     notes
             READ         notes
             NOTIFY       sigNotes)
  // clang-format on

 public:
  explicit Notebook(QObject* parent = nullptr);

  auto id() const -> int;
  auto setId(int id) -> void;

  auto name() const -> QString;
  auto setName(const QString& name) -> void;

  auto children() -> NotebookList;
  auto readChildren() -> void;

  auto notes() -> NoteList;
  auto readNotes() -> void;

 Q_SIGNALS:
  auto sigId() -> void;
  auto sigName() -> void;
  auto sigChildren() -> void;
  auto sigNotes() -> void;

 private:
  int m_id;
  QString m_name;

  NotebookList m_children;
  NoteList m_notes;
};

#endif
