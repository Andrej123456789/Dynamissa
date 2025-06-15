cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Debug)

project(dynamissa)

file(GLOB SRC CONFIGURE_DEPENDS "include/*.hpp" "src/*.cpp")

find_package(SDL2 REQUIRED CONFIG)

IF(WIN32)
    set(SDL2_DLL_PATH "${CMAKE_PREFIX_PATH}/lib/x64/SDL2.dll")
ENDIF()

add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

IF(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_DLL_PATH}"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
ENDIF()
