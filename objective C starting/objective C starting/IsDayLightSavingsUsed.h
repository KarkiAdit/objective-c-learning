// IsDayLightSavingsUsed.h

#ifndef IsDayLightSavingsUsed_h
#define IsDayLightSavingsUsed_h

#import <Foundation/Foundation.h>

// Returns true if daylight savings is used in your Mac
bool isDayLightSavingsUsed(void){
    // Initialize a pointer to NSTimeZone object using systemTimeZone
    NSTimeZone *nsZonePtr = [NSTimeZone systemTimeZone];
    // Check if your system is using DLS
    return [nsZonePtr isDaylightSavingTime];
}

#endif
