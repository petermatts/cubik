%module(directors="1", threads="1") solver

%{
#include "../inc/solver.hpp"
%}

%include <std_string.i>
%include <std_vector.i>
%include <std_shared_ptr.i>
%include <exception.i>

%shared_ptr(Heuristic)
%feature("director") Heuristic;


namespace std {
    %template(StringVector) vector<std::string>;
    %template(FloatVector) vector<float>;
    %template(CubeVector) vector<Cube>;
}

%include "../inc/solver.hpp"
