import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Kirigami.Card {
  Layout.minimumWidth: Kirigami.Units.gridUnit * 12
  Layout.minimumHeight: Math.min(Kirigami.Units.gridUnit * 15, implicitHeight)

  showClickFeedback: true

  header: ColumnLayout {
    Kirigami.Heading {
      Layout.fillWidth: true

      text: modelData.name
      font.weight: Font.Bold
      font.bold: true

      maximumLineCount: 10

      wrapMode: Text.Wrap
      elide: Text.ElideRight
    }

    Kirigami.Separator {
      Layout.fillWidth: true
    }
  }

  contentItem: Text {
    Layout.fillWidth: true

    text: modelData.content
    textFormat: Text.MarkdownText

    wrapMode: Text.WordWrap
    elide: Text.ElideRight
  }

  onClicked: {
    Backend.currentNote = modelData;
    openNoteView();
  }

  actions: [
    Kirigami.Action {
      icon.name: "pin"
      text: "Pin"
      checkable: true
    },
    Kirigami.Action {
      icon.name: "color-management"
      text: "Color"
    },
    Kirigami.Action {
      icon.name: "archive-insert"
      text: "Archive"
      checkable: true
    },
    Kirigami.Action {
      icon.name: "view-hidden"
      text: "Hide"
      checkable: true
    },
    Kirigami.Action {
      icon.name: "delete"
      text: "Delete"
    }
  ]
}
