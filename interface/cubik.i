%module cubik

%{
#include "../inc/common.hpp"
#include "../inc/cube.hpp"
%}

/* ---- Primitive + STL includes ---- */
%include <stdint.i>
%include <std_string.i>
%include <std_vector.i>

/* ---- STL vector instantiations ---- */
namespace std {
    %template(Uint32Vector) vector<uint32_t>;
    %template(StringVector) vector<std::string>;
}

/* ---- Python operator renames ---- */
%rename(__eq__) Cube::operator==;
%rename(__ne__) Cube::operator!=;

/* ---- Include your actual headers ---- */
%include "../inc/cube.hpp"