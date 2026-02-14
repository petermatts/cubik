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

%typemap(out) std::vector<std::string> {
    PyObject* list = PyList_New($1.size());
    for (size_t i = 0; i < $1.size(); ++i) {
        PyList_SetItem(list, i, PyUnicode_FromString($1[i].c_str()));
    }
    $result = list;
}

%include "../inc/solver.hpp"
