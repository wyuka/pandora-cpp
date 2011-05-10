project(pandora)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(pandora_SRCS pandora.cpp main.cpp)
qt4_automoc(${pandora_SRCS})
add_executable(pandora ${pandora_SRCS})
target_link_libraries(pandora ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
