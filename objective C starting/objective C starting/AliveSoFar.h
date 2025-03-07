// AliveSoFar.h

#ifndef AliveSoFar_h
#define AliveSoFar_h

@class AliveSoFar; // Class definition

#import <Foundation/Foundation.h>

typedef struct {
    int mm;
    int dd;;
    int yyyy;
    int birthSec;
    int birthMin;
    int birthHour;
} DateOfBirth;

// The main logic
double aliveSoFarInSeconds(DateOfBirth *dob){
    // Create a NSDateComponents object
    NSDateComponents *comps = [[NSDateComponents alloc] init];
    [comps setDay:dob->dd];
    [comps setMonth:dob->mm];
    [comps setYear:dob->yyyy];
    [comps setSecond:dob->birthSec];
    [comps setMinute:dob->birthMin];
    [comps setHour:dob->birthHour];
    // Create NSCalendar object with Gregarian calendar
    NSCalendar *g = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    // Create an NSDate object for the Date of Birth using the Gregorian Calendar
    NSDate *dateOfBirth = [g dateFromComponents:comps];
    // Get the current date
    NSDate *now = [NSDate date];
    // Calculate the alive time
    double diff =  [now timeIntervalSinceDate:dateOfBirth];
    return diff;
};

#endif
