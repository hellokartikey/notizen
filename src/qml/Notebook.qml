import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Column {
  id: root

  required property var notebook

  ItemDelegate {
    anchors.left: parent.left
    anchors.right: parent.right

    text: notebook.name
    icon.name: inside.show ? "folder-notes-symbolic" : "arrow-right"

    onClicked: {
      inside.show = ! inside.show;
    }
  }

  Column {
    id: inside

    anchors.left: parent.left
    anchors.right: parent.right

    property bool show: false

    height: show ? implicitHeight : 0
    clip: true

    ItemDelegate {
      anchors.left: parent.left
      anchors.right: parent.right
      anchors.leftMargin: icon.width

      text: "Add note"
      icon.name: "list-add-symbolic"
    }

    Repeater {
      id: rep

      model: Backend.notesInNotebook(notebook)

      delegate: ItemDelegate {
        required property var modelData

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: icon.width

        text: modelData.name
        icon.name: "note-symbolic"
      }
    }

    Behavior on height {
      NumberAnimation {
        duration: 200
        easing.type: Easing.InOutQuad
      }
    }
  }
}
