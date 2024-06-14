import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
  id: root

  header: ToolBar {
    id: tabBar

    RowLayout {
      anchors.fill: parent

      Repeater {
        model: [ "Note 1", "Markdown", "Notizen", "Obsidian" ]

        delegate: Button {
          Layout.fillWidth: true
          text: modelData
          checkable: true
          autoExclusive: true

          Button {
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.margins: 4

            icon.name: "tab-close"
            height: width
            flat: true
          }
        }
      }
    }
  }

  Text {
    text: "Hello, World"
  }
}
