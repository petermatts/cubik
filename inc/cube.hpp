#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include "common.hpp"

using namespace std;

/**
 * @brief Toggle emoji printing for cube state output display.
 * 
 * @param[in] value boolean to enable/disable emoji printing.
 */
inline void PRINT_EMOJIS(bool value) { __USE_EMOJI = value; }

/**
 * @brief 24 Byte represents a 3x3 Rubik's Cube.
 *
 * This class stores the cube state and provides move,
 * validation, and inspection utilities.
 */
class Cube {
    public:
    /**
     * @brief Construct a solved cube.
     */
    Cube();

    /**
     * @brief Cube copy constructor.
     */
    Cube(const Cube &cube);

    /**
     * @brief Cube destructor.
     */
    ~Cube();


    /**
     * @brief Apply a U move to the cube.
     * 
     * @return Cube 
     */
    Cube U() const;

    /**
     * @brief Apply a D move to the cube.
     * 
     * @return Cube 
     */
    Cube D() const;

    /**
     * @brief Apply a L move to the cube.
     * 
     * @return Cube 
     */
    Cube L() const;

    /**
     * @brief Apply a R move to the cube.
     * 
     * @return Cube 
     */
    Cube R() const;

    /**
     * @brief Apply a F move to the cube.
     * 
     * @return Cube 
     */
    Cube F() const;
    /**
     * @brief Apply a B move to the cube.
     * 
     * @return Cube 
     */
    Cube B() const;


    /**
     * @brief Apply a u move to the cube.
     * 
     * @return Cube 
     */
    Cube u() const;

    /**
     * @brief Apply a d move to the cube.
     * 
     * @return Cube 
     */
    Cube d() const;

    /**
     * @brief Apply a l move to the cube.
     * 
     * @return Cube 
     */
    Cube l() const;

    /**
     * @brief Apply a r move to the cube.
     * 
     * @return Cube 
     */
    Cube r() const;

    /**
     * @brief Apply a f move to the cube.
     * 
     * @return Cube 
     */
    Cube f() const;

    /**
     * @brief Apply a b move to the cube.
     * 
     * @return Cube 
     */
    Cube b() const;


    /**
     * @brief Apply a U' move to the cube.
     * 
     * @return Cube 
     */
    Cube U_prime() const;
    
    /**
     * @brief Apply a D' move to the cube.
     * 
     * @return Cube 
     */
    Cube D_prime() const;

    /**
     * @brief Apply a L' move to the cube.
     * 
     * @return Cube 
     */
    Cube L_prime() const;

    /**
     * @brief Apply a R' move to the cube.
     * 
     * @return Cube 
     */
    Cube R_prime() const;

    /**
     * @brief Apply a F' move to the cube.
     * 
     * @return Cube 
     */
    Cube F_prime() const;

    /**
     * @brief Apply a B' move to the cube.
     * 
     * @return Cube 
     */
    Cube B_prime() const;


    /**
     * @brief Apply a u' move to the cube.
     * 
     * @return Cube 
     */
    Cube u_prime() const;

    /**
     * @brief Apply a d' move to the cube.
     * 
     * @return Cube 
     */
    Cube d_prime() const;

    /**
     * @brief Apply a l' move to the cube.
     * 
     * @return Cube 
     */
    Cube l_prime() const;

    /**
     * @brief Apply a r' move to the cube.
     * 
     * @return Cube 
     */
    Cube r_prime() const;

    /**
     * @brief Apply a f' move to the cube.
     * 
     * @return Cube 
     */
    Cube f_prime() const;

    /**
     * @brief Apply a b' move to the cube.
     * 
     * @return Cube 
     */
    Cube b_prime() const;


    /**
     * @brief Apply a U2 move to the cube.
     * 
     * @return Cube 
     */
    Cube U2() const;

    /**
     * @brief Apply a D2 move to the cube.
     * 
     * @return Cube 
     */
    Cube D2() const;

    /**
     * @brief Apply a L2 move to the cube.
     * 
     * @return Cube 
     */
    Cube L2() const;

