cmake_minimum_required(VERSION 3.15)
project(Cubik LANGUAGES CXX)

# Use C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Fetching External Dependencies
include(FetchContent)

# GoogleTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

# toml++
FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

# Enable SWIG and Python
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

# Add the main source directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Create a shared library for core logic
add_library(cubik_core
    src/cube.cpp
    src/common.cpp
    src/moves/B.cpp
    src/moves/D.cpp
    src/moves/E.cpp
    src/moves/F.cpp
    src/moves/L.cpp
    src/moves/M.cpp
    src/moves/R.cpp
    src/moves/S.cpp
    src/moves/U.cpp
    src/moves/X.cpp
    src/moves/Y.cpp
    src/moves/Z.cpp
)
target_include_directories(cubik_core PUBLIC src)


# SWIG configuration
set_source_files_properties(interface/cubik.i PROPERTIES CPLUSPLUS ON)
set(CMAKE_SWIG_FLAGS "-w503")

add_definitions(-DSWIG_PYTHON_INTERPRETER_NO_DEBUG)

swig_add_library(cubik_python
    LANGUAGE python
    TYPE MODULE
    SOURCES interface/cubik.i
            src/cube.cpp
            src/common.cpp
            src/moves/B.cpp
            src/moves/D.cpp
            src/moves/E.cpp
            src/moves/F.cpp
            src/moves/L.cpp
            src/moves/M.cpp
            src/moves/R.cpp
            src/moves/S.cpp
            src/moves/U.cpp
            src/moves/X.cpp
            src/moves/Y.cpp
            src/moves/Z.cpp
)

# Link SWIG module with Python and core logic
target_include_directories(cubik_python PRIVATE ${Python3_INCLUDE_DIRS})

if(Python3_LIBRARIES MATCHES "optimized;(.+);debug;(.+)")
    foreach(lib ${Python3_LIBRARIES})
        if(lib MATCHES ".*/?python[0-9]+\\.lib$")
            set(Python3_LIB_ONLY "${lib}")
        endif()
    endforeach()
    swig_link_libraries(cubik_python PRIVATE ${Python3_LIB_ONLY} cubik_core)
else()
    # Fallback for single-lib scenarios
    swig_link_libraries(cubik_python PRIVATE ${Python3_LIBRARIES} cubik_core)
endif()

# Build main executable
# todo: add compiler optimiztions?
add_executable(cubik main.cpp)
target_include_directories(cubik PRIVATE ${tomlplusplus_SOURCE_DIR}) # todo remove this
target_link_libraries(cubik PRIVATE cubik_core)

add_subdirectory(tests)
