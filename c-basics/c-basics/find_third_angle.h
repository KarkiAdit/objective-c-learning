// Given two angles of a triangle, calculate the third angle.
#ifndef FIND_THIRD_ANGLE_H
#define FIND_THIRD_ANGLE_H
# include <stdio.h>
# include <stdbool.h>

// Helper functions
bool isValidAngle(float x);
bool canFormATriangle(float x, float y);

// The main logic to find the third angle
float findThirdAngle(float x, float y);

bool isValidAngle(float x) {
    return x > 0.0 && x < 180.0;
}

bool canFormATriangle(float x, float y) {
    float sum = x + y;
    return isValidAngle(sum);
}

float findThirdAngle(float x, float y) {
    float angleC = 180.0 - x - y;
    return angleC;
}

#endif
