#ifndef NOTIZEN_BACKEND_H
#define NOTIZEN_BACKEND_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>

class Backend : public QObject {
  Q_OBJECT

  Q_PROPERTY(QStringList tags READ tags NOTIFY sigHashTags)
  Q_PROPERTY(QStringList notebooks READ notebooks NOTIFY sigNotebooks)

  Q_PROPERTY(bool isDbOk READ isDbOk NOTIFY sigIsDbOk)

 public:
  explicit Backend(QObject* parent = nullptr);

  static auto inst() -> Backend*;

  auto initDb() -> void;
  auto isDbOk() const -> bool;

  auto tags() -> QStringList;

  auto notebooks() -> QStringList;
  Q_INVOKABLE void addNotebook(const QString& name);

 Q_SIGNALS:
  auto sigIsDbOk() -> void;

  auto sigHashTags() -> void;
  auto sigNotebooks() -> void;

 private:
  QSqlDatabase m_db;
  bool m_ok;
};

#endif
