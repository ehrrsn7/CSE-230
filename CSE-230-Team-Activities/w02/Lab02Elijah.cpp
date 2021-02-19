/*************************************************************
 * 1. Name:
 *      Elijah Harrison
 * 2. Assignment Name:
 *      Lab 01: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      This week's difficulty was 100% trying to work out bugs
 *      with Lab01. I didn't have it done beforehand, and when 
 *      I started it this week it took a pretty long time.
 *      I kept on getting unexpected results and the algorithm
 *      was difficult to debug. However, this week's assignment
 *      was much simpler.
 * 5. How long did it take for you to complete the assignment?
 *      4 Hours
 * 
 * relevant links:
 * - how to use M_PI
 * https://stackoverflow.com/questions/1727881/how-to-use-the-pi-constant-in-c
 * - refresher how to use setprecision
 * http://www.cplusplus.com/reference/iomanip/setprecision/
 *****************************************************************/

// import / define

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#define YEET 0
#define DEBUG true
#define ERROR false

// physics properties and equations definitions

const float mass_lm             = 15103; // kg
const float g_moon              = 1.625; // m/s/s
const float f_thrust_lm_engine  = 45000; // N (or kg m/s/s)

float magnitudeToX(float mag, float angleRadians);
float magnitudeToY(float mag, float angleRadians);
// (prototypes of functions to be used by getAccel)

float getAccelX(float thrustAngleRadians) {
    return magnitudeToX(f_thrust_lm_engine, thrustAngleRadians)/mass_lm;
}

float getAccelY(float thrustAngleRadians) {
    return (magnitudeToY(f_thrust_lm_engine, thrustAngleRadians)/mass_lm + g_moon);
}

// debug function

void debug(std::string text) {
    if (DEBUG) std::cout << "debug: " << text << std::endl;
}

// more math helper functions

float rad(float angleDegrees) { return M_PI * angleDegrees/180; }
float deg(float angleRadians) { return 180 * angleRadians/M_PI; }

float mag(float x, float y)
    { return std::sqrt(std::pow(x, 2) + std::pow(y, 2)); }
float magnitudeToX(float mag, float angleRadians)
    { return mag * cos(angleRadians); }
float magnitudeToY(float mag, float angleRadians)
    { return mag * sin(angleRadians); }

bool quadraticFormula(
    float & root1, float & root2, 
    float a, float b, float c) {
    debug("quadraticFormula()");

    // find the descriminant
    float discriminant = b*b - 4*a*c;
    debug("Discriminant == " + std::to_string(discriminant));

    // roots are the same if discr == 0
    if (discriminant == 0) {
        root1 = root2 = -b/(2*a);
        debug("y(0) == " + std::to_string(root1));
        return true;
    }

    // if roots are complex numbers, return ERROR (false)
    if (discriminant < 0) return ERROR;

    // quadratic formula
    root1 = (-b + sqrt(discriminant)) / (2*a);
    root2 = (-b - sqrt(discriminant)) / (2*a);
    
    // debug quadratic formula
    std::string rootDebug = "y(0) == ";
    rootDebug += std::to_string(root1) + ", ";
    rootDebug += std::to_string(root2);
    debug(rootDebug);

    // if (discriminant >= 0)
    return true; // indicate that the root(s) are not complex
}

float timeToLand(float y0, float vy0, float thrustAngleRadians) {
    // y(t) = 1/2 accel t^2 + v0y t + y0
    // t1, t2 = quadratic formula [1/2 accel, vy0, y0]
    float t1, t2;

    bool isRealNumber = quadraticFormula(
        t1, t2, .5 * getAccelY(thrustAngleRadians), vy0, y0
    );

    if (isRealNumber) return std::max(t1, t2);
    /** else */ return -1; // error
}

float positionXAtTime(float x0, float vx0, float thrustAngleRadians, float t) {
    // x(t) = 1/2 accelx t^2 + vx0 t + x0
    return .5 * (getAccelX(thrustAngleRadians) * std::pow(t, 2)) + vx0 * t + x0;
}

float positionYAtTime(float y0, float vy0, float thrustAngleRadians, float t) {
    // y(t) = 1/2 accely t^2 + vy0 t + y0
    return .5 * (getAccelY(thrustAngleRadians) * std::pow(t, 2)) + vy0 * t + y0;
}

float velocityXAtTime(float vx0, float thrustAngleRadians, float t) {
    // vx(t) = accelx t + vx0
    return getAccelX(thrustAngleRadians) * t + vx0;
}

float velocityYAtTime(float vy0, float thrustAngleRadians, float t) {
    // vy(t) = accely t + vy0
    return getAccelY(thrustAngleRadians) * t + vy0;
}


// class definitions

// function prototypes / other helper functions

float promptFloat(std::string prompt) {
    float response;
    std::cout << prompt << " ";
    std::cin >> response;
    return response;
}


// main
int main() {
    // get/prompt
    float vy0   = promptFloat("What is your vertical velocity (m/s)?");
    float vx0   = promptFloat("What is your horizontal velocity (m/s)?");
    float y0    = promptFloat("What is your altitude (m)?");
    float x0    = 0;

    float thrustAngleRadians = promptFloat(
        "What is the angle of the LM where 0 is up (degrees)?");
    thrustAngleRadians += deg(90); // 0° is up

    std::cout << std::endl;

    // initialize s(t) and v(t) components
    float x         = x0;
    float y         = y0;
    float dx        = vx0;
    float dy        = vy0;
    float speed     = mag(dx, dy);

    // loop variables
    int multiplier  = 0;
    int offset      = 0;
    int i           = 0;

    while (y > 0) {
        std::cout << "\nFor the next 5 seconds with the main engine "
            << "on, the position of the lander is:\n\n";

        for (int t = i; t < i + 5; t++) {
            x   = positionXAtTime(x0, vx0, thrustAngleRadians, t + 1);
            y   = positionYAtTime(y0, vy0, thrustAngleRadians, t + 1);
            dx  = velocityXAtTime(vx0, thrustAngleRadians, t + 1);
            dy  = velocityYAtTime(vy0, thrustAngleRadians, t + 1);
            speed = mag(dx, dy);


            std::cout << t + 1 << "s " << std::fixed << std::setprecision(2)
                << "x,y:("    << x  << ", " << y  << ")m "   << std::setw(10)
                << "dx,dy:("  << dx << ", " << dy << ")m/s " << std::setw(10)
                << "speed:"   << speed << "m/s " << std::setw(10)
                << "angle:"   << deg(thrustAngleRadians) << "deg\n";
        }

        // prompt new angle
        if (y > 0)
            thrustAngleRadians = promptFloat(
                "What is the new angle of the LM where 0 is up (degrees)?");

        // next 5 seconds
        i += 5;
    }

    return YEET;
}
