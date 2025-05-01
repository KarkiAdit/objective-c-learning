#import "StockHolding.h"
#import <Foundation/Foundation.h>

@interface ForeignStockHolding : StockHolding

@property float conversionRate;
@property BOOL isConvertedToDollars;

- (instancetype) init; // Custom Initializer
- (void) convertToDollars;
- (float) costInDollars;
- (float) valueInDollars;

@end
