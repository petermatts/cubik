add_library(cubik_core
    cube.cpp
    common.cpp
    parity.cpp
    solver.cpp
    searches/ida_star.cpp
    searches/a_star.cpp
    moves/B.cpp
    moves/D.cpp
    moves/E.cpp
    moves/F.cpp
    moves/L.cpp
    moves/M.cpp
    moves/R.cpp
    moves/S.cpp
    moves/U.cpp
    moves/X.cpp
    moves/Y.cpp
    moves/Z.cpp
)

set_property(TARGET cubik_core PROPERTY POSITION_INDEPENDENT_CODE ON)

target_include_directories(cubik_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/inc
)

target_link_libraries(cubik_core
    PUBLIC
        tomlplusplus::tomlplusplus
)

