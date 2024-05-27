import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

ListView {
  id: root

  model: Backend.notebooks

  interactive: false

  property var delegateHeight: undefined
  property var headerHeight: undefined

  width: parent.width
  height: headerHeight + (count * delegateHeight)

  Component.onCompleted: {
    delegateHeight = currentItem.height;
    headerHeight = headerItem.height;
  }

  header: ColumnLayout {
    width: ListView.view.width

    spacing: 0

    Kirigami.PromptDialog {
      id: newNotebookDialog

      title: "New Notebook"

      standardButtons: Kirigami.Dialog.Ok | Kirigami.Dialog.Cancel

      Controls.TextField {
        id: newNotebookTextField

        placeholderText: "Notebook name..."
      }

      onAccepted: {
        Backend.addNotebook(newNotebookTextField.text);
        newNotebookTextField.clear();
      }
    }

    Kirigami.ListSectionHeader {
      Layout.fillWidth: true
      label: "Notebooks"
    }

    Controls.ItemDelegate {
      id: tmp
      Layout.fillWidth: true
      text: "Add Notebook"
      icon.name: "bookmark-add-folder"
      onClicked: {
        newNotebookDialog.open();
      }
    }
  }

  delegate: Controls.ItemDelegate {
    id: delegateItem
    text: modelData.name
    icon.name: "bookmarks"
    width: ListView.view.width

    highlighted: Backend.currentNotebook == modelData

    onClicked: {
      Backend.currentNotebook = modelData;
    }
  }
}
