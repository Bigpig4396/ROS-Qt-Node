##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.0)
project(qtros)

find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)
find_package(Qt5Widgets REQUIRED)

include_directories(
        include
        ${catkin_INCLUDE_DIRS})

set(CPP_SOURCES src/main.cpp src/main_window.cpp src/qnode.cpp)
set(CPP_HEADERS include/main_window.hpp include/qnode.hpp)
# set(QRC_RESOURCES resources/images.qrc)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES head_gesture
  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})

# qt5_wrap_ui(UIS_HEADERS ui/main_window.ui)

qt5_wrap_cpp(MOC_SOURCES ${CPP_SOURCES} ${CPP_HEADERS})

qt5_add_resources(RESOURCES_RCC ${RESOURCE})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++11")



add_executable(qtros ${CPP_SOURCES} ${UIS_HEADERS} ${MOC_SOURCES} ${QRC_RESOURCES} ${RESOURCES_RCC})
target_link_libraries(qtros ${Qt5Widgets_LIBRARIES} ${catkin_LIBRARIES})

qt5_use_modules(qtros Widgets)
