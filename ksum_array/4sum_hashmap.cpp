//
// Created by zee on 5/31/21.
//

#include <iostream>
#include <unordered_map>

using namespace std;

int countMethod1(int defaultArray[], int arrayLength, int target){
    // This function uses a hash table over the naive method to make the process more efficient
    // We iterate over the first two elements similar to the naive method
    // If so, we increase the counter

    // Initializing the iterator and a variable to hold the sum
    int finalCount = 0;
    int sum = 0;
    // Initializing the indices iterators
    int i, j, k, l;

    // Traversing through the array
    // Fixing the first number
    for (int i = 0; i < arrayLength-3; i++) {
        // Fixing the second number
        for (int j = i+1; j < arrayLength-2; j++) {
            int tempSum = defaultArray[i] + defaultArray[j];
            // Rest of the required sum
            int remain = target - tempSum;
            // Declare a hash map using unordered maps
            std::unordered_map<int, int> record;
            // Creating an entry for every element (after fixing the first two) in the map
            for (int k = j+1; k < arrayLength; k++) {
                record[defaultArray[k]]++;
            }
            // Initializing a counter
            int totalCount = 0;
            // Counting the total number of pairs
            for (int k = j+1; k < arrayLength; k++) {
                totalCount += record[remain - defaultArray[k]];
                // Considering a case when you need the same number twice
                if (remain - defaultArray[k] == defaultArray[k]){
                    totalCount--;
                }
            }
            // Adding to the final counter
            finalCount += totalCount/2;
        }
    }

    return finalCount;
}

int countMethod2(int defaultArray[], int arrayLength, int target){
    // This function uses a hash table over the naive method to make the process more efficient
    // We iterate over the first two elements similar to the naive method
    // If so, we increase the counter

    // Initializing the iterator and a variable to hold the sum
    int finalCount = 0;
    int sum = 0;
    // Initializing the indices iterators
    int i, j;

    // Defining a hash map here
    std::unordered_map<int, int> records;

    // Traversing through the array
    // Fixing the first number
    for (int i = 0; i < arrayLength-1; i++) {
        // Fixing the second number
        for (int j = i+1; j < arrayLength; j++) {
            int tempSum = defaultArray[i] + defaultArray[j];
            if (tempSum < target){
                finalCount += records[target - tempSum];
            }
        }
        for (int j = 0; j < i; j++) {
            int tempSum2 = defaultArray[i] + defaultArray[j];
            if (tempSum2 < target){
                records[tempSum2]++;
            }
        }
    }

    return finalCount;
}

int main(){
    // Defining an array here
    int defaultArray[] = {4, 5, 3, 1, 2, 4};
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Target sum for quadruples
    int target = 13;
    // Testing
    //std::cout << "Size of the array is: " << sizeof(defaultArray)/ sizeof(defaultArray[0]) << endl;

    int output1 = countMethod1(defaultArray, arrayLength, target);
    std::cout << "The total pairs of quadruples meeting the target according to Method 1 is: " << output1 << endl;

    int output2 = countMethod2(defaultArray, arrayLength, target);
    std::cout << "The total pairs of quadruples meeting the target according to Method 2 is: " << output2 << endl;
}
