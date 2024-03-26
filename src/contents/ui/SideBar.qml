import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

import "sidebar"

Kirigami.GlobalDrawer {
  id: root

  modal: Kirigami.Settings.isMobile
  interactive: Kirigami.Settings.isMobile

  handleVisible: true
  handleClosedIcon.name: "sidebar-expand"
  handleOpenIcon.name: "sidebar-collapse"

  width: Kirigami.Units.gridUnit * 10

  header: HeaderBar {}
  footer: FooterBar {}

  Column {
    Layout.fillWidth: true

    Notes {}
    Notebooks {}
    Tags {}
  }
}
