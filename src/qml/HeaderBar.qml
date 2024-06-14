import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
  id: root

  leftPadding: 0

  RowLayout {
    anchors.fill: parent

    spacing: 0

    Item {
      id: sideBarSpacer

      height: 10

      // HACK: this feels like a hack... idk
      Layout.preferredWidth: sideBar.drawerWidth - sideBarSeparator.width
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

    Item {
      Layout.fillWidth: true
    }

    ToolButton {
      text: "Debug"
      icon.name: "debug-run"

      onClicked: {
        console.log(`opened: ${sideBar.opened}`);
        console.log(`visible: ${sideBar.visible}`);
      }
    }
  }
}
