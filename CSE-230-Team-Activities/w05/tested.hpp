
#include <iostream>
using namespace std;

#include "position.hpp"

void tested() {
    // test a valid position first
    cout << "Test King position\n";
    Position king;      // create position
    king.set(0, 4);     // set position functionality
    king.display();     // test display functionality
    // test getters functionality
    cout << "King row/column indexes: "
         << king.getRow() << " " << king.getCol() << endl;

    // test invalid positions
    cout << "\nInvalid position no. 1\n";
    Position invalid;
    invalid.set(-1, -1);
    invalid.display();

    cout << "\nInvalid position no. 2\n";
    Position invalid2;
    invalid2.set(64, 64);
    invalid2.display();
}
