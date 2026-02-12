%module(package="cubik") solver

%{
#include "../inc/solver.hpp"
%}

%include "../inc/solver.hpp"

%typemap(in) SearchAlgorithm {
    $1 = static_cast<SearchAlgorithm>($input);
}

