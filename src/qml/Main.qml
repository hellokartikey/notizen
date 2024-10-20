import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  width: 700
  height: 500

  visible: true

  Page {
    id: page
    anchors.fill: parent

    header: ToolBar {}

    TreeView {
      id: treeView

      anchors.fill: parent
      model: Backend.tree

      rootIndex: model.rootIndex

      delegate: Item {
        implicitHeight: 30
        implicitWidth: page.width

        required property int hasChildren

        ItemDelegate {
          anchors.fill: parent
          anchors.leftMargin: treeView.depth(row) * 20

          text: model.fileName
          icon.name: hasChildren ? "folder-symbolic" : "text-plain"

          onClicked: { treeView.toggleExpanded(row) }
        }
      }
    }
  }
}
