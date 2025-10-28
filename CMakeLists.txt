cmake_minimum_required(VERSION 3.30)
project(courier CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base xrc)
include(${wxWidgets_USE_FILE})

# wxWidgets xrc
set(XRC_FILE "${CMAKE_SOURCE_DIR}/res/ui.xrc")
set(XRS_OUT "${CMAKE_BINARY_DIR}/ui.cpp")
find_program(WXRC_EXECUTABLE NAMES wxrc wxrc-3.2 wxrc-3.1 REQUIRED)
add_custom_command(
  OUTPUT ${XRS_OUT}
  COMMAND ${WXRC_EXECUTABLE} -c -o ${XRS_OUT} ${XRC_FILE}
  DEPENDS ${XRC_FILE}
  COMMENT "Compiling XRC resources"
)

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SRC_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_FILES} ${XRS_OUT})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
