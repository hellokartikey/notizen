import QtQuick
import QtQuick.Controls

Item {
  id: root

  readonly property int elementHeight: 30
  readonly property int indentationUnit: 25

  required property TreeView treeView
  required property bool isTreeNode
  required property bool expanded
  required property int hasChildren
  required property int depth

  required property string fileName

  property int indentation: indentationUnit * depth

  implicitHeight: elementHeight
  implicitWidth: treeView.parent.width

  // The vertical line for indented elements
  Row {
    Repeater {
      model: root.depth
      delegate: Item {
        width: root.indentationUnit
        height: root.elementHeight

        Rectangle {
          anchors.left: parent.left
          anchors.top: parent.top
          anchors.bottom: parent.bottom
          anchors.leftMargin: root.indentationUnit / 2
          width: 1
          color: palette.active.mid
        }
      }
    }
  }

  ItemDelegate {
    anchors.fill: parent
    anchors.leftMargin: indentation

    text: fileName
    icon.name: hasChildren ? "folder-notes-symbolic" : "text-plain"

    onClicked: { treeView.toggleExpanded(row) }
  }
}
