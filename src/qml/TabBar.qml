import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ToolBar {
  id: tabBar

  background: Rectangle {
    color: palette.window

    Rectangle {
      anchors.verticalCenter: parent.bottom
      color: palette.mid
      height: 1
      width: parent.width
    }
  }

  RowLayout {
    anchors.fill: parent

    spacing: 0

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

    Button {
      id: newNote

      icon.name: "document-new-symbolic"
    }
  }
}
