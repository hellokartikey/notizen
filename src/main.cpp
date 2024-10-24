#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "backend.hpp"

int main(int argc, char* argv[]) {
  using namespace Qt::Literals;

  auto app = QGuiApplication{argc, argv};
  auto qml = QQmlApplicationEngine{};

  QObject::connect(
      &qml, &QQmlApplicationEngine::objectCreationFailed, &app,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

  qml.loadFromModule("Notizen", "Main");

  return app.exec();
}
