#ifndef HK_NOTIZEN_BACKEND_HPP
#define HK_NOTIZEN_BACKEND_HPP

#include <QFileSystemModel>
#include <QObject>
#include <QString>

#include "filemodel.hpp"

class Backend : public QObject {
  Q_OBJECT;

  Q_PROPERTY(FileModel* tree READ getTree CONSTANT);

 private:
  Backend(QObject* parent = nullptr);

  FileModel& tree();
  const FileModel& tree() const;

 public:
  static Backend* get();

  Q_INVOKABLE QString hello() const;

  FileModel* getTree();

 private:
  FileModel m_fs_tree;
};

#endif
