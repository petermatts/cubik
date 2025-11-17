cmake_minimum_required(VERSION 3.15)
project(Cubik LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ========== Optional: Only download googletest if tests enabled ==========
option(ENABLE_TESTING "Enable unit tests" OFF)
if(ENABLE_TESTING)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

# toml++
FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(tomlplusplus)

# ========== Core C++ Library ==========
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

# Required for using cubik_core inside a shared library (SWIG module)
set_property(TARGET cubik_core PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(cubik_core PUBLIC inc)

# ========== SWIG Python Module ==========
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
set(CMAKE_SWIG_FLAGS "-w503")
find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)

set_source_files_properties(interface/cubik.i PROPERTIES CPLUSPLUS ON)

swig_add_library(cubik
    TYPE MODULE
    LANGUAGE python
    SOURCES interface/cubik.i
)

swig_link_libraries(cubik PRIVATE cubik_core Python3::Module)

# Place generated module in Python package when installing wheels
install(TARGETS cubik
    LIBRARY DESTINATION cubik
    RUNTIME DESTINATION cubik   # Windows
)

# ========== Optional CLI executable ==========
add_executable(cubik_cli main.cpp)
target_link_libraries(cubik_cli PRIVATE cubik_core)

install(TARGETS cubik_cli DESTINATION bin)

# ========== Tests ==========
if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
