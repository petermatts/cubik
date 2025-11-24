enable_testing()

add_executable(cubik_tests test_main.cpp test_moves.cpp test_parity.cpp)
target_include_directories(cubik_tests PRIVATE ${tomlplusplus_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/inc)
target_link_libraries(cubik_tests PRIVATE GTest::gtest_main cubik_core)

include(GoogleTest)
gtest_discover_tests(cubik_tests)

# Get path to the build dir for tests
set(TEST_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Copy the `solutions` folder to the test output directory
add_custom_command(
    TARGET cubik_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/solutions
            ${TEST_OUTPUT_DIR}/solutions
    COMMENT "Copying test data (solutions/) to test output directory"
)
