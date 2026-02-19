add_executable(cubik_tests 
    test_main.cpp
    test_moves.cpp
    test_parity.cpp
    test_solver.cpp
)

target_link_libraries(cubik_tests
    PRIVATE
        GTest::gtest_main
        cubik_core
        tomlplusplus::tomlplusplus
)

include(GoogleTest)
gtest_discover_tests(cubik_tests)

# Copy test data
add_custom_command(
    TARGET cubik_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/solutions
            ${CMAKE_CURRENT_BINARY_DIR}/solutions
    COMMENT "Copying test data (solutions/) to test output directory"
)
