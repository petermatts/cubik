%module cubik

%{
#include "../inc/common.hpp"
#include "../inc/cube.hpp"
%}
    
%include <std_string.i>
%include <std_vector.i>

%rename(__eq__) Cube::operator==;
%rename(__ne__) Cube::operator!=;

%include "../inc/cube.hpp"