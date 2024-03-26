import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Controls.ToolBar {
  position: Controls.ToolBar.Footer

  visible: Kirigami.Settings.isMobile

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
