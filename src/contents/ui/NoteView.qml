import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Kirigami.Page {
  property var note: Backend.currentNote

  title: note.title

  padding: 0

  Rectangle {
    color: Kirigami.Theme.alternateBackgoundColor
    anchors.fill: parent

    TextEdit {
      anchors.fill: parent
      anchors.margins: Kirigami.Units.gridUnit

      text: note.content
      textFormat: Text.MarkdownText
      selectionColor: Kirigami.Theme.highlightColor

      readOnly: true

      wrapMode: Text.WordWrap
    }
  }
}
