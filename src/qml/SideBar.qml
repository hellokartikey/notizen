import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Drawer {
  id: root

  property real drawerWidth: width * position

  readonly property real defaultWidth: 200
  readonly property real minimumWidth: 100
  readonly property real maximumWidth: 400
  readonly property real dragThreshold: 20

  interactive: false
  modal: false
  visible: true

  closePolicy: Popup.NoAutoClose

  height: parent.height
  width: dragAreaRect.x + (dragAreaRect.width / 2)

  Column {
    anchors.fill: parent

    ItemDelegate {
      anchors.left: parent.left
      anchors.right: parent.right

      text: "Add Notebook"
      icon.name: "list-add-symbolic"
    }

    Repeater {
      model: Backend.notebooks
      delegate: Notebook {
        required property var modelData

        anchors.left: parent.left
        anchors.right: parent.right

        notebook: modelData
      }
    }
  }

  Item {
    id: dragAreaRect

    width: dragThreshold
    height: parent.height

    x: defaultWidth

    Rectangle {
      id: dragHighlight

      anchors.centerIn: parent

      height: parent.height
      width: 1

      color: palette.highlight

      visible: dragMouseArea.containsMouse
    }

    MouseArea {
      id: dragMouseArea

      anchors.fill: parent

      hoverEnabled: true
      cursorShape: pressed ? Qt.DragMoveCursor : Qt.SplitHCursor

      drag.target: dragAreaRect
      drag.axis: Drag.XAxis
      drag.minimumX: minimumWidth
      drag.maximumX: maximumWidth
      drag.threshold: 0
    }
  }
}
