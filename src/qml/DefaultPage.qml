import QtQuick
import QtQuick.Controls

import Notizen

Page {
  id: page

  required property var sideBar

  anchors.leftMargin: sideBar.posX

  background: Rectangle {
    color: palette.light
  }

  Text {
    anchors.centerIn: parent
    text: Backend.hello()
  }
}
