#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>

#include "backend.h"

auto main(int argc, char* argv[]) -> int {
  using namespace Qt::Literals::StringLiterals;

  auto app = QApplication{argc, argv};
  auto engine = QQmlApplicationEngine{};

  engine.rootContext()->setContextProperty(u"backend"_s, Backend::inst());

  engine.load(u"qrc:/main.qml"_s);

  return app.exec();
}

