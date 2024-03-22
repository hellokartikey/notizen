#ifndef NOTIZEN_BACKEND_H
#define NOTIZEN_BACKEND_H

#include <QObject>

class Backend : public QObject {
  Q_OBJECT

public:
  Backend(QObject* parent=nullptr);

  static auto inst() -> Backend*;
};

#endif

