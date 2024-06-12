import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  title: "Notizen"

  height: 500
  width: 500

  visible: true

  Drawer {
    id: sideBar

    readonly property real drawerWidth: width * position

    width: 200
    height: root.height

    interactive: false
    modal: false
    visible: true

    closePolicy: Popup.NoAutoClose

    Page {
      anchors.fill: parent

      header: ToolBar {}

      background: Rectangle {
        color: palette.base
      }
    }
  }

  Page {
    anchors.fill: parent
    anchors.leftMargin: sideBar.drawerWidth

    header: ToolBar {}

    Text { text: "Hello, World" }
  }
}
