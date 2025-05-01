#import <Foundation/Foundation.h>

void byValue(int x) {
    x = x + 10;
    NSLog(@"Inside byValue: x = %d", x);
}

void byReference(int *x) {
    *x = *x + 10;
    NSLog(@"Inside byReference: x = %d", *x);
}

void byValueResult(int x, int *out) {
    x = x + 10;
    *out = x;
    NSLog(@"Inside byValueResult: x = %d", x);
}

// Simulating "by-name" using macro (just like C)
#define byName(expr) \
    do { \
        expr = expr + 10; \
        NSLog(@"Inside byName: expr = %d", expr); \
    } while (0)

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int a = 5, b = 5, c = 5, d = 5;
        
        NSLog(@"Initial values: a = b = c = d = 5");
        
        byValue(a);
        NSLog(@"After byValue: a = %d\n", a);
        
        byReference(&b);
        NSLog(@"After byReference: b = %d\n", b);
        
        byValueResult(c, &c);
        NSLog(@"After byValueResult: c = %d\n", c);
        
        byName(d);
        NSLog(@"After byName: d = %d\n", d);
    }
    return 0;
}
