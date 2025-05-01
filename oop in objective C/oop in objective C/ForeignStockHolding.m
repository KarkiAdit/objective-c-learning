#import "ForeignStockHolding.h"

#import <Foundation/Foundation.h>

@implementation ForeignStockHolding

- (instancetype) init {
    self = [super init];
    // Set default values
    if (self) {
        _isConvertedToDollars = NO;
        _conversionRate = 1.0;
    }
    return self;
}

- (void) convertToDollars{
    if ([self isConvertedToDollars]){
        return;
    }
    self.purchasePrice = self.purchasePrice * self.conversionRate;
    self.currentPrice = self.currentPrice * self.conversionRate;
    self.isConvertedToDollars = YES;
}

- (float) costInDollars{
    [self convertToDollars];
    return [super costInDollars];
}

- (float) valueInDollars {
    [self convertToDollars];
    return [super valueInDollars];
}

@end
