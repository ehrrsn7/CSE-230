/*************************************************************
 * 1. Name:
 *      Elijah Harrison
 * 2. Assignment Name:
 *      Lab 01: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, and writing code-
 *****************************************************************/

// include / define
#include <iostream>
#include <string>
#include <cmath>


const float mass_lm     = 15103;    // kg
const float g_moon      = -1.620;   // m/s/s
const float thrust_y    = 45000;    // N
const float thrust_x    = 450;      // N
const int   YEET        = 0;
const bool  DEBUG       = true;

// classes

// // prototypes
void prompt(float & v0y, float & v0x, float & y0);
void calculate(float & v0y, float & v0x, float & y0);

// main
int main() {
    // get initial velocity / altitude from user
    float v0y = -9.09, v0x = -0.3, y0 = 30; // automate (uncomment prompt to get vals from user)
    // prompt(v0y, v0x, y0);

    // calculate time to landing / final velocity and display
    calculate(v0y, v0x, y0);

    return YEET; // yeet us outta here, scotty
}

// functions

// prompt
float promptFloat(std::string prompt) {
    // TODO: error handling for invalid input
    std::cout << prompt << " ";
    float result;
    std::cin >> result;
    return result;
}

void prompt(float & v0y, float & v0x, float & y0) {
    /************************************************
     * Prompt:
     * 
     * Sample i/o (from rubric):
     * What is your vertical velocity (m/s)? -9.09
     * What is your horizontal velocity (m/s)? -0.3
     * What is your altitude (m)? 30
     * 
     * This program will prompt the user for the vertical 
     * velocity at the beginning of the simulation, the 
     * horizontal velocity at the beginning of the simulation, 
     * and the altitude above the moon's surface. 
     ************************************************/ 
    v0y = promptFloat("What is your vertical velocity (m/s)?");
    v0x = promptFloat("What is your horizontal velocity (m/s)?");
    y0  = promptFloat("What is your altitude (m)?");
}

// calculations
float quadraticFormula(float a, float b, float c) {
    std::cout << "Quadratic formula()\n";

    float discriminant = b*b - 4*a*c;
    std::cout << "Discriminant == " << discriminant << std::endl;

    if (discriminant == 0)
        return -b/(2*a);

    int error = -1;

    if (discriminant < 0) return error;
    float x1 = (-b + sqrt(discriminant)) / (2*a);
    float x2 = (-b - sqrt(discriminant)) / (2*a);
    std::cout << "x1 == " << x1 << ", x2 == " << x2 << std::endl; // debug roots
    if (x1 < 0 || x2 < 0) return error;
    return std::max(x1, x2);
 
    return error;
}

float getTotalAcceleration() { return (thrust_y/mass_lm) + (g_moon); }
void debug(std::string text) { if (DEBUG) std::cout << text << std::endl; }

float timeToLanding(float y0, float v0y) {
    float totalAcceleration = 0.6798; // goal number
    totalAcceleration = getTotalAcceleration();
    std::cout << "accel: " << totalAcceleration << std::endl;
    totalAcceleration /= 2;
    std::cout << "accel/2: " << totalAcceleration << std::endl;

    return quadraticFormula(totalAcceleration, v0y, y0);
}

void displayLandingInfo(float tn) {
    std::cout << "time:   " << tn << std::endl;
}

void calculate(float & v0y, float & v0x, float & y0) {
    float tn = timeToLanding(y0, v0y);
    displayLandingInfo(tn);
}

