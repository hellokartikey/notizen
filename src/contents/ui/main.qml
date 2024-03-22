import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

Kirigami.ApplicationWindow {
  id: root

  title: "Notizen"

  pageStack.initialPage: Notes {}

  globalDrawer: SideBar {}
}

