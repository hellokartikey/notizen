import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  function openNote(name) {
    Backend.currentNote = Backend.note(name)
    stack.replaceCurrentItem(noteView)
  }

  function closeNote() {
    stack.replaceCurrentItem(homeView)
    Backend.currentNote = null
  }

  title: "Notizen"

  minimumHeight: 500
  minimumWidth: 500

  height: 700
  width: 1000

  visible: true

  header: HeaderBar {
    id: headerBar
  }

  SideBar {
    id: sideBar

    ScrollView {
      id: scroll

      anchors.fill: parent

      Column {
        id: sideBarColumn

        anchors.top: parent.top

        width: scroll.width - scroll.effectiveScrollBarWidth

        Notebook {
          anchors.left: parent.left
          anchors.right: parent.right

          text: "All Notes"
          iconName: "note-symbolic"
          notebook: Backend.notes
        }

        Notebook {
          anchors.left: parent.left
          anchors.right: parent.right

          text: "Archived"
          iconName: "folder-symbolic"
          notebook: undefined
          showAdd: false
        }

        Notebook {
          anchors.left: parent.left
          anchors.right: parent.right

          text: "Deleted"
          iconName: "delete-symbolic"
          notebook: undefined
          showAdd: false
        }

        MenuSeparator {}

        ItemDelegate {
          anchors.left: parent.left
          anchors.right: parent.right

          text: "Add Notebook"
          icon.name: "list-add-symbolic"
        }

        Repeater {
          model: Backend.notebooks

          delegate: Notebook {
            required property var modelData

            anchors.left: parent.left
            anchors.right: parent.right

            notebook: Backend.notesInNotebook(modelData)
            text: modelData.name
          }
        }
      }
    }
  }

  StackView {
    id: stack
    initialItem: homeView

    anchors.fill: parent
    anchors.leftMargin: sideBar.drawerWidth
  }

  Component {
    id: homeView

    HomePage {
      id: homePage
    }
  }

  Component {
    id: noteView

    NoteView {
      id: notePage
    }
  }
}
