//
// Created by zee on 5/31/21.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int count_fourSum(int defaultArray[], int arrayLength, int target){
    // Defining the counter that keeps a track
    int totalCount = 0;

    for (int i = 0; i < arrayLength - 3; i++) {
        for (int j = i+1; j < arrayLength - 2; ++j) {
            // Fixing the first element
            int remain = target - defaultArray[i] - defaultArray[j];
            // Now we apply the two pointer logic used in the 2sum algorithm to solve for remaining two elements
            // Defining the two pointers
            int low = j+1;
            int high = arrayLength - 1;
            while (high > low){
                int tempSum = defaultArray[low] + defaultArray[high];
                if (tempSum == remain){
                    totalCount++;
                    low++;
                    high = arrayLength - 1;
                }
                else if (tempSum > remain){
                    high--;
                }
                else{
                    low++;
                }
            }
        }
    }

    return totalCount;
}

int main(){
    // Defining an array here
    int defaultArray[] = {2, 7, 5, 4, 11, 15, 1};
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Target sum for pair
    int target = 18;

    // Sorting the array
    std::sort(defaultArray, defaultArray+arrayLength);
    // Printing the array for sanity check
    std::cout << "The sorted array looks like: " ;
    for (int i = 0; i < arrayLength; ++i) {
        std::cout << defaultArray[i] << " ";
    }

    int result = count_fourSum(defaultArray, arrayLength, target);
    std::cout << "\nThe total pairs that add up to the target are: " << result << endl;
}