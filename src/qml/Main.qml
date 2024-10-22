import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  width: 700
  height: 500

  visible: true

  SideBar {
    id: sideBar

    parentItem: root

    Page {
      anchors.fill: parent

      header: ToolBar {
        ToolButton {
          icon.name: "debug-step-instruction"
          text: "Debug"
        }
      }

      TreeView {
        id: treeView

        anchors.fill: parent
        model: Backend.tree

        rootIndex: model.rootIndex

        delegate: FileDelegate {}
      }
    }
  }

  Page {
    id: page

    anchors.fill: parent
    anchors.leftMargin: sideBar.posX

    header: ToolBar {
      Row {
        anchors.fill: parent
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

    background: Rectangle {
      color: palette.light
    }

    Text {
      anchors.centerIn: parent
      text: Backend.hello()
    }
  }
}
