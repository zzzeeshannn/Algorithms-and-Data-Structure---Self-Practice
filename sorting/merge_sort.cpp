//
// Created by zee on 6/3/21.
//

#include <iostream>
#include <string>

void print_array(int defaultArray[], int len){
    std::cout << "The array is: ";
    for (int i = 0; i < len-1; i++) {
        std::cout << defaultArray[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int defaultArray[], int start_itr, int mid_itr, int end_itr){
    // Getting the size for the two subarrays we declare later
    int size1 = mid_itr - start_itr + 1;
    int size2 = end_itr - mid_itr;

    // Declaring two subarrays
    int subArray1[size1];
    int subArray2[size2];

    // Copying the elements from the main array to the subarrays
    for (int i = 0; i < size1; i++) {
        subArray1[i] = defaultArray[start_itr + i];
    }
    for (int j = 0; j < size2; j++) {
        subArray2[j] = defaultArray[mid_itr + 1 + j];
    }

    // Defining initial indices of the subarrays
    int i = 0;
    int j = 0;
    int k = start_itr;

    while (i < size1 && j < size2){
        if (subArray1[i] <= subArray2[j]){
            defaultArray[k] = subArray1[i];
            i++;
        }
        else{
            defaultArray[k] = subArray2[j];
            j++;
        }
        k++;
    }

    while (i < size1){
        defaultArray[k] = subArray1[i];
        i++;
        k++;
    }
    while (j < size2){
        defaultArray[k] = subArray2[j];
        j++;
        k++;
    }
}

void merge_sort(int defaultArray[], int start_itr, int end_itr){
    if (start_itr >= end_itr){
        return;
    }

    int mid_itr = start_itr + (end_itr - start_itr)/2;

    merge_sort(defaultArray, start_itr, mid_itr);
    merge_sort(defaultArray, mid_itr + 1, end_itr);
    merge(defaultArray, start_itr, mid_itr, end_itr);
}

int main(){
// Defining the array here
    int defaultArray[] = {11, 45, 67, 35, 42, 89, 7, 29, 38, 47, 56};
// Getting the size of the array
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
// Sanity Check
    std::cout << "The length of the array is: " << arrayLength << std::endl;
// Defining required variables here
    int start_itr = 0;
    int end_itr = arrayLength - 1;
// Printing the array before sorting
    print_array(defaultArray, arrayLength);
// Calling the sort function
    merge_sort(defaultArray, start_itr, end_itr);
// Printing the array after sorting
    print_array(defaultArray, arrayLength);
}
