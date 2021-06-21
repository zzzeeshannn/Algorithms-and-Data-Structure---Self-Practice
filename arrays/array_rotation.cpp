//
// Created by zee on 5/29/21.
//
#include <iostream>

using namespace std;

// Function to rotate the elements of the array by one

// This is used in Method 2
int left_rotate(int rotationArray[], int len){

    // Saving the first element in a temporary variable
    int temp = rotationArray[0];

    for (int i = 0; i < len-1; i++) {
        rotationArray[i] = rotationArray[i+1];
    }
    rotationArray[len-1] = temp;
}

// Function to find the Greatest Common Divisor(GCD) of two numbers
// This is used in Method 3
int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    else {
        gcd(b, a % b);
    }
}

// Function to rotate the elements in the array towards left in sets with relation to GCD
// This is used in Method 3
int set_left_rotation(int rotationArray[], int len, int rotation){

    // Finding the GCD of the length of the array and number of rotations required to divide it into sets
    int gcdNumbers = gcd(len, rotation);
    for (int i = 0; i < gcdNumbers; i++) {
        int temp = rotationArray[i];
        int x = i;
        while(1){
            int y = rotation + x;
            if (y >= len){
                y = y - len;
            }
            if (y == i){
                break;
            }
            rotationArray[x] = rotationArray[y];
            x = y;
        }
        rotationArray[x] = temp;
    }
}

int main(){
    // Defining a random array
    int firstArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int secondArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int thirdArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // METHOD 1: USING A TEMPORARY ARRAY
    // Number of elements to be rotated
    int rotation;
    std::cout << "Enter the number of elements you'd like to rotate(<10): ";
    std::cin >> rotation;

    // Defining a temporary array
    int temp[10];

    std::cout << "\n" << "-------- METHOD 1 --------";
    // Printing the original array
    std::cout << "\nThe original array is: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << " " << firstArray[i] ;
    }
    // Storing the entered number of elements in a temporary array
    for (int i = 0; i < rotation; i++) {
        temp[i] = firstArray[i];
    }

    // Shifting the rest of the elements in the array
    for (int i = 0; i < 10; i++) {
        if (i >= rotation){
            firstArray[i-rotation] = firstArray[i];
        }
    }

    // Restoring the elements saved in the temporary array
    int x = rotation;
    for (int i = 0; i < rotation; i++) {
        firstArray[10-x] = temp[i];
        x -= 1;
    }

    // Printing the array after rotation
    std::cout << "\n" << "The rotated array is: ";
    for (int i = 0; i < 10; i++) {
        std::cout << " " << firstArray[i] ;
    }

    // METHOD 2: ROTATE ONE BY ONE
    std::cout << "\n\n" << "-------- METHOD 2 --------";
    std::cout << "\n" << "The second array is: ";
    for (int i = 0; i < 10; i++) {
        std::cout << " " << secondArray[i] ;
    }

    // rotating left by the number of rotations required
    for (int i = 0; i < rotation; ++i) {
        left_rotate(secondArray, 10);
    }

    std::cout << "\n" << "The second array after rotation is: ";
    for (int i = 0; i < 10; i++) {
        std::cout << " " << secondArray[i] ;
    }

    // METHOD 3: JUGGLING ALGORITHM
    std::cout << "\n\n" << "-------- METHOD 3 --------";
    std::cout << "\n" << "The third array is: ";
    for (int i = 0; i < 10; i++) {
        std::cout << " " << thirdArray[i] ;
    }

    // Calling the rotation function - juggling algorithm
    set_left_rotation(thirdArray, 10, rotation);
    std::cout << "\n" << "The third array after rotation is: ";
    for (int i = 0; i < 10; i++) {
        std::cout << " " << secondArray[i] ;
    }
}