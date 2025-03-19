#import <Foundation/Foundation.h>

@interface StockHolding: NSObject

@property float purchasePrice;
@property float currentPrice;
@property int numberOfShares;

- (float) costInDollars;
- (float) valueInDollars;
- (void) getStockObjPtr: (NSMutableArray *)objArray;

@end
