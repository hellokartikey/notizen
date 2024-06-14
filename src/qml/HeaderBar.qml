import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
  id: root

  leftPadding: 0

  Row {
    anchors.fill: parent

    Item {
      id: sideBarSpacer

      height: 10
      width: sideBar.drawerWidth - sideBarSeparator.width
    }

    ToolSeparator {
      id: sideBarSeparator

      visible: sideBar.visible
    }

    ToolButton {
      icon.name: sideBar.opened ? "sidebar-collapse-left-symbolic" : "sidebar-expand-left-symbolic"

      onClicked: {
        if (sideBar.opened) {
          sideBar.close();
        } else {
          sideBar.open();
        }
      }
    }

    ToolButton {
      icon.name: "debug-run"

      onClicked: {
        console.log(`opened: ${sideBar.opened}`);
        console.log(`visible: ${sideBar.visible}`);
      }
    }
  }
}
