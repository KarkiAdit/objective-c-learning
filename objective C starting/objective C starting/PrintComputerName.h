//  PrintComputerName.h

#ifndef PrintComputerName_h
#define PrintComputerName_h

#import <Foundation/Foundation.h>

void nsStringBasics(void){
    // Sample string generation
    NSString *lament = @"Why me?";
    // Get the number of characters in these strings
    NSUInteger size = [lament length];
    NSLog(@"The length is %d.", (int) size);
    // Check for equality of two strings
    NSString *lamentCopy = [NSString stringWithFormat:@"Why me%c", '?']; // Use formatting
    if ([lament isEqual:lamentCopy]){
        NSLog(@"Both are same. %@ and %@.", lament, lamentCopy);
    }
}

void printComputerName(void) {
    // Create a pointer to NSHost object
    NSHost *hostComputerPtr = [NSHost currentHost];
    // Get the localized name of your system
    NSString *localName = [hostComputerPtr localizedName];
    // Print the computer name
    NSLog(@"You have named you computer as %@.", localName);
}

#endif


