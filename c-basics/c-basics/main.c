#include "find_third_angle.h"
#include "find_sine.h"
#include <stdio.h>
#include <stdbool.h>

// All test functions
void testFindThirdAngle(void);
void testFindSine(void);

int main(int argc, const char * argv[]){
    // Test all logic written while learning
    testFindThirdAngle();
    testFindSine();
    return 0;
}

void testFindThirdAngle(void){
    float angleA = 35.0;
    float angleB = 75.0;
    bool isValidTriangle = isValidAngle(angleA) && isValidAngle(angleB) && canFormATriangle(angleA, angleB);
    isValidTriangle ? printf("The third angle is %f\n", findThirdAngle(angleA, angleB)) : printf("Not a valid triangle\n\n");
}

void testFindSine(void) {
    double angle1 = 1.5708; // 90 degrees
    printf("Finding the sine for angle in radians. Angle=%f, sine=%f\n", angle1, findTrigonometricSine(angle1, true));
    double angle2 = 180.0;
    printf("Finding the sine for angle in degrees. Angle=%f, sine=%f\n\n", angle2, findTrigonometricSine(angle2, false));
}
