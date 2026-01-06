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

# ========== toml++ ==========
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
    src/parity.cpp
    src/solver.cpp
    src/searches/ida_star.cpp
    src/searches/a_star.cpp
)

# Required for using cubik_core inside a shared library (SWIG module)
set_property(TARGET cubik_core PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(cubik_core PUBLIC inc)

# ========== SWIG Python Module ==========
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
set(CMAKE_SWIG_FLAGS "-w503;-doxygen")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)

# --- Main module: cubik ---
set_source_files_properties(interface/cubik.i PROPERTIES CPLUSPLUS ON)

swig_add_library(cubik
    TYPE MODULE
    LANGUAGE python
    SOURCES interface/cubik.i
)

swig_link_libraries(cubik PRIVATE cubik_core Python3::Module)

# --- Submodule: cubik.moves ---
set_source_files_properties(interface/moves.i PROPERTIES CPLUSPLUS ON)

swig_add_library(cubik_moves
    TYPE MODULE
    LANGUAGE python
    SOURCES interface/moves.i
)

swig_link_libraries(cubik_moves PRIVATE cubik_core Python3::Module)

# ========== Install Python Extension + Wrapper ==========
# Install main SWIG extension
install(TARGETS cubik
    LIBRARY DESTINATION . # Linux / macOS
    RUNTIME DESTINATION . # Windows
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cubik.py"
    DESTINATION .
)

# Install moves submodule (_moves.so + moves.py)
install(TARGETS cubik_moves
    LIBRARY DESTINATION .       # goes inside the cubik package folder
    RUNTIME DESTINATION .
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/moves.py"
    DESTINATION .
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
