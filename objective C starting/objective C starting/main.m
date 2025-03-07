#import "AliveSoFar.h"
#import <Foundation/Foundation.h>

// All test functions
void testAliveSoFar(void);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Run all test logic
        testAliveSoFar();
    }
    return 0;
}

void testAliveSoFar(void) {
    DateOfBirth dob;
    // Set the values
    // Birthtime: 03:03:10 AM in the morning
    // Birthdate October 19, 2001
    dob.birthSec = 10;
    dob.birthMin = 3;
    dob.birthHour = 3;
    dob.dd = 19;
    dob.mm = 10;
    dob.yyyy = 2001;
    double aliveTime = aliveSoFarInSeconds(&dob);
    NSLog(@"You have been alive for %f seconds.", aliveTime);
};

