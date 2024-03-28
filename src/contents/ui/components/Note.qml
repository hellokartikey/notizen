import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

Kirigami.Card {
  Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

  Layout.minimumWidth: Kirigami.Units.gridUnit * 12
  Layout.minimumHeight: Math.min(Kirigami.Units.gridUnit * 15, implicitHeight)

  Layout.maximumWidth: Layout.minimumWidth
  Layout.maximumHeight: Layout.minimumHeight

  showClickFeedback: true

  header: ColumnLayout {
    Kirigami.Heading {
      Layout.fillWidth: true

      text: "Title is this very long string that should wrap around"
      font.weight: Font.Bold
      font.bold: true
      maximumLineCount: 2

      wrapMode: Text.Wrap
      elide: Text.ElideRight
    }

    Kirigami.Chip {
      closable: false
      checkable: false
      text: "tag"
    }

    Kirigami.Separator { Layout.fillWidth: true }
  }

  contentItem: Text {
    Layout.fillWidth: true

    text: "Lorem Ipsum is simply dummy text of the printing and typesetting industry. This it again too long of a note"

    wrapMode: Text.Wrap
    elide: Text.ElideRight
  }

  actions: [
    Kirigami.Action {
      icon.name: "pin"
    },

    Kirigami.Action {
      icon.name: "archive-insert"
    },

    Kirigami.Action {
      icon.name: "view-hidden"
    },

    Kirigami.Action {
      icon.name: "edit-duplicate"
    },

    Kirigami.Action {
      icon.name: "delete"
    }
  ]
}
