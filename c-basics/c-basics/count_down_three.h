#ifndef COUNT_DOWN_THREE_H
#define COUNT_DOWN_THREE_H
#include <stdio.h>

// Counts down a positive integer by 3
void countBackThree(int num) {
    while (num > 0) {
        if (num % 5 == 0)
            printf("Found one divisible by 5: %d\n", num);
        else
            printf("%d\n", num);
        num -= 3;
    }
}
#endif 

