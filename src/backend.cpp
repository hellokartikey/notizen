#include "backend.hpp"

#include <QObject>
#include <QString>

Backend::Backend(QObject* parent)
    : QObject(parent) {}

Backend* Backend::get() {
  static auto instance = Backend{nullptr};
  return &instance;
}

QString Backend::hello() const {
  return "Hello, World!";
}

#include "moc_backend.cpp"
