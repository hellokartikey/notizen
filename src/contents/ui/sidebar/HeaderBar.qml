import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Controls.ToolBar {
  height: pageStack.globalToolBar.preferredHeight

  RowLayout {
    anchors.fill: parent

    Kirigami.Heading {
      Layout.leftMargin: Kirigami.Units.largeSpacing
      text: "Notizen"
    }

    Kirigami.ActionToolBar {
      overflowIconName: "menu_new"

      actions: [
        Kirigami.Action {
          text: "Settings"
          icon.name: "settings-configure"
        },

        Kirigami.Action {
          text: "About"
          icon.name: "help-about"
        },

        Kirigami.Action { separator: true },

        Kirigami.Action {
          text: "Quit"
          icon.name: "application-exit"
          shortcut: StandardKey.Quit
          onTriggered: { Actions.quit() }
        }
      ]
    }
  }
}
