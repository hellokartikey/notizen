import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as Controls
import org.kde.kirigami as Kirigami

Kirigami.Action {
  id: tagList

  text: "Tags"
  expandible: true

  visible: backend.hashTags.length

  Component.onCompleted: {
    var tagComponent = Qt.createComponent("Tag.qml")
    for ( const tag of backend.hashTags ) {
      var tagAction = tagComponent.createObject(tagList, {text: tag})
      children.push(tagAction)
    }
  }
}

