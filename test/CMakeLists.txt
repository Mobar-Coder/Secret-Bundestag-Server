project(Tests)

enable_testing()
find_package(GTest)
if (GTest_FOUND)
    include_directories(${GTEST_INCLUDE_DIR})

    file(GLOB_RECURSE TEST_SOURCES . *.cpp)

    include_directories(${CMAKE_SOURCE_DIR}/src)

    add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${TEST_SOURCES})

    target_link_libraries(${PROJECT_NAME} ${LIBS} gmock gtest)

    add_test(
            NAME ${PROJECT_NAME}
            COMMAND ${PROJECT_NAME}
    )
endif()
