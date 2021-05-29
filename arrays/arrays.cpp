//
// Created by zee on 5/29/21.
//
#include <iostream>
using namespace std;

int main(){
// Different forms of declaration of arrays
// 1. Declaration by size
int n = 2;
int firstArray[5];
int secondArray[n];

// 2. Declaration by elements
int thirdArray[] = {1, 2, 3};

// 3. Declaration by size and elements
int fourthArray[5] = {4, 5, 6};

// Checking the stored values at 3rd and 4th elements respectively
// Expected output: 6 *some random number*
printf("%d %d", fourthArray[2], fourthArray[4]);

// Checking for indexing error
// C++ does not throw index errors if you access an index > size
printf("\n%d\n", thirdArray[10]);

// Checking memory locations
std::cout << "Size of an integer: " << sizeof(int) << "\n";
for (int i = 0; i < 5; ++i) {
    std::cout << "Memory Location of fourthArray's index" << i << " is: " << &firstArray[i] << "\n";
}
}
