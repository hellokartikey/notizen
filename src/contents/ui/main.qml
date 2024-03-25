import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Kirigami.ApplicationWindow {
  id: root

  title: "Notizen"

  pageStack.initialPage: Notes {}

  globalDrawer: SideBar {}
}
