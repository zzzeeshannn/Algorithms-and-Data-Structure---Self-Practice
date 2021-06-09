# A self study and practice repository for Data Structures

## Topic 1: Arrays 
### Programs/Problems solved for arrays:
1. Array Rotation
- Method 1: Using "temp" array [Time and Space Complexity: O(n), O(d) where d is the rotation of the number of elements in the array]
- Method 2: Rotate one by one [Time and Space Complexity: O(n*d), O(1) where d is the rotation of the number of elements in the array]
- Method 3: Juggling Problem [Time and Space Complexity: O(n), O(1)]
- Method 4: Block Swap
- Method 5: Reversal Algorithm

2. ksum-array
Problem Statement- To find if sum of k-elements in the array is equal to a given target.
   - Naive Approach
   - Hashmaps: Two approaches 
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


## Topic 2: Linked Lists
Linked lists are a linear data structure which consists of two parts: a data field to store data and a reference to the next node. 
Unlike arrays, the nodes are not saved in contiguous memory locations. 
#### Advantages over arrays
1. Provides the option of dynamic size allotment as compared to arrays that require to mention a fixed size on declaration. [Exception of dynamically allotted arrays.]
2. Inserting a new element in arrays is expensive as you'll need to shift all the elements to accomodate a single new entry. 
#### Disadvantages over arrays 
1. Does not allow for random access. We'll have to traverse through the entire list of nodes. 
2. Need to allocate extra space for a pointer with every data module. 
3. One of the advantages of using arrays was cache locality. Since the nodes are not saved in contiguous memory locations, it's not cache friendly. (Arrays are faster in accessing elements.)
### Singly Linked Lists 
### Circular Linked Lists 
### Doubly Linked Lists 
## Topic 3: Vectors  
## Topic 4: Hashmap in C++
### Using Unordered Map: 
#### Programs:
1. Given an array of size n and a number k, find all elements that appear more than n/k times
### Using Unordered Sets: 
## Topic 5: Stack
## Topic 6: Queue
Queue is a linear data structure, like Stacks. However, Stack uses LIFO order whereas Queue uses FIFO. 
The main functions in a Queue are: 
1. Enqueue
2. Dequeue
3. Front 
4. Rear
### Priority Queue 
Priority queue is an extension of Queue where every element of the queue has a priority associated with it. 
The element with the highest priority is popped out first.