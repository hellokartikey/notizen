#ifndef HK_NOTIZEN_BACKEND_HPP
#define HK_NOTIZEN_BACKEND_HPP

#include <QFileSystemModel>
#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QString>

#include "filemodel.hpp"

class Backend : public QObject {
  Q_OBJECT;
  QML_ELEMENT;
  QML_SINGLETON;

  Q_PROPERTY(FileModel* tree READ getTree CONSTANT);
  Q_PROPERTY(QString currentNote READ getCurrentNote WRITE setCurrentNote NOTIFY sigCurrentNote);

 private:
  Backend(QObject* parent = nullptr);

 public:
  static Backend* get();
  static Backend* create(QQmlEngine* qml, QJSEngine* js);

  Q_INVOKABLE [[nodiscard]] QString hello() const;

  FileModel& tree();
  [[nodiscard]] const FileModel& tree() const;
  FileModel* getTree();

  Q_INVOKABLE void openNote(const QString& path);

  QString& currentNote();
  const QString& currentNote() const;
  const QString& getCurrentNote() const;
  void setCurrentNote(const QString& new_value);
  Q_SIGNAL void sigCurrentNote();

 private:
  FileModel m_fs_tree;
  QString m_current_note;
};

#endif
