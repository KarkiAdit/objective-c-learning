#ifndef HEAPS_BASICS_H
#define HEAPS_BASICS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float heightInMeters;
    float weightInKilos;
} BMI;

void understandHeapBasics(void) {
    // Declare a pointer to the heap
    float *startOfNums;
    // The size of buffer
    int bufferSize = 10;
    // Initialize buffer
    startOfNums = malloc(bufferSize * sizeof(float));
    // Use the buffer
    for (int i = 0; i < bufferSize; i++){
        startOfNums[i] = i + 1; // Store positive integers
        printf("The integer at %d index is %f.\n", i, startOfNums[i]);
    }
    // Clean the buffer so it can be reused
    free(startOfNums);
    // Forget memory buffer
    startOfNums = NULL;
}

float bodyMassIndex(BMI *bmiAttributes) {
    float bmi = bmiAttributes->weightInKilos / (bmiAttributes->heightInMeters * bmiAttributes->heightInMeters);
    return bmi;
}

void calculateBMIExample(void){
    BMI *bmiAttributes = (BMI *) malloc(sizeof(BMI));
    // Populate BMI Attributes
    bmiAttributes->heightInMeters = 1.7350;
    bmiAttributes->weightInKilos = 72.575;
    printf("Your BMI is: %f\n", bodyMassIndex(bmiAttributes));
    // Free up the heap
    free(bmiAttributes);
    // Nullify the BMI pointer
    bmiAttributes = NULL;
}

#endif
