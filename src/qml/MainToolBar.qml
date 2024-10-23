import QtQuick
import QtQuick.Controls

ToolBar {
  id: root

  required property var sideBar

  Row {
    id: row

    spacing: 0

    ToolButton {
      icon.name: "debug-step-instruction"
      text: "Debug"

      visible: sideBar.opened
    }

    Item {
      height: 10
      width: sideBar.posX - x - root.leftPadding
    }

    ToolSeparator {
      id: separator
      visible: sideBar.opened
    }

    ToolButton {
      icon.name: sideBar.visible ? "sidebar-collapse-symbolic" : "sidebar-show-symbolic"
      onClicked: {
        if (sideBar.visible) {
          sideBar.close()
        } else {
          sideBar.open()
        }
      }
    }
  }
}
