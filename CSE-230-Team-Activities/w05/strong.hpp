#include <iostream>
#include "position.hpp"

void strong() {
    Position positioni;
    std::cout << "\nTesting all possible possible correct positions\n";
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            positioni.set(i, j);
    // (error handling in Position::set() will display any errors)

    std::cout << "\nTesting invalid range error handling\n";
    positioni.set(-1,0); // invalid row     (<0)
    positioni.set(0,-1); // invalid column  (<0)
    positioni.set(8,0);  // invalid row     (>8)
    positioni.set(0,8);  // invalid column  (>8)

    std::cout << "\nTesting invalid input\n";
    positioni.set('a', 'b');
}
