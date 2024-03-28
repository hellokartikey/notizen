import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Kirigami.ApplicationWindow {
  id: root

  title: "Notizen"

  minimumWidth: Kirigami.Units.gridUnit * 30
  minimumHeight: Kirigami.Units.gridUnit * 20

  width: Kirigami.Units.gridUnit * 50

  pageStack.initialPage: Notes {}

  globalDrawer: SideBar {}
}
