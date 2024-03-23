import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

import "sidebar"

Kirigami.GlobalDrawer {
  id: root

  modal: false
  interactive: false

  handleVisible: true
  handleClosedIcon.name: "sidebar-expand"
  handleOpenIcon.name: "sidebar-collapse"

  width: 192

  header: HeaderBar {}

  actions: [
    Notes {},

    Notebooks {},

    Tags {}
  ]
}