    /**
     * @brief Apply a R2 move to the cube.
     * 
     * @return Cube 
     */
    Cube R2() const;

    /**
     * @brief Apply a F2 move to the cube.
     * 
     * @return Cube 
     */
    Cube F2() const;

    /**
     * @brief Apply a B2 move to the cube.
     * 
     * @return Cube 
     */
    Cube B2() const;


    /**
     * @brief Apply a u2 move to the cube.
     * 
     * @return Cube 
     */
    Cube u2() const;

    /**
     * @brief Apply a d2 move to the cube.
     * 
     * @return Cube 
     */
    Cube d2() const;

    /**
     * @brief Apply a l2 move to the cube.
     * 
     * @return Cube 
     */
    Cube l2() const;

    /**
     * @brief Apply a r2 move to the cube.
     * 
     * @return Cube 
     */
    Cube r2() const;

    /**
     * @brief Apply a f2 move to the cube.
     * 
     * @return Cube 
     */
    Cube f2() const;

    /**
     * @brief Apply a b2 move to the cube.
     * 
     * @return Cube 
     */
    Cube b2() const;


    /**
     * @brief Apply a M move to the cube.
     * 
     * @return Cube 
     */
    Cube M() const;

    /**
     * @brief Apply a E move to the cube.
     * 
     * @return Cube 
     */
    Cube E() const;

    /**
     * @brief Apply a S move to the cube.
     * 
     * @return Cube 
     */
    Cube S() const;


    /**
     * @brief Apply a M' move to the cube.
     * 
     * @return Cube 
     */
    Cube M_prime() const;

    /**
     * @brief Apply a E' move to the cube.
     * 
     * @return Cube 
     */
    Cube E_prime() const;

    /**
     * @brief Apply a S' move to the cube.
     * 
     * @return Cube 
     */
    Cube S_prime() const;


    /**
     * @brief Apply a M2 move to the cube.
     * 
     * @return Cube 
     */
    Cube M2() const;

    /**
     * @brief Apply a E2 move to the cube.
     * 
     * @return Cube 
     */
    Cube E2() const;

    /**
     * @brief Apply a S2 move to the cube.
     * 
     * @return Cube 
     */
    Cube S2() const;


    /**
     * @brief Apply a X move to the cube.
     * 
     * @return Cube 
     */
    Cube X() const;

    /**
     * @brief Apply a Y move to the cube.
     * 
     * @return Cube 
     */
    Cube Y() const;

    /**
     * @brief Apply a Z move to the cube.
     * 
     * @return Cube 
     */
    Cube Z() const;


    /**
     * @brief Apply a X' move to the cube.
     * 
     * @return Cube 
     */
    Cube X_prime() const;

    /**
     * @brief Apply a Y' move to the cube.
     * 
     * @return Cube 
     */
    Cube Y_prime() const;

    /**
     * @brief Apply a Z' move to the cube.
     * 
     * @return Cube 
     */
    Cube Z_prime() const;


    /**
     * @brief Apply a X2 move to the cube.
     * 
     * @return Cube 
     */
    Cube X2() const;

    /**
     * @brief Apply a Y2 move to the cube.
     * 
     * @return Cube 
     */
    Cube Y2() const;

    /**
     * @brief Apply a Z2 move to the cube.
     * 
     * @return Cube 
     */
    Cube Z2() const;

    /**
     * @brief Apply a sequence of moves and return the resulting cube state.
     * 
     * @param moves Vector/List of moves (strings/Moves).
     * 
     * @return Cube 
     */
    Cube apply_moves(const vector<string> &moves);

    /**
     * @brief Return the canonical representation of the cube, i.e. the white center is on the up face,
     * green center is on the front face, and the red center is on the right face.
     * 
     * @return Cube 
     */
    Cube canonical() const;

    /**
     * @brief Returns true if the cube is in a solved state, false otherwise.
     * 
     * @return Boolean indicating if the cube is solved.
     */
    bool is_solved();

