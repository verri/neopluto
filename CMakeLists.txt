cmake_minimum_required(VERSION 3.0)
project(NeoPluto VERSION 0.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/libneopluto)

set(CMAKE_AUTOMOC ON)

add_executable(npl main.cpp mainwindow.cpp)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

target_link_libraries(npl PRIVATE neopluto Qt5::Widgets Qt5::Core)
target_include_directories(npl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
