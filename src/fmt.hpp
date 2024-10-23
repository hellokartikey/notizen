#ifndef HK_NOTIZEN_FMT_HPP
#define HK_NOTIZEN_FMT_HPP

#include <fmt/format.h>

#include <QString>

auto format_as(const QString& string) {
  return qPrintable(string);
}

#endif
