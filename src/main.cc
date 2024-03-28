#include <QApplication>
#include <QQmlApplicationEngine>
#include <QString>

#include "backend.h"

auto main(int argc, char* argv[]) -> int {
  using namespace Qt::Literals::StringLiterals;

  auto app = QApplication{argc, argv};
  auto engine = QQmlApplicationEngine{};

  qmlRegisterSingletonInstance("Notizen", 1, 0, "Backend", Backend::inst());

  engine.load(u"qrc:/main.qml"_s);

  return app.exec();
}
