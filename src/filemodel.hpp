#ifndef HK_NOTIZEN_FILEMODEL_HPP
#define HK_NOTIZEN_FILEMODEL_HPP

#include <QDir>
#include <QFileSystemModel>
#include <QObject>
#include <QVariant>

class FileModel : public QFileSystemModel {
  Q_OBJECT;

  Q_PROPERTY(QModelIndex rootIndex READ rootIndex CONSTANT);

 public:
  FileModel(QObject* parent = nullptr);

  int columnCount(const QModelIndex& parent = QModelIndex{}) const override;

  QModelIndex rootIndex() const;

 private:
  QModelIndex m_index;
};

#endif
