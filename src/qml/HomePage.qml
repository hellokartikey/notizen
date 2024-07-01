import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
  id: root

  background: Rectangle {
    color: palette.light
  }

  Label {
    anchors.centerIn: parent

    text: "No note is open."
  }
}
