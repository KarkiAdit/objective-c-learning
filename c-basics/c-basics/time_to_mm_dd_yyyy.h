#ifndef TIME_TO_MM_DD_YYYY_H
#define TIME_TO_MM_DD_YYYY_H

#include <stdio.h>
#include <time.h>

// Define the MMDDYYYY format
typedef struct {
    int date;
    int month;
    int year;
} DateFormat;

// Calculate the current time
void calculateCurrentTime(struct tm *now){
    long secondsSince1900 = time(NULL);
    printf("It has been %ld seconds since 1900.\n", secondsSince1900);
    localtime_r(&secondsSince1900, now);
}

// The main logic
void currentTimeToMMDDYYYY(DateFormat *mmDDYYYY){
    // Create a Time Stucture to hold current time.
    struct tm now;
    // Store the current time.
    calculateCurrentTime(&now);
    // Update Date format
    mmDDYYYY->date = now.tm_mday;
    mmDDYYYY->month = now.tm_mon + 1;
    mmDDYYYY->year = now.tm_year + 1900;
}

#endif
