//
// Created by zee on 5/31/21.
//

#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

int findElements(int defaultArray[], int arrayLength, int k){
    int ratio = arrayLength/k;
    std::unordered_map<int, int> record;
    for (int i = 0; i < arrayLength; i++) {
        record[defaultArray[i]]++;
    }
    std::cout << "\nThe elements with count greater are: " << std::endl;
    for (auto temp : record){
        if (temp.second > ratio){
            std::cout << temp.first << " ";
        }
    }
}

int main(){
    // Defining the array here
    int defaultArray[] = {3, 1, 2, 2, 2, 1, 4, 3, 3};
    // Getting the size of the array
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Division number
    int k = 4;
    // Sanity check
    std::cout << "Length of the array is: " << arrayLength << std::endl;
    // Sorting the array
    std::sort(defaultArray, defaultArray+arrayLength);
    // Checking the sorted array
    std::cout << "Elements of the sorted array are: ";
    for (int i = 0; i < arrayLength; ++i) {
        std::cout << defaultArray[i] << " ";
    }
    findElements(defaultArray, arrayLength, k);
}