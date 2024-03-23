import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import "sidebar"

Kirigami.GlobalDrawer {
  id: root

  modal: false
  interactive: false

  handleVisible: true
  handleClosedIcon.name: "sidebar-expand"
  handleOpenIcon.name: "sidebar-collapse"

  width: 200

  header: Controls.ToolBar {
    height: pageStack.globalToolBar.preferredHeight

    RowLayout {
      anchors.fill: parent

      Kirigami.Heading {
        Layout.leftMargin: Kirigami.Units.largeSpacing
        text: "Notizen"
      }
    }
  }

  actions: [
    Notes {},

    Notebooks {},

    Tags {}
  ]

  footer: Controls.ToolBar {
    position: Controls.ToolBar.Footer
    ColumnLayout {
      anchors.fill: parent

      Controls.ItemDelegate {
        Layout.fillWidth: true
        text: "Settings"
        icon.name: "settings-configure"
      }

      Controls.ItemDelegate {
        Layout.fillWidth: true
        text: "About"
        icon.name: "help-about"
      }
    }
  }
}

