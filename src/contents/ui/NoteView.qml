import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Kirigami.Page {
  property var note: Backend.currentNote

  title: note.name

  padding: 0

  actions: [
    Kirigami.Action {
      text: "Edit"

      onTriggered: {
        if (editor.readOnly) {
          editor.textFormat = Text.PlainText;
        } else {
          editor.textFormat = Text.MarkdownText;
        }
        editor.readOnly = !editor.readOnly;
      }
    }
  ]

  Rectangle {
    id: background

    color: Kirigami.Theme.View.backgroundColor

    anchors.fill: parent

    TextEdit {
      id: editor

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
