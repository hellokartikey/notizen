cmake_minimum_required(VERSION 3.28.0)

project(notizen VERSION 0.1.0)

set(KF_MIN_VERSION "6.0.0")
set(QT_MIN_VERSION "6.7.0")

find_package(ECM ${KF_MIN_VERSION} REQUIRED NO_MODULE)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${ECM_MODULE_PATH}
  ${PROJECT_SOURCE_DIR}/cmake
)

include(FeatureSummary)
include(ECMQmlModule)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

find_package(fmt REQUIRED)

find_package(Qt6 ${QT_MIN_VERSION} REQUIRED NO_MODULE
COMPONENTS
  Core
  Quick
  QuickControls2
  Widgets
  Sql
)

qt6_standard_project_setup()

add_subdirectory(src)

feature_summary(
  WHAT
  ALL
  INCLUDE_QUIET_PACKAGES
  FATAL_ON_MISSING_REQUIRED_PACKAGES
)
