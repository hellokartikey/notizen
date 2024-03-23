#include "backend.h"

Backend::Backend(QObject* parent) : QObject(parent) {}

auto Backend::inst() -> Backend* {
  static auto backend = Backend{};

  return &backend;
}

auto Backend::hashTags() const -> QStringList {
  // TODO
  using namespace Qt::Literals::StringLiterals;

  return {u"lmao"_s, u"test"_s};
}
