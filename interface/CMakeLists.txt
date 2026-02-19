find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

set(CMAKE_SWIG_FLAGS "-w503;-doxygen")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)

# Output Python files into build/cubik
set(CMAKE_SWIG_OUTDIR ${PROJECT_BINARY_DIR}/cubik)

# ================= Main Module =================
set_source_files_properties(cubik.i PROPERTIES CPLUSPLUS ON)

swig_add_library(cubik
    TYPE MODULE
    LANGUAGE python
    SOURCES cubik.i
)

set_target_properties(cubik PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/cubik
)

swig_link_libraries(cubik PRIVATE cubik_core Python3::Module)

# ================= Moves Submodule =================
set_source_files_properties(moves.i PROPERTIES CPLUSPLUS ON)

swig_add_library(cubik_moves
    TYPE MODULE
    LANGUAGE python
    SOURCES moves.i
)

set_target_properties(cubik_moves PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/cubik
)

swig_link_libraries(cubik_moves PRIVATE cubik_core Python3::Module)

# ================= Solver Submodule =================
set_source_files_properties(solver.i PROPERTIES CPLUSPLUS ON)

swig_add_library(cubik_solver
    TYPE MODULE
    LANGUAGE python
    SOURCES solver.i
)

set_target_properties(cubik_solver PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/cubik
)

swig_link_libraries(cubik_solver PRIVATE cubik_core Python3::Module)

# ================= Install =================

install(TARGETS
    cubik
    cubik_moves
    cubik_solver
    LIBRARY DESTINATION .
    RUNTIME DESTINATION .
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cubik.py"
    "${CMAKE_CURRENT_BINARY_DIR}/moves.py"
    "${CMAKE_CURRENT_BINARY_DIR}/solver.py"
    DESTINATION .
)
