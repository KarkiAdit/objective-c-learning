#import "Person.h"

@implementation Person

@synthesize heightInMeters, weightInKilos;

- (float) bodyMassIndex
{
    // Similar to the following implmentation
    // return weightInKilos / (heightInMeters * heightInMeters);
    float h = [self heightInMeters]; // However, this is a good encapsulation using getters and setters.
    return [self weightInKilos] / (h * h);
}

- (void) addObjToArray:(NSMutableArray *)theArray{
    [theArray addObject:self];
}

@end
