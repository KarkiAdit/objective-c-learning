//
//  main.m
//  oop in objective C
//
//  Created by Aditya Karki on 3/19/25.
//
# import "Person.h"
# import "StockHolding.h"
#import <Foundation/Foundation.h>

// All test functions
void testPersonBMICalculation(void);
void testStockHolding(void);

// Helper functions
float randomFloatInRange(float min, float max);
int randomIntInRange(int min, int max);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Call all test functions
        testPersonBMICalculation();
        testStockHolding();
    }
    return 0;
}

void testPersonBMICalculation(void){
    // Create an instance of Person
    Person *person = [[Person alloc] init];
    // Give the instance variables some values
    [person setWeightInKilos:72];
    [person setHeightInMeters:1.7272];
    // Calculate the BMI
    float bmi = [person bodyMassIndex];
    NSLog(@"Person has a BMI of %f", bmi);
}

void testStockHolding(void){
    // Create a pointer to instances of StockHolding objects
    NSMutableArray<StockHolding *> *stocks = [[NSMutableArray alloc] init];
    // Create three stocks objects
    for (int i = 0; i < 3; i++){
        StockHolding *stock = [[StockHolding alloc] init];
        // Set random values between 0 to 100 for currentPrice, purchasePrice
        [stock setPurchasePrice:randomFloatInRange(0.0, 100.0)];
        [stock setCurrentPrice:randomFloatInRange(0.0, 100.0)];
        // Set random values between 0 to 1000 for total shares
        [stock setNumberOfShares:randomIntInRange(0, 1000)];
        // Access the object and store inside stocks
        [stock getStockObjPtr:stocks];
    }
    // Print the random stock holding values
    for (StockHolding *storedStock in stocks){
        float totalPurchaseCost = [storedStock costInDollars];
        float totalValue = [storedStock valueInDollars];
        NSLog(@"Purchase Price = %f, Current Price = %f,  Number of Shares = %d", [storedStock purchasePrice], [storedStock currentPrice], [storedStock numberOfShares]);
        NSLog(@"Total Purchase Cost = %f, Total Value = %f", totalPurchaseCost, totalValue);
    }

}

// Function to generate a random float within a specified range
float randomFloatInRange(float min, float max) {
    float random = ((float)arc4random() / UINT32_MAX); // Normalized random number between 0 and 1
    return min + random * (max - min);
}

// Function to generate a random integer within a specified range
int randomIntInRange(int min, int max) {
    return arc4random_uniform(max - min + 1) + min;
}
