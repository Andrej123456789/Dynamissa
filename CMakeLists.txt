cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Debug)

project(dynamissa)

file(GLOB SRC CONFIGURE_DEPENDS "include/*.hpp" "src/*.cpp")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_LIBRARIES})

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
