#include "filemodel.hpp"

FileModel::FileModel(QObject* parent)
    : QFileSystemModel(parent)
    , m_index(QFileSystemModel::setRootPath(QDir::currentPath())) {}

int FileModel::columnCount(const QModelIndex& parent) const {
  std::ignore = parent;
  return 1;
}

QModelIndex FileModel::rootIndex() const {
  return m_index;
}

#include "moc_filemodel.cpp"
