//
//  main.m
//  oop in objective C
//
//  Created by Aditya Karki on 3/19/25.
//
#import "Person.h"
#import "StockHolding.h"
#import "ForeignStockHolding.h"
#import "Employee.h"
#import "Asset.h"
#import <Foundation/Foundation.h>

// All test functions
void testPersonBMICalculation(void);
void testStockHolding(void);
void testForeignStockHolding(void);
void testEmployeeWithAssets(void);
void testMutableDictionaryWithEmployee(void);

// Helper functions
float randomFloatInRange(float min, float max);
int randomIntInRange(int min, int max);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Call all test functions
        testPersonBMICalculation();
        testStockHolding();
        testForeignStockHolding();
        testEmployeeWithAssets();
        testMutableDictionaryWithEmployee();
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

void testForeignStockHolding(void){
    NSMutableArray<ForeignStockHolding *> *foreighStockObjects = [[NSMutableArray alloc] init];
    // Create three foreign stocks objects
    for (int i = 0; i < 3; i++){
        ForeignStockHolding *stock = [[ForeignStockHolding alloc] init];
        // Set random values between 0 to 100 for currentPrice, purchasePrice
        float purchaseValue = randomFloatInRange(0.0, 100.0);
        NSLog(@"Purchase value in Pound Sterling = %f", purchaseValue);
        [stock setPurchasePrice:purchaseValue];
        float currentValue = randomFloatInRange(0.0, 100.0);
        NSLog(@"Current value in Pound Sterling = %f", currentValue);
        [stock setCurrentPrice:currentValue];
        // Set random values between 0 to 1000 for total shares
        [stock setNumberOfShares:randomIntInRange(0, 1000)];
        // Assume the stock was in Pound Sterling
        [stock setConversionRate:1.3];
        // Access the object and store inside stocks
        [foreighStockObjects addObject:stock];
    }
    // Print the random foregin stock holding values
    for (ForeignStockHolding *storedStock in foreighStockObjects){
        float totalPurchaseCost = [storedStock costInDollars];
        float totalValue = [storedStock valueInDollars];
        NSLog(@"Purchase Price = $%f, Current Price = $%f,  Number of Shares = %d", [storedStock purchasePrice], [storedStock currentPrice], [storedStock numberOfShares]);
        NSLog(@"Total Purchase Cost = $%f, Total Value = $%f", totalPurchaseCost, totalValue);
    }
}

void testEmployeeWithAssets(void) {
    // Create an array of Employee objects
    NSMutableArray *employees = [[NSMutableArray alloc] init];
    for (int i = 0; i < 10; i++){
        // Create an instance of Employee objects
        Employee *person = [[Employee alloc] init];
        // Give the instance variable interesting values
        [person setWeightInKilos:90+i];
        [person setHeightInMeters:1.8-i/10.0];
        [person setEmployeeID:i];
        // Put the employee in the employees array
        [employees addObject:person];
    }
    // Create an array to store all the assets
    NSMutableArray *allAssets = [[NSMutableArray alloc] init];
    // Create 10 assets
    for (int i = 0; i < 10; i++){
        // Create an asset
        Asset *asset = [[Asset alloc] init];
        // Give it an interesting label
        NSString *currentLabel = [NSString stringWithFormat:@"Laptop %d", i];
        [asset setLabel:currentLabel];
        [asset setResaleValue:i * 17];
        // Get a random number between 0 and 9 inclusive
        NSUInteger randomIndex = randomIntInRange(0, 9);
        // Find that employee
        Employee *randomEmployee = [employees objectAtIndex:randomIndex];
        // Assign the asset to the employee
        [randomEmployee addAssetsObject:asset];
        [allAssets addObject:asset];
    }
    // Sort employees based on value of assets, employeedID
    NSSortDescriptor *voa = [NSSortDescriptor sortDescriptorWithKey:@"valueOfAssets" ascending:YES];
    NSSortDescriptor *ei = [NSSortDescriptor sortDescriptorWithKey:@"employeeID" ascending:YES];
    [employees sortUsingDescriptors:[NSArray arrayWithObjects:voa, ei, nil]];
    NSLog(@"Employees: %@", employees);
    NSLog(@"Giving up ownership of one employee");
    [employees removeObjectAtIndex:5];
    NSLog(@"all Assets:  %@", allAssets);
    // Filter assets with value more than $120
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"holder.valueOfAssets > 120"];
    NSArray *toBeReclaimed = [allAssets filteredArrayUsingPredicate:predicate];
    NSLog(@"to be Reclaimed: %@", toBeReclaimed);
    toBeReclaimed = nil;
    NSLog(@"Giving up owndership of arrays");
    allAssets = nil;
    employees = nil;
}

void testMutableDictionaryWithEmployee(void) {
    NSMutableArray *employees = [[NSMutableArray alloc] init];
    NSArray *titles = @[@"CEO", @"CTO", @"CFO", @"Infrastructural Head", @"PM", @"Software Engineer"];
    NSMutableDictionary *executives = [[NSMutableDictionary alloc] init];
    for (int i = 0; i < 10; i++) {
        Employee *person = [[Employee alloc] init];
        [person setWeightInKilos:90 + i];
        [person setHeightInMeters:1.8 - i / 10.0];
        [person setEmployeeID:i];
        [employees addObject:person];

        if (i < 5) {
            [executives setObject:person forKey:titles[i]];
        } else {
            // Create a unique key like "Software Engineer 1", "Software Engineer 2", ...
            NSString *key = [NSString stringWithFormat:@"Software Engineer %d", i - 4];
            [executives setObject:person forKey:key];
        }
    }
    NSLog(@"executives: %@", executives);
    executives = nil;
    employees = nil;
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
