import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  width: 700
  height: 500

  visible: true

  Text {
    anchors.centerIn: parent
    text: Backend.hello()
  }
}
