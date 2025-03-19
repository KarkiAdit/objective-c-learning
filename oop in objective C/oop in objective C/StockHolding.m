#import "StockHolding.h"

#import "Foundation/Foundation.h"

@implementation StockHolding

@synthesize purchasePrice, currentPrice, numberOfShares;

- (float) costInDollars
{
    return [self purchasePrice] * [self numberOfShares];
}

- (float) valueInDollars
{
    return [self currentPrice] * [self numberOfShares];
}

- (void) getStockObjPtr:(NSMutableArray *)objArray
{
    [objArray addObject:self];
}

@end
