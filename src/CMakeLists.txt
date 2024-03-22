ecm_setup_version(${PROJECT_VERSION}
  VARIABLE_PREFIX NOTIZEN
  VERSION_HEADER version.h)

add_executable(
  ${PROJECT_NAME}
  main.cc
  backend.cc backend.h
  resources.qrc)

target_link_libraries(
  ${PROJECT_NAME}
  Qt6::Core
  Qt6::Widgets
  Qt6::Qml
  Qt6::Quick
  Qt6::QuickControls2
  KF6::Kirigami2
  KPim6::AkonadiNotes)

install(TARGETS ${PROJECT_NAME} ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})

