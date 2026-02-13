%module(directors="1") solver

%{
#include "../inc/solver.hpp"
%}

%include <stdint.i>
%include <std_string.i>
%include <std_vector.i>

namespace std {
    %template(StringVector) vector<std::string>;
    %template(FloatVector) vector<float>;
    %template(CubeVector) vector<Cube>;
}

%feature("director") Heuristic;

%include "../inc/solver.hpp"
