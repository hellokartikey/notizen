import QtQuick
import QtQuick.Controls

import Notizen

ApplicationWindow {
  id: root

  width: 700
  height: 500

  visible: true

  header: MainToolBar { sideBar: sideBar }

  SideBar {
    id: sideBar

    parentItem: root

    TreeView {
      id: treeView

      anchors.fill: parent
      model: Backend.tree

      rootIndex: model.rootIndex

      delegate: FileDelegate {}
    }
  }

  DefaultPage {
    id: defaultPage

    sideBar: sideBar

    anchors.fill: parent
  }
}
