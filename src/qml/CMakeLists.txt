ecm_add_qml_module(${PROJECT_NAME} URI Notizen)

ecm_target_qml_sources(${PROJECT_NAME}
  SOURCES
    Main.qml
    SideBar.qml
    NoteCard.qml
    HomePage.qml
    HeaderBar.qml
    TabBar.qml
    Notebook.qml
    NoteView.qml)
