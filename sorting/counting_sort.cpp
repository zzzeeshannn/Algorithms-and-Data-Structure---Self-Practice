//
// Created by zee on 6/4/21.
//

#include <iostream>
#include <string>
#define RANGE 255

void print_array(int defaultArray[], int len){
    std::cout << "The array is: ";
    for (int i = 0; i < len; i++) {
        std::cout << defaultArray[i] << " ";
    }
    std::cout << std::endl;
}

int counting_sort(int defaultArray[], int arrayLength){

    int countArray[RANGE] = {0};
    int finalArray[RANGE];

    for (int i = 0; i < arrayLength; i++) {
        ++countArray[defaultArray[i]];
    }
    // print_array(countArray, RANGE);

    for (int i = 1; i < RANGE; i++) {
        countArray[i] += countArray[i-1];
    }
    for (int i = 0; i < arrayLength; i++) {
        int itr = countArray[defaultArray[i]];
        finalArray[itr-1] = defaultArray[i];
        --countArray[defaultArray[i]];
    }
    for (int i = 0; i < arrayLength; i++) {
        defaultArray[i] = finalArray[i];
    }
}

int main(){
    // Defining the array here
    int defaultArray[] = {11, 45, 67, 35, 42, 89, 7, 29, 38, 47, 56};
    // Getting the size of the array
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Sorted array
    int sortedArray[arrayLength];
    // Sanity Check
    std::cout << "The length of the array is: " << arrayLength << std::endl;
    // Printing the array before sorting
    print_array(defaultArray, arrayLength);
    // Calling the sort function
    counting_sort(defaultArray, arrayLength);
    // Printing the array after sorting
    print_array(defaultArray, arrayLength);
}
