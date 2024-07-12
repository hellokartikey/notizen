add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
PRIVATE
  main.cc
  fwd.h
  backend.cc
  backend.h
  note.cc
  note.h
  notebook.cc
  notebook.h
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
  fmt::fmt
  Qt6::Core
  Qt6::Widgets
  Qt6::Qml
  Qt6::Quick
  Qt6::QuickControls2
  Qt6::Sql
)

add_subdirectory(qml)

install(TARGETS ${PROJECT_NAME} ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
