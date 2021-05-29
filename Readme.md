# A self study and practice repository for Data Structures

## Topic 1: Arrays 
### Key Points: 
1. In C, arrays have fixed size. 
### Advantages: 
1. Allows storing multiple data items (of the same type) using a single name.
2. Allow random access to elements of the array. 
3. Better cache locality. (How does it affect performance? : Provides "Locality of Reference". When an array is defined, chunk of memory equivalent to its size on declaration is loaded into the cache upon first access which makes it quick to access array elements.)
### Disadvantages: 
1. Cannot change the size of the array once declared. (Vectors have an advantage over arrays here as they do not require to mention the size at the time of declaration and can be dynamically resized.)
### Primary Applications: 
1. Used in implementing data structures like Queue, Stacks, Hash tables etc. 
### Interesting observations: 
1. C++ does not throw an error for index-out-of-bounds.
2. Array stored in continuous memory locations.
### Programs/Problems solved for arrays: 
1. Array Rotation
- Method 1: Using "temp" array [Time and Space Complexity: O(n), O(d) where d is the rotation of the number of elements in the array]
- Method 2: Rotate one by one [Time and Space Complexity: O(n*d), O(1) where d is the rotation of the number of elements in the array]
- Method 3: Juggling Problem [Time and Space Complexity: O(n), O(1)]
- Method 4: Block Swap
- Method 5: Reversal Algorithm

## Topic 2: Linked Lists
## Topic 3: Stack
## Topic 4: Queue