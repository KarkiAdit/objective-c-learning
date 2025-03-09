//  ArrayBasics.h

#ifndef ArrayBasics_h
#define ArrayBasics_h

void nsArrayBasics(void){
    // Create four NSDate objects
    NSDate *now = [NSDate date];
    NSDate *tomorrow = [now dateByAddingTimeInterval:86400]; // 1 day is 86400 seconds.
    NSDate *dayAfterTomorrow = [tomorrow dateByAddingTimeInterval:86400];
    NSDate *yesterday = [now dateByAddingTimeInterval:-86400];
    // Create an NSArray object with these elements
    // NSArray *datesList = [NSArray arrayWithObjects:yesterday, now, tomorrow, dayAfterTomorrow, nil];
    NSArray *datesList = @[yesterday, now, tomorrow, dayAfterTomorrow]; // Same as above.
    // Print the size of NSArray list
    NSUInteger size = [datesList count];
    NSLog(@"Size of date list is %lu.", size);
    // Print tht elements in the list
    for (NSUInteger i = 0; i < size; i++){
        NSLog(@"%lu: %@", i + 1, datesList[i]);
    }
}

void nsMutableArrayBasics(void){
    // Create an empty NSMutable array object
    NSMutableArray *randomStrings = [NSMutableArray array];
    // Store four strings inside an array
    for (NSUInteger i = 0; i < 4; i++){
        // Create a random string
        NSString *curr = [NSString stringWithFormat:@"%lu", i];
        // Store this string inside the array
        [randomStrings addObject:curr];
    }
    // Print all the random strings
    for (NSString *randomString in randomStrings){
        NSLog(@"%@", randomString);
    }
}

#endif

