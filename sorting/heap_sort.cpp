//
// Created by zee on 6/4/21.
//

#include <iostream>

using namespace std;

void print_array(int defaultArray[], int len){
    std::cout << "The array is: ";
    for (int i = 0; i < len; i++) {
        std::cout << defaultArray[i] << " ";
    }
    std::cout << std::endl;
}

int heapArray(int defaultArray[], int arrayLength, int i){
    // Defining the iterators here
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;


    if(left < arrayLength && defaultArray[left] < defaultArray[smallest]){
        smallest = left;
    }
    if(right < arrayLength && defaultArray[right] < defaultArray[smallest]){
        smallest = right;
    }

    if (smallest != i){
        swap(defaultArray[i], defaultArray[smallest]);
        heapArray(defaultArray, arrayLength, smallest);
    }
}

int heapSort_ascending(int defaultArray[], int arrayLength){
    // Main sorting function

    // Reordering the array
    for (int i = (arrayLength/2)-1; i >= 0; i--) {
        heapArray(defaultArray, arrayLength, i);
    }

    for (int i = arrayLength - 1; i > 0; i--) {
        swap(defaultArray[0], defaultArray[i]);
        heapArray(defaultArray, arrayLength, 0);
    }
}

int main(){
    // Defining the array here
    int defaultArray[] = {12, 45, 67, 23, 89, 3, 35};
    int defaultArray2[] = {12, 45, 67, 23, 89, 3, 35};
    // Size of the array
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Printing the array for sanity check
    print_array(defaultArray, arrayLength);
    // Calling sort here
    heapSort_ascending(defaultArray, arrayLength);
    // Check after sorting
    print_array(defaultArray, arrayLength);
}