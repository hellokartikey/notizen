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

  // Tags related methods
  auto tags() -> QStringList;

  // Notebook related methods
  auto notebooks() -> QStringList;
  Q_INVOKABLE void addNotebook(const QString& name);

  // Actions
  Q_INVOKABLE void quit();

 Q_SIGNALS:
  auto sigIsDbOk() -> void;

  auto sigHashTags() -> void;
  auto sigNotebooks() -> void;

 private:
  QSqlDatabase m_db;
  bool m_ok;
};

#endif
