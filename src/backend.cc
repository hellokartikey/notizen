#include "backend.h"

Backend::Backend(QObject* parent) : QObject(parent) {}

auto Backend::inst() -> Backend* {
  static auto backend = Backend();

  return &backend;
}

