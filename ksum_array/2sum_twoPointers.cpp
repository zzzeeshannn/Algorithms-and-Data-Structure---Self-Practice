//
// Created by zee on 5/31/21.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int count_twoSum(int defaultArray[], int arrayLength, int target){
    // Defining the two pointers
    int low = 0;
    int high = arrayLength - 1;
    // Defining the counter that keeps a track
    int totalCount = 0;

    while (high > low){
        int tempSum = defaultArray[low] + defaultArray[high];
        if (tempSum == target){
            totalCount++;
            low++;
            high = arrayLength - 1;
        }
        else if(tempSum > target){
            high--;
        }
        else{
            low++;
        }

    }

    return totalCount;
}
int main(){
    // Defining an array here
    int defaultArray[] = {2, 7, 5, 4, 11, 15, -2};
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Target sum for pair
    int target = 9;

    // Sorting the array
    std::sort(defaultArray, defaultArray+arrayLength);
    // Printing the array for sanity check
    std::cout << "The sorted array looks like: " ;
    for (int i = 0; i < arrayLength; ++i) {
        std::cout << defaultArray[i] << " ";
    }

    int result = count_twoSum(defaultArray, arrayLength, target);
    std::cout << "\nThe total pairs that add up to the target are: " << result << endl;
}