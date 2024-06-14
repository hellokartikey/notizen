import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  title: "Notizen"

  minimumHeight: 500
  minimumWidth: 500

  height: 700
  width: 1000

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
