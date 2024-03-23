#ifndef NOTIZEN_ACTIONS_H
#define NOTIZEN_ACTIONS_H

#include <QApplication>
#include <QObject>

class Actions : public QObject {
  Q_OBJECT

 public:
  Actions(QApplication& app, QObject* parent = nullptr);

  static auto inst(QApplication& app) -> Actions*;

 public:  // Actions
  Q_INVOKABLE void quit();

 private:
  QApplication& m_app;
};

#endif
