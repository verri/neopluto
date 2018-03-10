cmake_minimum_required(VERSION 3.0)
project(NeoPluto VERSION 0.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/libneopluto)

set(CMAKE_AUTOMOC ON)

add_executable(npl main.cpp mainwindow.cpp mainwindow.h balancewidget.cpp balancewidget.h
    accountswidget.cpp accountswidget.h
    tagswidget.cpp tagswidget.h)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

target_compile_features(npl PRIVATE cxx_std_17)

target_link_libraries(npl PRIVATE neopluto Qt5::Widgets Qt5::Core)
target_include_directories(npl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(npl PRIVATE "$<$<CONFIG:DEBUG>:-O0>")
set_target_properties(npl PROPERTIES LINK_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address,leak,undefined -fuse-ld=gold")
