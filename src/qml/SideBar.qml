import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Drawer {
  id: root

  property real drawerWidth: width * position

  readonly property real defaultWidth: 300
  readonly property real minimumWidth: 200
  readonly property real maximumWidth: 400
  readonly property real dragThreshold: 10

  interactive: false
  modal: false
  visible: true

  closePolicy: Popup.NoAutoClose

  height: parent.height
  width: dragAreaRect.x + (dragAreaRect.width / 2)

  Item {
    id: dragAreaRect

    width: dragThreshold
    height: parent.height

    x: defaultWidth

    MouseArea {
      id: dragMouseArea

      anchors.fill: parent

      cursorShape: Qt.SizeHorCursor

      drag.target: dragAreaRect
      drag.axis: Drag.XAxis
      drag.minimumX: minimumWidth
      drag.maximumX: maximumWidth
    }
  }
}
