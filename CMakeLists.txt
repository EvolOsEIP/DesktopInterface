cmake_minimum_required(VERSION 3.22)
project(desktop_interface)

set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SOURCES "./src/*.cpp")

# Find GTK
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
include_directories(include)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})
