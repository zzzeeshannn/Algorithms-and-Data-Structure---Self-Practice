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

int getLargest(int defaultArray[], int arrayLength){
    // Starting with the first element
    int largest = defaultArray[0];
    for (int i = 1; i < arrayLength; i++) {
        if(defaultArray[i] > largest){
            largest = defaultArray[i];
        }
    }
    return largest;
}

int counting_array(int defaultArray[], int arrayLength, int exponent){
    int outputArray[arrayLength];
    int countArray[10] = {0};

    for (int j = 0; j < arrayLength; j++) {
        countArray[(defaultArray[j]/exponent) % 10]++;
    }
    for (int j = 1; j < 10; j++) {
        countArray[j] += countArray[j-1];
    }
    for (int j = arrayLength - 1 ; j >= 0; j--) {
        outputArray[countArray[(defaultArray[j]/exponent) % 10] - 1] = defaultArray[j];
        countArray[(defaultArray[j]/exponent) % 10]--;
    }
    for (int j = 0; j < arrayLength; j++) {
        defaultArray[j] = outputArray[j];
    }
}

int radix_sort(int defaultArray[], int arrayLength){
    // Getting the biggest element in the array
    int largest = getLargest(defaultArray, arrayLength);
    // Sanity check
    // std::cout << "The largest element in the array is: " << largest << std::endl;
    for (int i = 1; largest/i > 0 ; i *= 10) {
        counting_array(defaultArray, arrayLength, i);
    }
}

int main(){
    // Defining the array here
    int defaultArray[] = {1, 45, 967, 835, 742, 689, 57, 429, 338, 247, 156};
    // Getting the size of the array
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Sorted array
    int sortedArray[arrayLength];
    // Sanity Check
    std::cout << "The length of the array is: " << arrayLength << std::endl;
    // Printing the array before sorting
    print_array(defaultArray, arrayLength);
    // Calling the sort function
    radix_sort(defaultArray, arrayLength);
    // Printing the array after sorting
    print_array(defaultArray, arrayLength);
}
