#import "AliveSoFar.h"
#import "IsDayLightSavingsUsed.h"
#import "PrintComputerName.h"
#import "ArrayBasics.h"
#import "ProcessPeopleNames.h"
#import <Foundation/Foundation.h>

// All test functions
void testAliveSoFar(void);
void testIsDaylightSavingsUsed(void);
void testProcessNames(void);
void testStaticNSMutableArray(void);
void testSomeConstantsIdeas(void);

// Helper functions
NSArray* getStaticNSMutableArray(void);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Run all test logic
        testAliveSoFar();
        testIsDaylightSavingsUsed();
        printComputerName();
        nsArrayBasics();
        nsMutableArrayBasics();
        testProcessNames();
        testStaticNSMutableArray();
        testSomeConstantsIdeas();
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

void testIsDaylightSavingsUsed(void) {
    NSLog(@"Day light savings is %s used.", (isDayLightSavingsUsed() ? "": "not"));
}

void testProcessNames(void){
    NSMutableArray *processedNames = processNames();
    for (NSString *name in processedNames){
        NSLog(@"%@", name);
    }
}

void testStaticNSMutableArray(void) {
    NSArray *oddsPtr = getStaticNSMutableArray();
    NSLog(@"Print the non-mutable array here. Now it can't be changed. %@", oddsPtr);
}

NSArray* getStaticNSMutableArray(void){
    static NSMutableArray *odds = nil;
    if (!odds) {
        odds = [[NSMutableArray alloc] init];
        int i = 1;
        while ([odds count] < 30){
            [odds addObject: [NSNumber numberWithInt:i]];
            i += 2;
        }
    }
    return odds;
}

void testSomeConstantsIdeas(void) {
    NSLog(@"\u03c0 is %f", M_PI); // Comes from include and import of Foundation header file.
    NSLog(@"%d is larger", MAX(10, 12)); // Come from defined macro of Foundation header file.
    
    NSLocale *here = [NSLocale currentLocale];
    NSString *currency = [here objectForKey: NSLocaleCurrencyCode]; // NSLocaleCurrencyCode is declared as constant somewhere in header.
    NSLog(@"Money is %@", currency);
}
