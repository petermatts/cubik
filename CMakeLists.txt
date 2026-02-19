cmake_minimum_required(VERSION 3.20)
project(Cubik LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ================= Options =================
option(ENABLE_TESTING "Enable unit tests" ON)
option(BUILD_PYTHON "Build Python bindings" ON)
option(BUILD_CLI "Build CLI executable" ON)

# ================= Dependencies =================

# ---- toml++ (always required) ----
FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

# ---- GoogleTest (optional) ----
if(ENABLE_TESTING)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

# ================= Subdirectories =================

add_subdirectory(src)

if(BUILD_PYTHON)
    add_subdirectory(interface)
endif()

if(BUILD_CLI)
    add_executable(cubik_cli main.cpp)
    target_link_libraries(cubik_cli PRIVATE cubik_core)
    install(TARGETS cubik_cli DESTINATION bin)
endif()

if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

