import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

import "sidebar"
import "components"

Kirigami.ScrollablePage {
  id: root

  title: "Notes"

  actions: [
    Kirigami.Action {
      text: "New Note"
      icon.name: "list-add-symbolic"
    }
  ]

  Kirigami.CardsLayout {
    minimumColumnWidth: Kirigami.Units.gridUnit * 12

    maximumColumns: 3

    columnSpacing: Kirigami.Units.mediumSpacing
    rowSpacing: Kirigami.Units.mediumSpacing

    Repeater {
      model: Backend.notes
      delegate: NoteCard {}
    }
  }
}
