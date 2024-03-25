#ifndef NOTIZEN_BACKEND_H
#define NOTIZEN_BACKEND_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

class Backend : public QObject {
  Q_OBJECT

  Q_PROPERTY(QStringList hashTags READ hashTags CONSTANT)

  Q_PROPERTY(bool isDbOk READ isDbOk NOTIFY sigIsDbOk)

 public:
  explicit Backend(QObject* parent = nullptr);

  static auto inst() -> Backend*;

  auto initDb() -> void;

  auto isDbOk() const -> bool;

  auto hashTags() -> QStringList;

 Q_SIGNALS:
  auto sigIsDbOk() -> void;

 private:
  QSqlDatabase m_db;
  bool m_ok;
};

#endif
