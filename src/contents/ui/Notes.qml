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

  Kirigami.CardsLayout {
    maximumColumns: 10

    minimumColumnWidth: Kirigami.Units.gridUnit * 12
    maximumColumnWidth: Kirigami.Units.gridUnit * 12

    columnSpacing: Kirigami.Units.mediumSpacing
    rowSpacing: Kirigami.Units.mediumSpacing

    Repeater {
      model: 5
      delegate: Note {}
    }

  }
}
