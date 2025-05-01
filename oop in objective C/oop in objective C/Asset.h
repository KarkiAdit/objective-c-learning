#import <Foundation/Foundation.h>
@class Employee;

@interface Asset : NSObject

@property (strong) NSString *label;
@property unsigned int resaleValue;
@property (weak) Employee *holder;

@end
