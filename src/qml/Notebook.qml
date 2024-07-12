import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Column {
  id: root

  required property string text

  property var notes
  property var notebooks

  default property string iconName: "folder-notes-symbolic"
  
  property bool show: false

  ItemDelegate {
    id: notebookButton

    anchors.left: parent.left
    anchors.right: parent.right

    text: root.text
    icon.name: iconName

    onClicked: {
      show = ! show;
    }

    Text {
      anchors.verticalCenter: parent.verticalCenter
      anchors.right: parent.right
      anchors.rightMargin: 12

      horizontalAlignment: Text.AlignRight

      text: notebooks ? notebooks.size : 0
    }
  }

  Column {
    id: inside

    anchors.left: parent.left
    anchors.right: parent.right

    height: show ? implicitHeight : 0
    clip: true

    Repeater {
      id: notesRepeater

      model: notes

      delegate: ItemDelegate {
        required property var modelData

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: icon.width

        text: modelData.name
        icon.name: "note-symbolic"

        onClicked: { openNote(modelData.name) }

        Rectangle {
          id: verLine

          anchors.right: parent.left
          anchors.rightMargin: parent.icon.width / 3

          height: parent.height
          width: 1

          color: palette.mid
        }
      }
    }

    Behavior on height {
      NumberAnimation {
        easing.type: Easing.OutQuad
      }
    }
  }
}