    /**
     * @brief Returns a string representation of the cube.
     * 
     * @details If emojis are enabled (default), uses colored emojis to represent stickers. Otherwise, uses letters. example 'W' for white.
     * 
     * @return String
     */
    string toString() const;
    
    /**
     * @brief Validate (solvability) the cube state. I.e. a valid state is a solvable state.
     * 
     * @return Boolean indicating if the cube state is valid. Retturns true if valid, false otherwise.
     */
    bool is_valid_state() const;

    /**
     * @brief Verify that the center pieces are in their correct positions.
     * 
     * @return Boolean indicating if the centers are correctly positioned.
     */
    bool verify_centers() const;

    /**
     * @brief Get the state representation of the cube (array/vector of length 6).
     * 
     * @details Each face is represented as a 32-bit unsigned integer, with the 27 least significant bits used to represent the stickers on that face.
     *          The order of the faces in the returned vector is: Up, Front, Right, Back, Left, Down.
     * 
     * @return vector<uint32_t> 
     */
    vector<uint32_t> get_state() const;

    /**
     * @brief Set the cube state from a given state representation.
     * 
     * @details The input vector should contain 6 elements, each representing a face of the cube as a 32-bit unsigned integer.
     *          The order of the faces in the input vector should be: Up, Front, Right, Back, Left, Down.
     * 
     * @param[in] state Vector of 6 uint32_t representing the cube state.
     * 
     * @throws logic_error if the input state vector is not valid.
     * 
     * @return Boolean indicating if the state was set successfully. Returns false if the input state is invalid.
     */
    bool set_state(const vector<uint32_t> &state);

    /**
     * @brief Check if this cube is rotation-equivalent to another cube.
     * 
     * @param[in] other The other cube to compare against.
     * 
     * @return Boolean indicating if the two cubes are rotation-equivalent.
     */
    bool is_rotation_equal(Cube &other) const;

    /**
     * @brief Compare two cubes for equality.
     * 
     * @param cube1 
     * @param cube2 
     * @return true 
     * @return false 
     */
    friend bool operator==(const Cube &cube1, const Cube &cube2);

    /**
     * @brief Compare two cubes for inequality.
     * 
     * @param cube1 
     * @param cube2 
     * @return true 
     * @return false 
     */
    friend bool operator!=(const Cube &cube1, const Cube &cube2);

    /**
     * @brief Output stream operator for printing the cube.
     * 
     * @param os Output stream.
     * @param obj Cube object to print.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Cube& obj);

    /**
     * @brief Returns a string representation of the cube.
     * 
     * @details If emojis are enabled (default), uses colored emojis to represent stickers. Otherwise, uses letters. example 'W' for white.
     * 
     * @return String
     */
    string __str__();

    /**
     * @brief Returns a representation of the cube (a string equivalent to calling __str__).
     * 
     * @details If emojis are enabled (default), uses colored emojis to represent stickers. Otherwise, uses letters. example 'W' for white.
     * 
     * @return String
     */
    string __repr__(); //? add more special python support

    /**
     * @brief Compare cubes for equality.
     * 
     * @param other 
     * @return true if cubes are equal
     * @return false otherwise
     */
    bool __eq__(const Cube &other);

    /**
     * @brief Compare cubes for inequality.
     * 
     * @param other 
     * @return true if cubes are not equal
     * @return false otherwise
     */
    bool __ne__(const Cube &other);

    private:
    uint32_t up;
    uint32_t front;
    uint32_t left;
    uint32_t right;
    uint32_t back;
    uint32_t down;

    bool check_corner_orientation() const;
    bool check_edge_orientation() const;
    bool check_piece_counts() const;
    
    std::array<int8_t, 8> corner_permutation() const;
    std::array<int8_t, 12> edge_permutation() const;

    int corner_parity() const;
    int edge_parity() const;
    bool check_parity() const;
    CornerCubie get_corner_cubie(int pos) const;
    EdgeCubie get_edge_cubie(int pos) const;
};

#endif // CUBE_HPP
