import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

ListView {
  id: root

  model: Backend.tags

  visible: Backend.tags.length

  interactive: false

  property var delegateHeight: undefined
  property var headerHeight: undefined

  width: parent.width
  height: headerHeight + (count * delegateHeight)

  Component.onCompleted: {
    delegateHeight = currentItem.height
    headerHeight = headerItem.height
  }

  header: Kirigami.ListSectionHeader {
    Layout.fillWidth: true
    width: ListView.view.width
    label: "Tags"
  }

  delegate: Controls.ItemDelegate {
    text: modelData
    icon.name: "tag"
    width: ListView.view.width
  }
}
