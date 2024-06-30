### **Bubble Sort**
```c++
// This algorithm has (n + 1)(n / 2) or dropping constants, has
// n ^ 2 time complexity runtime.

// Runtime can be summed by:
// (n) + (n - 1) + (n - 2) + (n - 3) ... (n - n)
// This is a triangular number, where the formula is:
// (n ^ 2 + n) / 2 == (n(n + 1)) / 2

// Notes:
// Every pass through, the largest element within that range
// is always sorted correctly at the end.

// [ ] Indicates the largest sorted element
// (Indicates the range of each iteration)
// Length: 6 Elements, 6 Passes
// {7, 5, 3, 9, 8, 2}
// Iteration 1: (5, 3, 7, 8, 2, [9])
// Iteration 2: (3, 5, 7, 2, [8]), 9
// Iteration 3: (3, 5, 2, [7]), 8, 9
// Iteration 4: (3, 2, [5]), 7, 8, 9
// Iteration 5: (2, [3]), 5, 7, 8, 9
// Iteration 6: ([2]), 3, 5, 7, 8, 9

#include <iostream>

void bubbleSort(int array[], int arraySize) {
    for (int i = arraySize; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int var = array[j];
                array[j] = array[j + 1];
                array[j + 1] = var;
            }
        }
    }
}

int main() {
    int array[6] = {7, 5, 3, 9, 8, 2};
    
    int arraySizeInBytes = sizeof(array);
    int intSizeInBytes = sizeof(int);
    int arraySize = arraySizeInBytes / intSizeInBytes;
    
    bubbleSort(array, arraySize);
    
    for (int i = 0; i < arraySize; i++) {
        std :: cout << array[i];
    }

    return 0;
}
```