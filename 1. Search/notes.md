# **Search**

### **Linear Search**

```c++
// This has o(n) runtime since it walks through the array step by
// step until the element is found. 

int array[6] = {7, 5, 3, 9, 8, 2};

int arraySizeInBytes = sizeof(array);
int intSizeInBytes = sizeof(int);
int arraySize = arraySizeInBytes / intSizeInBytes;

int linear_search(int element) {
    // Iterate through each element in the array
    // until we find the element.
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}
```

### **Binary Search**
```c++
// Binary search has o(log n) runtime since it divides and
// conquers until the element is found. The array continues
// to be halved repeatedly.

// Ex. Array Size: 60
// Step 1: Divide -> (60 / 2) = 30 -> Difference: 30
// Step 2: Divide -> (30 / 2) = 15 -> Difference: 15
// Step 3: Divide -> (15 / 2) = 7  -> Difference: 8
// ....

// Binary search requires a sorted array. Apply write once,
// read often to reduce the time complexity added by sorting.
int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int arraySizeInBytes = sizeof(array);
int intSizeInBytes = sizeof(int);
int arraySize = arraySizeInBytes / intSizeInBytes;

int binary_search(int element) {
    int left = 0; 

    // Offset by 1 since arrays start at 0.
    int right = arraySize - 1;

    // Keeps track of where we divide our array.
    int middle;

    // Side note for what happens if you just set
    // left or right as middle without shifting:
    // An array of size 8 finding element 8
    // 1, 2, 3, (4), 5, 6, 7, 8 -> Middle: 4
    // 4, 5, (6), 7, 8          -> Middle: 6
    // 6, (7), 8                -> Middle: 7
    // (7), 8                   -> Middle: 7
    // (7), 8                   -> Middle: 7
    // ....... (forever)
    // Hence never terminating. Unlike shifting:
    // 1, 2, 3, (4), 5, 6, 7, 8 -> Middle: 4
    // 5, (6), 7, 8             -> Middle: 6
    // (7), 8                   -> Middle: 7
    // 8                      -> Terminated (Left > Right)

    // Continue searching until our left/right has gone
    // has gone out of bounds. We use <= over < so that 
    // the entire space is searched.
    while(left <= right){
        middle = left + ((right - left) / 2);
        // Element is on the right side after dividing.
        // Divide and restrict our search bounds after the middle.
        if (element > array[middle]) {
            left = middle + 1;

        // Element is on the left side after dividing.
        // Divide and restrict our search bounds before the middle.
        } else if (element < array[middle]) { 
            right = middle - 1;

        // The current middle element is equal to the
        // element we found. Return that index.
        } else {
            return middle;
        }
    }

    // Return -1 that no element was found.
    return -1;
}
```

### Two Crystal Ball Problem
```c++
// Problem:
// Given two crystal balls that will break if dropped from high
// enough distance, determine the exact spot in which it will break
// in the most optimized way.

// My misconception: Exact spot meaning find the floor at which the
// crystal balls breaks.

// Visualized in an array: (F) -> False, (T) -> True
// [T, T, T, T, F, F, F] -> T is where it will always break.
// 0...................N

bool breakable_heights[100] = {false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               
                               true, true, true, true, true, true, true, true, true, true};

int find_breakable_height() {
    int arraySizeInBytes = sizeof(breakable_heights);
    int booleanSizeInBytes = sizeof(bool);
    int arraySize = arraySizeInBytes / booleanSizeInBytes;

    // We use sqrt(n):
    // Array size of 100:
    // Jump array: sqrt(100) = 10 (jumps)
    // 10 (jumps) ^ 2 = 100 (back to where we started)
    // We've reduced o(n) to sqrt(n)
    int jumpHeight = sqrt(arraySize);
    int steps = 0;
    int i = 0;

    // Jump until we find the breaking point.
    for(i = 0; i <= arraySize; i += jumpHeight) {
        steps ++;
        if (breakable_heights[i] == true) {
            break;
        }
    }

    // We don't need to track where the array found an approximate
    // breaking point since the loop will terminate either at or before
    // the approximate.
    i -= jumpHeight;

    // From the last jumped height to the end.
    for(int j = arraySize; j <= i; j++) {
        steps++;
        if (breakable_heights[j] == true) {
            std::cout << steps << std::endl;
            std::cout << j << std::endl;
            return j;
        }
    }

    return -1;
}

```
