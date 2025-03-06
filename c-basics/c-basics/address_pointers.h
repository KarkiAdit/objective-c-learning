#ifndef ADDRESS_POINTERS_H
#define ADDRESS_POINTERS_H
#define _USE_MATH_DEFINES
#include <stdio.h>

void addressPointersBasics(void){
    // Populate a random int value
    int i = 190;
    // Get the address of i
    // Note: variable name should start with *
    int *addressOfI = &i;
    // Read value at the address
    int valueOfI = *addressOfI;
    // Print both values
    printf("Value of i: %d\n", i);
    printf("Value of i from pointer: %d\n", valueOfI);
    printf("Print the pointer of i: %p\n", addressOfI);
    printf("Print the address of pointer of i: %p\n", &addressOfI);
    printf("An integer is %zu bytes\n", sizeof(i));
    printf("A pointer is  %zu bytes\n", sizeof(addressOfI));
}

int getFloatMemorySize(void){
    float *num;
    num = NULL; // Initialize to null pointer
    float PI = M_PI; // Store PI, i.e 3.142857
    if (!num){
        // Store the pointer to PI
        num = &PI;
    }
    printf("The value num points to: %f\n", *num);
    printf("The size of pointer to PI is %zu bytes\n", sizeof(num));
    return sizeof(*num);
}

#endif
