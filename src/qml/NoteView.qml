import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
  id: root

  property var note: Backend.currentNote

  background: Rectangle {
    color: palette.light
  }

  Text {
    anchors.fill: parent

    text: note.content
  }
}
