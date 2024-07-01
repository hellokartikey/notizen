import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Column {
  id: root

  required property string text
  required property var notebook
  property bool showAdd: true
  default property string iconName: "folder-notes-symbolic"

  ItemDelegate {
    anchors.left: parent.left
    anchors.right: parent.right

    text: root.text
    icon.name: iconName

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
      visible: root.showAdd
    }

    Repeater {
      id: rep

      model: notebook

      delegate: ItemDelegate {
        required property var modelData

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: icon.width

        text: modelData.name
        icon.name: "note-symbolic"

        onClicked: { openNote(modelData.name) }
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
