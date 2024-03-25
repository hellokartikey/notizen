#include "actions.h"

Actions::Actions(QApplication& app, QObject* parent)
    : QObject(parent), m_app(app) {}

auto Actions::inst(QApplication& app) -> Actions* {
  static auto action = Actions{app};

  return &action;
}

auto Actions::quit() -> void { m_app.quit(); }

#include "moc_actions.cpp"
