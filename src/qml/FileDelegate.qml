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
  required property string filePath

  property int indentation: indentationUnit * depth

  implicitHeight: elementHeight
  implicitWidth: treeView.parent.width

  // The vertical line for indented elements
  Row {
    Repeater {
      model: root.depth
      delegate: Item {
        id: delegateItem

        width: root.indentationUnit
        height: root.elementHeight

        Rectangle {
          anchors.left: delegateItem.left
          anchors.top: delegateItem.top
          anchors.bottom: delegateItem.bottom
          anchors.leftMargin: root.indentationUnit / 2
          width: 1
          color: palette.active.mid
        }
      }
    }
  }

  ItemDelegate {
    anchors.fill: root
    anchors.leftMargin: indentation

    text: root.fileName
    icon.name: root.hasChildren ? "folder-notes-symbolic" : "text-plain"

    onClicked: {
      if (root.hasChildren) {
        root.treeView.toggleExpanded(row)
      } else {
        Backend.openNote(root.filePath)
      }
    }
  }
}
