import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  title: "Notizen"

  minimumHeight: 700
  minimumWidth: 1000

  visible: true

  header: HeaderBar {
    id: headerBar
  }

  SideBar {
    id: sideBar
  }

  HomePage {
    id: homePage

    anchors.fill: parent
    anchors.leftMargin: sideBar.drawerWidth
  }
}
