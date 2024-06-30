// Problem:
// Given two crystal balls that will break if dropped from high
// enough distance, determine the exact spot in which it will break
// in the most optimized way.

// My misconception: Exact spot meaning find the floor at which the
// crystal balls breaks.

// Visualized in an array: (F) -> False, (T) -> True
// [T, T, T, T, F, F, F] -> T is where it will always break.
// 0...................N

#include <iostream>

bool breakable_heights[100] = {false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               false, false, false, false, false, false, false, false, false, false,
                               true, true, true, true, true, true, true, true, true, true};

int find_breakable_height()
{
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

   // Jump until we find the breaking point.1
   for (i = 0; i <= arraySize; i += jumpHeight)
   {
      steps++;
      if (breakable_heights[i] == true)
      {
         break;
      }
   }

   // We don't need to track where the array found an approximate
   // breaking point since the loop will terminate either at or before
   // the approximate.
   i -= jumpHeight;

   // From the last jumped height to the end.
   for (int j = arraySize; j <= i; j++)
   {
      steps++;
      if (breakable_heights[j] == true)
      {
         std::cout << steps << std::endl;
         std::cout << j << std::endl;
         return j;
      }
   }

   return -1;
}