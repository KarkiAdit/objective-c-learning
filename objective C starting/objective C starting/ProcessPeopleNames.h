//  ProcessPeopleNames.h
#ifndef ProcessPeopleNames_h
#define ProcessPeopleNames_h

#import <Foundation/Foundation.h>

NSString *getFilePathForResource(NSString *fileName, NSString *fileExtension) {
    NSString *filePath = [[NSBundle mainBundle] pathForResource:fileName ofType:fileExtension];
    if (!filePath) { // If pathForResource fails, try direct resource path
        NSString *resourcePath = [[NSBundle mainBundle] resourcePath];
        filePath = [resourcePath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.%@", fileName, fileExtension]];
    }
    return filePath;
}

NSMutableArray *listAllNames(void){
    // Print the App Bundle Path
    NSString *bundlePath = [[NSBundle mainBundle] bundlePath];
    NSLog(@"Bundle Path: %@", bundlePath);
    // List All Files in the Bundle to Check if names.txt Exists
    NSError *error;
    NSArray *files = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:bundlePath error:&error];
    if (error) {
        NSLog(@"Error fetching bundle contents: %@", error.localizedDescription);
    } else {
        NSLog(@"Files in bundle: %@", files);
    }
    // Get File Path
    NSString *filePath = getFilePathForResource(@"peopleNames", @"txt");
    // Stores all names
    NSMutableArray *names = nil;
    // Read names and store everything as a single huge string
    if (filePath) {
        NSString *fileContents = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:&error];
        if (error) {
            NSLog(@"Error reading file: %@", error.localizedDescription);
            // In case of error, store some random names
            names = [@[@"Sonia", @"zoe", @"soNia", @"zlatan", @"ronaldo", @"Messi", @"messi", @"ZOE", @"zOE", @"Zlatan", @"Ronaldo"] mutableCopy
            ];
        } else {
            // Store individual names from file based on newline
            names = [[fileContents componentsSeparatedByString:@"\n"] mutableCopy];
            NSLog(@"File contents: %@", fileContents);
        }
    } else {
        NSLog(@"ERROR: names.txt file not found in bundle!");
    }
    return names;
}

NSMutableArray* processNames(void) {
    @autoreleasepool{
        // Get all names from the file
        NSMutableArray *names = listAllNames();
        // Update processedNames untill
        // Note: Every name is non-case sensitively unique.
        // Note: Every name is sorted.
        int idx = 0;
        NSUInteger size = [names count];
        while (idx < size - 1) {
            NSUInteger curr_next = idx + 1;
            while (curr_next < size){
                // Find the fixed element at idx position
                NSString *name_at_idx = names[idx];
                // Check if current element matches the element at fixed index
                NSString *curr = names[curr_next];
                NSComparisonResult compResult = [name_at_idx caseInsensitiveCompare:curr];
                if (compResult == NSOrderedSame){
                    NSLog(@"%@ and %@ are equal.", name_at_idx, curr);
                    // Remove the current element
                    [names removeObjectAtIndex:curr_next];
                    // Reduce the size
                    size--;
                } else if (compResult == NSOrderedDescending){
                    NSLog(@"%@ comes after %@.", name_at_idx, curr);
                    // Swap these values
                    NSString *temp;
                    temp = names[idx];
                    names[idx] = names[curr_next];
                    names[curr_next] = temp;
                    curr_next++;
                } else {
                    NSLog(@"%@ comes before %@.", name_at_idx, curr);
                    curr_next++;
                }
            }
            idx++;
        }
        return names;
    }
}

#endif

