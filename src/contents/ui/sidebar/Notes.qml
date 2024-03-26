import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

ColumnLayout {
  width: parent.width

  Kirigami.ListSectionHeader {
    Layout.fillWidth: true
    label: "Notes"
  }

  Controls.ItemDelegate {
    Layout.fillWidth: true
    text: "All Notes"
    icon.name: "note"
  }

  Controls.ItemDelegate {
    Layout.fillWidth: true
    text: "Archive"
    icon.name: "archive-extract"
  }

  Controls.ItemDelegate {
    Layout.fillWidth: true
    text: "Deleted"
    icon.name: "trash-empty"
  }
}
