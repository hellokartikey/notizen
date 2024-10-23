#ifndef HK_NOTIZEN_BACKEND_HPP
#define HK_NOTIZEN_BACKEND_HPP

#include <QFileSystemModel>
#include <QQmlEngine>
#include <QJSEngine>
#include <QObject>
#include <QString>

#include "filemodel.hpp"

class Backend : public QObject {
  Q_OBJECT;
  QML_ELEMENT;
  QML_SINGLETON;

  Q_PROPERTY(FileModel* tree READ getTree CONSTANT);

 private:
  Backend(QObject* parent = nullptr);

  FileModel& tree();
  [[nodiscard]] const FileModel& tree() const;

 public:
  static Backend* get();

  static Backend* create(QQmlEngine* qml, QJSEngine* js);

  Q_INVOKABLE [[nodiscard]] QString hello() const;

  FileModel* getTree();

 private:
  FileModel m_fs_tree;
};

#endif
