#ifndef NOTIZEN_BACKEND_H
#define NOTIZEN_BACKEND_H

#include <QObject>
#include <QString>

class Backend : public QObject {
  Q_OBJECT

  Q_PROPERTY(QStringList hashTags READ hashTags CONSTANT)

 public:
  explicit Backend(QObject* parent = nullptr);

  static auto inst() -> Backend*;

  auto hashTags() const -> QStringList;
};

#endif
