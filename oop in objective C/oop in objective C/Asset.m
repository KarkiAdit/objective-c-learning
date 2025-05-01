#import "Asset.h"
#import "Employee.h"

@implementation Asset

@synthesize label, resaleValue, holder;

- (NSString *)description
{
    // Is holder non-nil?
    if ([self holder]) {
        return [NSString stringWithFormat:@"<%@: $%u, assigned to %@>", [self label], [self resaleValue], [self holder]];
    } else {
        return [NSString stringWithFormat:@"<%@: $%u unassigned>", [self label], [self resaleValue]];
    }
}

- (void) dealloc
{
    NSLog(@"deallocating %@", self);
}

@end
