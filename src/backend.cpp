#include "backend.hpp"

#include <fmt/core.h>

#include <QDir>
#include <QObject>
#include <QString>

#include <libassert/assert.hpp>

#include "fmt.hpp"

Backend::Backend(QObject* parent)
    : QObject(parent) {
  tree().setRootPath(QDir::currentPath());
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

FileModel& Backend::tree() {
  return m_fs_tree;
}

const FileModel& Backend::tree() const {
  return m_fs_tree;
}

FileModel* Backend::getTree() {
  return &tree();
}

void Backend::openNote(const QString& path) {
  PANIC("TODO - Implement this", path);
}

QString& Backend::currentNote() {
  return m_current_note;
}

const QString& Backend::currentNote() const {
  return m_current_note;
}

const QString& Backend::getCurrentNote() const {
  return currentNote();
}

void Backend::setCurrentNote(const QString& new_value) {
  if (new_value == currentNote()) {
    return;
  }

  currentNote() = new_value;
  Q_EMIT sigCurrentNote();
}

#include "moc_backend.cpp"
