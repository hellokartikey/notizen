import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

Kirigami.GlobalDrawer {
  id: root

  collapsible: false

  modal: false
  interactive: false

  width: 150

  header: Controls.ToolBar {
    height: pageStack.globalToolBar.preferredHeight

    RowLayout {
      anchors.fill: parent

      Kirigami.Heading { text: "Notizen" }
    }
  }

  actions: [
    Kirigami.Action {
      text: "Notes"
      expandible: true

      Kirigami.Action {
        text: "All Notes"
        icon.name: "note"
      }

      Kirigami.Action {
        text: "Archive"
        icon.name: "archive-insert"
      }

      Kirigami.Action {
        text: "Deleted"
        icon.name: "trash-empty"
      }

    },

    Kirigami.Action {
      text: "Notebooks"
      expandible: true

      Kirigami.Action {
        text: "Add Notebook"
        icon.name: "bookmark-add-folder"
      }

      Kirigami.Action {
        text: "Other"
        icon.name: "bookmarks"
      }
    },

    Kirigami.Action {
      separator: true
      enabled: false
    },

    Kirigami.Action {
      text: "Tags"
      icon.name: "tag"
    },

    Kirigami.Action {
      separator: true
      enabled: false
    }
  ]

  footer: Controls.ToolBar {
    position: Controls.ToolBar.Footer
    ColumnLayout {
      anchors.fill: parent

      Controls.ItemDelegate {
        Layout.fillWidth: true
        text: "Settings"
        icon.name: "settings-configure"
      }

      Controls.ItemDelegate {
        Layout.fillWidth: true
        text: "About"
        icon.name: "help-about"
      }
    }
  }
}

