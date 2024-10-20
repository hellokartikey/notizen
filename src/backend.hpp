#ifndef HK_NOTIZEN_BACKEND_HPP
#define HK_NOTIZEN_BACKEND_HPP

#include <QObject>
#include <QString>

class Backend : public QObject {
  Q_OBJECT;

 private:
  Backend(QObject* parent = nullptr);

 public:
  static Backend* get();

  Q_INVOKABLE QString hello() const;

 private:
  int m_id = 0;
};

#endif
