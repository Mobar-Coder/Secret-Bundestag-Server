cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(SecretBundestagServer)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -mtune=native")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif ()

set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/comm/ConnectionHandler.cpp
        ${CMAKE_SOURCE_DIR}/src/comm/LobbyHandler.cpp
        ${CMAKE_SOURCE_DIR}/src/comm/Lobby.cpp
        ${CMAKE_SOURCE_DIR}/src/util/Logging.cpp
        ${CMAKE_SOURCE_DIR}/src/util/ArgumentParser.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/Error.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/JoinRequest.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/Message.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/Accept.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/StartRequest.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/Player.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/GameStart.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/CardType.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/EventType.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/Fraction.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/Office.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/Role.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/TriggerComparator.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/enum/TriggerCompositor.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/AbstractEventTrigger.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamecontroller/Controller.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamecontroller/Controller.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Board.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Board.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/CardRange.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/CardRange.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Environment.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Environment.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/EventTrigger.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/EventTrigger.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/GameStateRepresentation.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/GameStateRepresentation.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Player.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/Player.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/RuleSet.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/RuleSet.hpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/SingleCardEventTrigger.cpp
        ${CMAKE_SOURCE_DIR}/src/gamelogic/gamemodel/SingleCardEventTrigger.hpp
        ${CMAKE_SOURCE_DIR}/src/util/RandomGenerator.cpp)

set(LIBS stdc++fs pthread WebsocketCpp)

include_directories(SYSTEM lib)
include_directories(SYSTEM lib/json/single_include)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

add_subdirectory(test)

set(WebsocketCppBuildStatic ON CACHE INTERNAL "")
add_subdirectory(lib/WebsocketCpp)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)
