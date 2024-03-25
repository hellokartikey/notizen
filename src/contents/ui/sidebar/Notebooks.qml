import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

Kirigami.Action {
  text: "Notebooks"
  expandible: true

  children: [
    Kirigami.Action {
      text: "Add Notebook"
      icon.name: "bookmark-add-folder"
    },

    Kirigami.Action {
      text: "Other"
      icon.name: "bookmarks"
    }
  ]
}
