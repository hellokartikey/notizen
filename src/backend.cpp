#include "backend.hpp"

#include <QDir>
#include <QObject>
#include <QString>

Backend::Backend(QObject* parent)
    : QObject(parent) {
  tree().setRootPath(QDir::currentPath());
}

FileModel& Backend::tree() {
  return m_fs_tree;
}

const FileModel& Backend::tree() const {
  return m_fs_tree;
}

Backend* Backend::get() {
  static auto instance = Backend{nullptr};
  return &instance;
}

Backend* Backend::create(QQmlEngine* qml, QJSEngine* js) {
  std::ignore = qml;
  std::ignore = js;

  auto* ptr = Backend::get();
  QJSEngine::setObjectOwnership(ptr, QJSEngine::CppOwnership);

  return ptr;
}

QString Backend::hello() const {
  return tree().rootPath();
}

FileModel* Backend::getTree() {
  return &tree();
}

#include "moc_backend.cpp"
