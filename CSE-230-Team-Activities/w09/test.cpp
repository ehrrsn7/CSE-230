
#include <iostream>
using namespace std;


bool isLeapYear(int year) {
    // if (year < 1753) return false;
    if (year % 100 == 0 && year % 400 != 0) return false;
    return year % 4 == 0;
}


void test_isLeapYear() {
    // leap years between centuries
    assert(true == isLeapYear(2004));  // first leap of the century
    assert(true == isLeapYear(2032));  // middle of the century
    assert(true == isLeapYear(2096));  // last of the century
    assert(true == isLeapYear(1756));  // previous century

    // not leap years between centuries
    assert(false == isLeapYear(2001));  // first non-leap of the century
    assert(false == isLeapYear(2002));  // remainder is 2
    assert(false == isLeapYear(2003));  // remainder is 3
    assert(false == isLeapYear(2051));  // middle of the century
    assert(false == isLeapYear(2099));  // last non-leap of the century
    assert(false == isLeapYear(1753));  // previous century
 
    // not leap years if on beginning of century
    assert (false == isLeapYear(1800)); // 19th century
    assert (false == isLeapYear(1900)); // 20th century
    assert (false == isLeapYear(2100)); // 22th century
    assert (false == isLeapYear(2200)); // 23th century
    assert (false == isLeapYear(2300)); // 24th century
    assert (false == isLeapYear(2500)); // 26th century

    // exception to above rule: every fourth century is a leap year
    assert (true == isLeapYear(2000)); // 21st century
    assert (true == isLeapYear(2400)); // 23rd century
    assert (true == isLeapYear(2800)); // 25th century
    assert (true == isLeapYear(3200)); // 27th century

    // range error: gregorian calendar not used before 1753
    
}



int main() {
    cout << "main() has run, program compiled and executed successfully." << endl;
    test_isLeapYear();
    cout << "All tests run successfully." << endl;
    return 0;
}
