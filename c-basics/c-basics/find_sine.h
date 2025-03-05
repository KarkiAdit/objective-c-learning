// Given angle in degree or radian, find trigonometric sine for that angle.
// Return the answer in 3 d.p.
#ifndef FIND_SINE_H
#define FIND_SINE_H
#include <stdio.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES
#include <math.h>

// Helper functions
double degreesToRadians(double deg);
double radiansToDegrees(double rad);
double roundToNPlaces(double num, int n);

// The main logic to find trigonometric sine
double findTrigonometricSine(double angle, bool isRad);

double degreesToRadians(double deg) {
    // Just to make sure we have the correct PI value
    printf("The Mathematical PI: %f\n", M_PI);
    double rad = (deg / 180.0) * M_PI;
    return rad;
}

double radiansToDegrees(double rad){
    // Just to make sure we have the correct PI value
    printf("The Mathematical PI: %f\n", M_PI);
    double deg = (rad * 180.0) / M_PI;
    return deg;
}

double roundToNPlaces(double num, int n){
    double factor = (n == 0) ? 1.0 : pow(10.0, n);
    return round(num * factor) / factor;
}

double findTrigonometricSine(double angle, bool isRad) {
    angle = isRad ? angle : degreesToRadians(angle);
    double sineValue = sin(angle);
    return roundToNPlaces(sineValue, 3); // Round to 3 decimal places.
}

#endif

