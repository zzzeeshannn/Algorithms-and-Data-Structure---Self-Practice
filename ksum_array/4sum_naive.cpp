//
// Created by zee on 5/30/21.
//

#include <iostream>

using namespace std;

int count(int defaultArray[], int arrayLength, int target){
    // This function is used to iterate over the array and count all possible combinations that add up to the target sum
    // In the naive approach, we just traverse through the array, checking if the sum equals to the target sum.
    // If so, we increase the counter

    // Initializing the iterator and a variable to hold the sum
    int totalCount = 0;
    int sum = 0;
    // Initializing the indices iterators
    int i, j, k, l;

    // Traversing through the array
    // Fixing the first number
    for (int i = 0; i < arrayLength; i++) {
        // Fixing the second number
        for (int j = i+1; j < arrayLength; j++) {
            // Fixing the third number
            for (int k = j+1; k < arrayLength; k++) {
                // Fixing the fourth number
                for (int l = k+1; l < arrayLength; l++) {
                    sum = defaultArray[i] + defaultArray[j] + defaultArray[k] + defaultArray[l];
                    if (sum == target){
                        totalCount++;
                    }
                }
            }
        }
    }

    return totalCount;
}

int main(){
    // Defining an array here
    int defaultArray[] = {4, 5, 3, 1, 2, 4};
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Target sum for quadruples
    int target = 13;
    // Testing
    //std::cout << "Size of the array is: " << sizeof(defaultArray)/ sizeof(defaultArray[0]) << endl;

    int totalPairs = count(defaultArray, arrayLength, target);

    std::cout << "The total pairs of quadruples meeting the target is: " << totalPairs << endl;
}
