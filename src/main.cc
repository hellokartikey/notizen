#include <qqml.h>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QString>

#include "actions.h"
#include "backend.h"

auto main(int argc, char* argv[]) -> int {
  using namespace Qt::Literals::StringLiterals;

  auto app = QApplication{argc, argv};
  auto engine = QQmlApplicationEngine{};

  qmlRegisterSingletonInstance("Notizen", 1, 0, "Backend", Backend::inst());
  qmlRegisterSingletonInstance("Notizen", 1, 0, "Actions", Actions::inst(app));

  engine.load(u"qrc:/main.qml"_s);

  return app.exec();
}
