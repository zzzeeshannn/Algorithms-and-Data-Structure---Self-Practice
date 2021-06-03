//
// Created by zee on 6/3/21.
//

#include <iostream>

void bubblesort(int defaultArray[], int len){
    std::cout << "------Sorting the array------" << std::endl;
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (defaultArray[j] > defaultArray[j+1]){
                int temp = defaultArray[j+1];
                defaultArray[j+1] =  defaultArray[j];
                defaultArray[j] = temp;
            }
        }
    }
}

void print_array(int defaultArray[], int len){
    std::cout << "The array is: ";
    for (int i = 0; i < len-1; i++) {
        std::cout << defaultArray[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    // Defining the array here
    int defaultArray[] = {11, 45, 67, 35, 42, 89, 7, 29, 38, 47, 56};
    // Getting the size of the array
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Sanity Check
    std::cout << "The length of the array is: " << arrayLength << std::endl;
    // Printing the array before sorting
    print_array(defaultArray, arrayLength);
    // Calling the sort function
    bubblesort(defaultArray, arrayLength);
    // Printing the array after sorting
    print_array(defaultArray, arrayLength);
}