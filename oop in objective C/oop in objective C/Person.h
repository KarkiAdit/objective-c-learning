#import <Foundation/Foundation.h>

// The class person inherits all the instance variables
// and methods defined by the class NSObject
@interface Person: NSObject
// Allow property setter and getter methods
// Similar to this
//- (void) setHeightInMeters: (float)h;
//- (void) setWeightInKilos: (int)w;
@property float heightInMeters;
@property int weightInKilos;

// This method calculates the Body Mass Index
- (float) bodyMassIndex;

// This method adds an instance to given array
- (void) addObjToArray: (NSMutableArray *)theArray;
@end
