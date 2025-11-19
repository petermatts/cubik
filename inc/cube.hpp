#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include "common.hpp"

using namespace std;

class Cube {
    public:
    Cube();
    Cube(const Cube &cube);
    ~Cube();

    Cube U() const;
    Cube D() const;
    Cube L() const;
    Cube R() const;
    Cube F() const;
    Cube B() const;

    Cube u() const;
    Cube d() const;
    Cube l() const;
    Cube r() const;
    Cube f() const;
    Cube b() const;

    Cube U_prime() const;
    Cube D_prime() const;
    Cube L_prime() const;
    Cube R_prime() const;
    Cube F_prime() const;
    Cube B_prime() const;

    Cube u_prime() const;
    Cube d_prime() const;
    Cube l_prime() const;
    Cube r_prime() const;
    Cube f_prime() const;
    Cube b_prime() const;

    Cube U2() const;
    Cube D2() const;
    Cube L2() const;
    Cube R2() const;
    Cube F2() const;
    Cube B2() const;

    Cube u2() const;
    Cube d2() const;
    Cube l2() const;
    Cube r2() const;
    Cube f2() const;
    Cube b2() const;

    Cube M() const;
    Cube E() const;
    Cube S() const;

    Cube M_prime() const;
    Cube E_prime() const;
    Cube S_prime() const;

    Cube M2() const;
    Cube E2() const;
    Cube S2() const;

    Cube X() const;
    Cube Y() const;
    Cube Z() const;

    Cube X_prime() const;
    Cube Y_prime() const;
    Cube Z_prime() const;

    Cube X2() const;
    Cube Y2() const;
    Cube Z2() const;

    Cube apply_moves(const vector<string> &moves);

    bool is_solved();
    string toString();
    
    vector<uint32_t> state_array() const;

    friend bool operator==(const Cube &cube1, const Cube &cube2);
    friend bool operator!=(const Cube &cube1, const Cube &cube2);

    string __str__();
    string __repr__(); //? add more special python support
    bool __eq__(const Cube &other);
    bool __ne__(const Cube &other);


    private:
    uint32_t up;
    uint32_t front;
    uint32_t left;
    uint32_t right;
    uint32_t back;
    uint32_t down;
    
    bool verify_orientation() const;
};

#endif // CUBE_HPP
