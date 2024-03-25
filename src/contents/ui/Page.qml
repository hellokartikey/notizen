import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

import Notizen

Kirigami.Page {
  id: root

  Kirigami.InlineMessage {
    anchors { left: parent.left; right: parent.right }

    text: "Error reading database file."

    type: Kirigami.MessageType.Error

    visible: ! Backend.isDbOk
  }
}
