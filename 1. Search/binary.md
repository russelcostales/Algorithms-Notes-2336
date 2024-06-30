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