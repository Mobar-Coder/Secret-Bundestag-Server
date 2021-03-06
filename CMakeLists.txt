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
        ${CMAKE_SOURCE_DIR}/src/comm/ConnectionHandler.cpp
        ${CMAKE_SOURCE_DIR}/src/comm/LobbyHandler.cpp
        ${CMAKE_SOURCE_DIR}/src/comm/Lobby.cpp
        ${CMAKE_SOURCE_DIR}/src/util/Logging.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/Error.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/JoinRequest.cpp
        ${CMAKE_SOURCE_DIR}/src/messages/Message.cpp)

set(LIBS stdc++fs pthread WebsocketCpp)

include_directories(lib)
include_directories(lib/json/single_include)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

add_subdirectory(test)
add_subdirectory(lib/WebsocketCpp)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)
