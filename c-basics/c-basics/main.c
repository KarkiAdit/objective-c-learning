#include "find_third_angle.h"
#include "find_sine.h"
#include "count_down_three.h"
#include "address_pointers.h"
#include "arguments.h"
#include "time_to_mm_dd_yyyy.h"
#include "heaps_basics.h"
#include <stdio.h>
#include <stdbool.h>

// All test functions
void testFindThirdAngle(void);
void testFindSine(void);
void testCountDownThree(void);
void testGetFloatMemorySize(void);
void testCartesianToPolar(void);
void testcurrentTimeToMMDDYYYY(void);
void testBMICalculator(void);

int main(int argc, const char * argv[]){
    // Test all logic written while learning
    testFindThirdAngle();
    testFindSine();
    testCountDownThree();
    testGetFloatMemorySize();
    testCartesianToPolar();
    testcurrentTimeToMMDDYYYY();
    testBMICalculator();
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

void testCountDownThree(void){
    countBackThree(100);
}

void testGetFloatMemorySize(void){
    printf("The size of float data in memory is %d bytes.\n", getFloatMemorySize());
}

void testCartesianToPolar(void){
    // The sample cartesian coordinates
    float x = 3.0;
    float y = 4.0;
    // The sample polar coordinates
    double radius;
    double theta;
    // Call the cartesian to polar with pointers
    cartesianToPolar(x, y, &theta, &radius);
    // Print the values
    printf("Cartesian coordinates: x = %f, y = %f\n", x, y);
    printf("Polar coordinates: theta = %f, radius = %f\n", theta, radius);
    printf("Theta converted to degrees = %f\n\n", radiansToDegrees(theta));
}

void testcurrentTimeToMMDDYYYY(void){
    DateFormat mmDDYYYY;
    currentTimeToMMDDYYYY(&mmDDYYYY);
    // Print the current month, date and year.
    printf("MM:DD:YYYY = %d:%d:%d\n\n", mmDDYYYY.date, mmDDYYYY.month, mmDDYYYY.year);
}

void testBMICalculator(void) {
    calculateBMIExample();
}
