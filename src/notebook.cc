#include "notebook.h"

Notebook::Notebook(QObject* parent) : QObject(parent) {}

auto Notebook::id() const -> int { return m_id; }

auto Notebook::setId(int id) -> void {
  if (id == m_id) return;
  m_id = id;
  Q_EMIT sigId();
}

auto Notebook::name() const -> QString { return m_name; }

auto Notebook::setName(const QString& name) -> void {
  if (name == m_name) return;
  m_name = name;
  Q_EMIT sigName();
}
