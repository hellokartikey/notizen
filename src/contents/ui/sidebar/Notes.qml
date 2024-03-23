import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

Kirigami.Action {
  text: "Notes"
  expandible: true

  children: [
    Kirigami.Action {
      text: "All Notes"
      icon.name: "note"
    },

    Kirigami.Action {
      text: "Archive"
      icon.name: "archive-insert"
    },

    Kirigami.Action {
      text: "Deleted"
      icon.name: "trash-empty"
    }
  ]
}

