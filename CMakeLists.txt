cmake_minimum_required(VERSION 3.10)
project(SecretBundestagServer)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -mtune=native -march=native")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif ()


set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/comm/MessageHandler.cpp
        ${CMAKE_SOURCE_DIR}/src/util/Logging.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/Error.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/CardType.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/Fraction.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/Office.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/Role.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamecontroller/Controller.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamecontroller/Controller.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamecontroller/Controller.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamecontroller/Controller.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Board.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Board.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/CardRange.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/CardRange.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Environment.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Environment.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Player.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Player.hpp)

set(LIBS stdc++fs pthread WebsocketCpp)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE lib)
target_include_directories(${PROJECT_NAME} PRIVATE lib/json/single_include)

add_subdirectory(test)
add_subdirectory(lib/WebsocketCPP)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)
