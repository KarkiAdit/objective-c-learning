#import "Person.h"
@class Asset;

@interface Employee : Person
{
    int employeeID;
    NSMutableSet *assets;
}

@property int employeeID;
- (void) addAssetsObject: (Asset *)a;
- (unsigned int) valueOfAssets;

@end
