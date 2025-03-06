#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <stdio.h>
#include <math.h>

void passByReference(void){
    float PI = 3.14;
    double intPart;
    float floatPart = modf(PI, &intPart);
    printf("integer part = %.0f, fraction part = %.2f\n", intPart, floatPart);
}

void cartesianToPolar(float x, float y, double *thetaPtr, double *radiusPtr){
    if (radiusPtr)
        *radiusPtr = sqrt(x * x + y * y);
    else
        printf("No pointer found to store radius value.");
    // Avoid divide by 0 error
    if (y == 0) {
        *thetaPtr = 90;
        return;
    }
    if (thetaPtr)
        *thetaPtr = tan(x / y);
    else
        printf("No pointer found to store theta value.");
}

#endif
