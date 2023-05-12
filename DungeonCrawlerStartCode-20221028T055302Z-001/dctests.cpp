#include <iostream>
#include "logic.h"

using std::cout, std::endl;

// TODO(student): Write unit tests for the functions in logic.h
//                You should end up with at least 500 lines of test code

int main() {
    
    // example
    /*
    example.txt
    -----------
    5 3
    3 0
    M + -
    - + -
    - + !
    - - -
    @ - $
    */
    ////////////////////
    // this is the only code _required_ to get coverage points on the extra credit
    //   invocation --> coverage
    int maxRow;
    int maxCol;
    Player player;
    char** level = loadLevel("example.txt", maxRow, maxCol, player);
    ////////////////////
    
    ////////////////////
    // this is optional but STRONGLY recommended for preparing for implementing dungeon crawler
    //   coverage -/-> correctness
    // note: there are _many_ ways to do this part, including ways that are more elegant and efficient than this way demonstrated here
    if (level == nullptr) {
        cout << "FAIL: level is nullptr" << endl;
    } else {
        cout << " OK : level is not nullptr" << endl;
        if (maxRow == 5) {
            cout << " OK : maxRow is 5" << endl;
        } else {
            cout << "FAIL: expected maxRow to be 5, got " << maxRow << endl; 
        }
        if (maxCol == 3) {
            cout << " OK : maxCol is 3" << endl;
        } else {
            cout << "FAIL: expected maxCol to be 3, got " << maxCol << endl; 
        }
        if (player.row == 3) {
            cout << " OK : player.row is 3" << endl;
        } else {
            cout << "FAIL: expected player.row to be 3, got " << player.row << endl; 
        }
        if (player.col == 0) {
            cout << " OK : player.col is 0" << endl;
        } else {
            cout << "FAIL: expected player.col to be 0, got " << player.col << endl; 
        }
        if (level[0][0] == 'M') {
            cout << " OK : level[0][0] is M" << endl;
        } else {
            cout << "FAIL: expected level[0][0] to be M, got " << level[0][0] << endl; 
        }
        if (level[0][1] == '+') {
            cout << " OK : level[0][1] is +" << endl;
        } else {
            cout << "FAIL: expected level[0][1] to be +, got " << level[0][1] << endl; 
        }
        if (level[0][2] == '-') {
            cout << " OK : level[0][2] is -" << endl;
        } else {
            cout << "FAIL: expected level[0][2] to be -, got " << level[0][2] << endl; 
        }
        if (level[1][0] == '-') {
            cout << " OK : level[1][0] is -" << endl;
        } else {
            cout << "FAIL: expected level[1][0] to be -, got " << level[1][0] << endl; 
        }
        if (level[1][1] == '+') {
            cout << " OK : level[1][1] is +" << endl;
        } else {
            cout << "FAIL: expected level[1][1] to be +, got " << level[1][1] << endl; 
        }
        if (level[1][2] == '-') {
            cout << " OK : level[1][2] is -" << endl;
        } else {
            cout << "FAIL: expected level[1][2] to be -, got " << level[1][2] << endl; 
        }
        if (level[2][0] == '-') {
            cout << " OK : level[2][0] is -" << endl;
        } else {
            cout << "FAIL: expected level[2][0] to be -, got " << level[2][0] << endl; 
        }
        if (level[2][1] == '+') {
            cout << " OK : level[2][1] is +" << endl;
        } else {
            cout << "FAIL: expected level[2][1] to be +, got " << level[2][1] << endl; 
        }
        if (level[2][2] == '!') {
            cout << " OK : level[2][2] is !" << endl;
        } else {
            cout << "FAIL: expected level[2][2] to be !, got " << level[2][2] << endl; 
        }
        if (level[3][0] == 'o') {
            cout << " OK : level[3][0] is o" << endl;
        } else {
            cout << "FAIL: expected level[3][0] to be o, got " << level[3][0] << endl; 
        }
        if (level[3][1] == '-') {
            cout << " OK : level[3][1] is -" << endl;
        } else {
            cout << "FAIL: expected level[3][1] to be -, got " << level[3][1] << endl; 
        }
        if (level[3][2] == '-') {
            cout << " OK : level[3][2] is -" << endl;
        } else {
            cout << "FAIL: expected level[3][2] to be -, got " << level[3][2] << endl; 
        }
        if (level[4][0] == '@') {
            cout << " OK : level[4][0] is @" << endl;
        } else {
            cout << "FAIL: expected level[4][0] to be @, got " << level[4][0] << endl; 
        }
        if (level[4][1] == '-') {
            cout << " OK : level[4][1] is -" << endl;
        } else {
            cout << "FAIL: expected level[4][1] to be -, got " << level[4][1] << endl; 
        }
        if (level[4][2] == '$') {
            cout << " OK : level[4][2] is $" << endl;
        } else {
            cout << "FAIL: expected level[4][2] to be $, got " << level[4][2] << endl; 
        }
    }
    ////////////////////
    
    ////////////////////
    // this is required to prevent memory leaks on part 1 (test first)
    if (level) {
        for (int row = 0; row < 5; row++) {
            delete[] level[row];
        }
        delete[] level;
    }
    ////////////////////
    
    return 0;
}
