#ifndef NOTIZEN_BACKEND_H
#define NOTIZEN_BACKEND_H

#include <QColor>
#include <QObject>
#include <QSqlDatabase>
#include <QString>

#include "note.h"
#include "notebook.h"

class Backend : public QObject {
  Q_OBJECT

  Q_PROPERTY(NoteList notes READ notes NOTIFY sigNotes)
  Q_PROPERTY(Note* currentNote READ currentNote WRITE setCurrentNote NOTIFY
                 sigCurrentNote)

  Q_PROPERTY(QStringList tags READ tags NOTIFY sigHashTags)

  Q_PROPERTY(NotebookList notebooks READ notebooks NOTIFY sigNotebooks)
  Q_PROPERTY(Notebook* currentNotebook READ currentNotebook WRITE
                 setCurrentNotebook NOTIFY sigCurrentNotebook)

  Q_PROPERTY(bool isDbOk READ isDbOk NOTIFY sigIsDbOk)

 public:
  explicit Backend(QObject* parent = nullptr);

  static auto inst() -> Backend*;

  auto initDb() -> void;
  auto isDbOk() const -> bool;

  // Notes related methods
  auto readNotes() -> void;

  auto notes() -> NoteList;

  auto currentNote() -> Note*;
  auto setCurrentNote(Note* note = nullptr) -> void;

  // BUG: Fix date time parsing
  Q_INVOKABLE void addNote(const QString& name);

  // Tags related methods
  auto tags() -> QStringList;

  // Notebook related methods
  auto readNotebooks() -> void;

  auto notebooks() -> NotebookList;

  auto notebook(const QString& name) -> Notebook*;

  auto currentNotebook() -> Notebook*;
  auto setCurrentNotebook(Notebook* notebook = nullptr) -> void;

  Q_INVOKABLE void addNotebook(const QString& name);

  // Actions
  Q_INVOKABLE void quit();

 Q_SIGNALS:
  auto sigIsDbOk() -> void;

  auto sigNotes() -> void;
  auto sigCurrentNote() -> void;

  auto sigHashTags() -> void;

  auto sigNotebooks() -> void;
  auto sigCurrentNotebook() -> void;

 private:
  QSqlDatabase m_db;
  bool m_ok;

  NoteList m_notes;
  Note* m_current_note = nullptr;

  NotebookList m_notebooks;
  Notebook* m_current_notebook = nullptr;
};

#endif
