#include "toml.hpp"
#include "common.hpp"

#include <array>
#include <string>

using namespace std;

inline uint32_t string2colornum(string str) {
    if(str == "W") { return WHITE; }
    else if(str == "Y") { return YELLOW; }
    else if(str == "G") { return GREEN; }
    else if(str == "B") { return BLUE; }
    else if(str == "R") { return RED; }
    else if(str == "O") { return ORANGE; }
    else { throw invalid_argument("Unknown color read from TOML: " + str + "\n"); }
}

inline void set_face(toml::v3::node_view<toml::v3::node> node_view, uint32_t &face) {
    uint8_t i = 0;
    array<uint8_t, 9> shifts = {
        TOP_LEFT,
        TOP_MIDDLE,
        TOP_RIGHT,
        MIDDLE_LEFT,
        CENTER,
        MIDDLE_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_MIDDLE,
        BOTTOM_RIGHT
    };
    
    if(node_view.is_array()) {
        toml::array *toml_arr = node_view.as_array();
        for(auto&& elem : *toml_arr) {
            if(elem.is_string()) {
                face |= (string2colornum(*elem.value<std::string>()) << shifts[i++]);
            } else {
                cerr << "Non string element found when string element expected!" << endl;
            }
        }
    } else {
        //? add a helpful message
    }
}

inline vector<uint32_t> state(string toml_path) {
    array<uint8_t, 9> shifts = {
        TOP_LEFT,
        TOP_MIDDLE,
        TOP_RIGHT,
        MIDDLE_LEFT,
        CENTER,
        MIDDLE_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_MIDDLE,
        BOTTOM_RIGHT
    };

    array<uint8_t, 6> colors = {WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};
    vector<uint32_t> state_vector;

    try {
        toml::table solution = toml::parse_file(toml_path);
        
        uint32_t up = 0, front = 0, left = 0, right = 0, back = 0, down = 0;
        uint8_t u = 0, d = 0, l = 0, r = 0, f = 0, b = 0;

        if(auto node_view = solution["up"]) { set_face(node_view, up); }
        if(auto node_view = solution["front"]) { set_face(node_view, front); }
        if(auto node_view = solution["left"]) { set_face(node_view, left); }
        if(auto node_view = solution["right"]) { set_face(node_view, right); }
        if(auto node_view = solution["back"]) { set_face(node_view, back); }
        if(auto node_view = solution["down"]) { set_face(node_view, down); }

        state_vector = {up, front, right, back, left, down};
    } catch (const toml::parse_error& err) {
        cerr << "Error parsing TOML file: " << err << std::endl;
    }

    return state_vector;
}