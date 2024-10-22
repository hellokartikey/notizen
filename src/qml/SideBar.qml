import QtQuick
import QtQuick.Controls

Drawer {
  id: root

  required property var parentItem

  readonly property int defaultWidth: 200
  readonly property int minimumWidth: 100
  readonly property int maximumWidth: parentItem.width - minimumWidth
  readonly property int dragWidth: 20

  readonly property real posX: width * position

  modal: false
  interactive: false
  visible: true

  height: parentItem.height
  width: dragRect.x + (dragWidth / 2)

  Item {
    id: dragRect

    height: parent.height
    width: root.dragWidth

    x: root.defaultWidth

    MouseArea {
      anchors.fill: parent

      hoverEnabled: true
      cursorShape: pressed ? Qt.DragMoveCursor : Qt.SplitHCursor

      drag.target: dragRect
      drag.axis: Drag.XAxis
      drag.minimumX: root.minimumWidth
      drag.maximumX: root.maximumWidth
      drag.threshold: 0
    }
  }
}
