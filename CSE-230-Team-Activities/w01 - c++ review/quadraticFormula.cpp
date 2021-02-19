#include <iostream>

float quadraticFormula(float a, float b, float c) {
    std::cout << "Quadratic formula()\n";

    // find discriminant
    float discriminant = b*b - 4*a*c;
    std::cout << "Discriminant == " << discriminant << std::endl;

    // roots do not exist
    float error = -1.234;
    if (discriminant < 0) return error;

    // roots are equivalent
    if (discriminant == 0) return -b/(2*a);

    // two distinct roots
    float x1 = (-b + sqrt(discriminant)) / (2*a);
    float x2 = (-b - sqrt(discriminant)) / (2*a);
    std::cout << "x1 == " << x1 << ", x2 == " << x2 << std::endl; // debug roots
    // if (x1 < 0 || x2 < 0) return error;
    return std::max(x1, x2);
 
    // else
    return error;
}

int main() {
    std::cout << quadraticFormula(0.6798,-9.09,30) << std::endl;
    return 0;
}