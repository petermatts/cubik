#include "cube.hpp"
#include "moves.hpp"

using namespace std;

void solvedMsg(Cube cube) {
    if(cube.is_solved()) {
        cout << "Cube is solved :)" << endl << endl;
    } else {
        cout << "Cube is not solved :(" << endl << endl;
    }
}

int main() {
    Cube cube = Cube();
    Cube c = Cube();
    cout << cube << endl;
    solvedMsg(cube);
    cout << "Cube is " << sizeof(cube) << "B" << endl;
    auto state = cube.get_state();

    // PRINT_EMOJIS(false);
    // cout << cube << endl;

    // cout << WHITE_FACE << endl << YELLOW_FACE << endl << GREEN_FACE << endl
    //      << BLUE_FACE << endl << RED_FACE << endl << ORANGE_FACE << endl;

    // cout << "Performing R turn:" << endl;
    // c = cube.R();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing R' turn:" << endl;
    // c = cube.R_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing L turn:" << endl;
    // c = cube.L();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing L' turn:" << endl;
    // c = cube.L_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing U turn:" << endl;
    // c = cube.U();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing U' turn:" << endl;
    // c = cube.U_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing D turn:" << endl;
    // c = cube.D();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing D' turn:" << endl;
    // c = cube.D_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing F turn:" << endl;
    // c = cube.F();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing F' turn:" << endl;
    // c = cube.F_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing B turn:" << endl;
    // c = cube.B();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing B' turn:" << endl;
    // c = cube.B_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing M turn:" << endl;
    // c = cube.M();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing M' turn:" << endl;
    // c = cube.M_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing E turn:" << endl;
    // c = cube.E();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing E' turn:" << endl;
    // c = cube.E_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing S turn:" << endl;
    // c = cube.S();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing S' turn:" << endl;
    // c = cube.S_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing U2 turn:" << endl;
    // c = cube.U2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing D2 turn:" << endl;
    // c = cube.D2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing L2 turn:" << endl;
    // c = cube.L2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing R2 turn:" << endl;
    // c = cube.R2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing F2 turn:" << endl;
    // c = cube.F2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing B2 turn:" << endl;
    // c = cube.B2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing M2 turn:" << endl;
    // c = cube.M2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing E2 turn:" << endl;
    // c = cube.E2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing S2 turn:" << endl;
    // c = cube.S2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing X rotation:" << endl;
    // c = cube.X();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing Y rotation:" << endl;
    // c = cube.Y();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing Z rotation:" << endl;
    // c = cube.Z();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing X' rotation:" << endl;
    // c = cube.X_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing Y' rotation:" << endl;
    // c = cube.Y_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing Z' rotation:" << endl;
    // c = cube.Z_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing X2 rotation:" << endl;
    // c = cube.X2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing Y2 rotation:" << endl;
    // c = cube.Y2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing Z2 rotation:" << endl;
    // c = cube.Z2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing u turn:" << endl;
    // c = cube.u();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing u' turn:" << endl;
    // c = cube.u_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing d turn:" << endl;
    // c = cube.d();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing d' turn:" << endl;
    // c = cube.d_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing l turn:" << endl;
    // c = cube.l();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing l' turn:" << endl;
    // c = cube.l_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing r turn:" << endl;
    // c = cube.r();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing r' turn:" << endl;
    // c = cube.r_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing f turn:" << endl;
    // c = cube.f();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing f' turn:" << endl;
    // c = cube.f_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing b turn:" << endl;
    // c = cube.b();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing b' turn:" << endl;
    // c = cube.b_prime();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing u2 turn:" << endl;
    // c = cube.u2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing d2 turn:" << endl;
    // c = cube.d2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing l2 turn:" << endl;
    // c = cube.l2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing r2 turn:" << endl;
    // c = cube.r2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing f2 turn:" << endl;
    // c = cube.f2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing b2 turn:" << endl;
    // c = cube.b2();
    // cout << c << endl;
    // solvedMsg(c);

    // cout << "Performing move sequence U->U" << endl;
    // c = cube.apply_moves({moves::U, moves::U});
    // cout << c << endl;
    // solvedMsg(c);
}
