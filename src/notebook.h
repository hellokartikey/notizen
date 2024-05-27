#ifndef NOTIZEN_NOTEBOOK_H
#define NOTIZEN_NOTEBOOK_H

#include <QList>
#include <QObject>

class Notebook : public QObject {
  Q_OBJECT;

  Q_PROPERTY(int id READ id WRITE setId NOTIFY sigId);
  Q_PROPERTY(QString name READ name WRITE setName NOTIFY sigName);

 public:
  explicit Notebook(QObject* parent = nullptr);

  auto id() const -> int;
  auto setId(int id) -> void;

  auto name() const -> QString;
  auto setName(const QString& name) -> void;

 Q_SIGNALS:
  auto sigId() -> void;
  auto sigName() -> void;

 private:
  int m_id;
  QString m_name;
};

using NotebookList = QList<Notebook*>;

#endif
