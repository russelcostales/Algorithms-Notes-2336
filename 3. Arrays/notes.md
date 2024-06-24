# **Basics**

### **Array Data Structure**
When arrays are accessed, the index of an element is multiplied by the size of each element which determines how many bytes to offset from base address. 

An array has a certain number of bytes depending on how much is allocated to it. The bytes per type used to calculate the size of memory allocated to an array depends on the system architecture and the programming language.

```c++
// In C++, an integer is 4 bytes (32 bits).
// We initialize an array with an array size of 4
// The array is allocated 16 bytes (128 bits). 
int array[4];

// When an array is indexed, the computer gets the type's byte 
// size multiplied by the position to get the offset from the 
// base memory address.

// In this case, the bit's that are used are 64 - 95.
// 64 = (32 (int bit size) * 2 (position))
// 95 = (32 (int bit size) * 3 (position) - 1 (0 index offset))
// We subtract 1 bit because the exact multiplication of 3 is 
// the starting bit of the index 3 (0th index offset).
int array[2] = 3;

// This works since it takes the byte size of the array and 
// divide by the byte size of the type assigned to the array.

// Calculation:
// An integer is 4 bytes
// Size of array = 4 (int byte) * 4 (indices) = 16 (bytes)
// 16 (Size of array in bytes) / 4 (int byte size) = 4
int arraySize = sizeof(array) / sizeof(int)
```