// This has o(n) runtime since it walks through the array step by
// step until the element is found.

int array[6] = {7, 5, 3, 9, 8, 2};

int arraySizeInBytes = sizeof(array);
int intSizeInBytes = sizeof(int);
int arraySize = arraySizeInBytes / intSizeInBytes;

int linear_search(int element)
{
   // Iterate through each element in the array
   // until we find the element.
   for (int i = 0; i < arraySize; i++)
   {
      if (array[i] == element)
      {
         return i;
      }
   }
   return -1;
}