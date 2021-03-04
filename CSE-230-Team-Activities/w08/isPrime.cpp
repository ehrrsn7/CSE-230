#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

void addPair(vector< pair<int, bool> > & targetList, int number, bool value, int & n) {
    targetList.push_back(pair<int, bool>(number, value));
    n++;
}

void isPrimeTest() {
    
    // SETUP
    vector< pair<int, bool> > primesTestValues;
    int n = 0;

    addPair(primesTestValues, -1,   false, n);  // Error: negative prime
    addPair(primesTestValues, -2,   false, n);  // Error: negative prime 2
    addPair(primesTestValues, 2,    true,  n);  // Prime 1
    addPair(primesTestValues, 3,    true,  n);  // Prime 2
    addPair(primesTestValues, 5,    true,  n);  // Prime 3
    addPair(primesTestValues, 7,    true,  n);  // Prime 4
    addPair(primesTestValues, 11,   true,  n);  // Prime 5
    addPair(primesTestValues, 13,   true,  n);  // Prime 6
    addPair(primesTestValues, 541,  true,  n);  // Prime 88
    addPair(primesTestValues, 1,    false, n);  // non-prime
    addPair(primesTestValues, 100,  false, n);  // non-prime

    int i = 0;
    while (i < n) {
        int number = get<0>(primesTestValues[i]);
        bool value = get<1>(primesTestValues[i]);

        // EXERCISE
        cout << number << " ";
        bool numberIsPrime = isPrime(number);

        // VERIFY
        cout << value << endl;
        assert(numberIsPrime == number);
        
        // TEARDOWN
        ++i;
    }
}

int main() {
    isPrimeTest();
    return 0;
}