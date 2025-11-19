%module cubik

%{
#include "../inc/common.hpp"
#include "../inc/cube.hpp"
%}

%include <stdint.i>
%include <std_string.i>
%include <std_vector.i>
%template(Uint32Vector) std::vector<uint32_t>;

%rename(__eq__) Cube::operator==;
%rename(__ne__) Cube::operator!=;

%include "../inc/cube.hpp"