//
// Created by zee on 5/30/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Vector declaration
    vector<int> defaultVec;

    // Adding some random values to the vector
    // push_back is used to enter values in the vector
    for (int i = 1; i < 7; ++i) {
        defaultVec.push_back(i*10);
    }

    // Understanding iterators
    // begin() and end() returns an iterator to the first and last element of the vector
    std::cout << "The elements in the vector are: ";
    for (auto i = defaultVec.begin(); i != defaultVec.end() ; ++i) {
        std::cout << *i << " ";
    }
    // rbegin() and rend() returns a reverse iterator to the last and first element of the vector
    std::cout << "\nThe elements in the vector in the reversed order are: ";
    for (auto i = defaultVec.rbegin(); i != defaultVec.rend() ; ++i) {
        std::cout << *i << " ";
    }

    // Understanding size, max_size, resize, shrink_to_fit
    std::cout << "\nSize of the vector is: " << defaultVec.size();
    // resizing
    defaultVec.resize(5);
    std::cout << "\nThe elements in the vector after resizing to " << defaultVec.size() << " are: ";
    for (auto i = defaultVec.begin(); i != defaultVec.end() ; ++i) {
        std::cout << *i << " ";
    }
    // shrinking
    defaultVec.shrink_to_fit();
    std::cout << "\nThe elements in the vector after shrinking are: ";
    for (auto i = defaultVec.begin(); i != defaultVec.end() ; ++i) {
        std::cout << *i << " ";
    }

    // Understanding element access
    // Reference operator
    std::cout << "\nElement access at position 1 using reference operator: " << defaultVec[1];
    // "at" operator
    std::cout << "\nElement access at position 2 using at operator: " << defaultVec.at(2);
    // front function
    std::cout << "\nElement at the front of the vector: " << defaultVec.front();
    // end function
    std::cout << "\nElement at the end of the vector: " << defaultVec.back();

    // Understanding modifiers
    // assign()
    defaultVec.assign(5,100);
    std::cout << "\nThe elements in the vector after assign function are: ";
    for (auto i = defaultVec.begin(); i != defaultVec.end() ; ++i) {
        std::cout << *i << " ";
    }
    // push_back()
    defaultVec.push_back(69);
    std::cout << "\nThe elements in the vector after push_back function are: ";
    for (auto i = defaultVec.begin(); i != defaultVec.end() ; ++i) {
        std::cout << *i << " ";
    }
    // pop_back()
    defaultVec.pop_back();
    std::cout << "\nThe elements in the vector after pop_back function are: ";
    for (auto i = defaultVec.begin(); i != defaultVec.end() ; ++i) {
        std::cout << *i << " ";
    }
    // emplace
    defaultVec.emplace(defaultVec.begin(), 99);
    std::cout << "\nThe elements in the vector after emplace function are: ";
    for (auto i = defaultVec.begin(); i != defaultVec.end() ; ++i) {
        std::cout << *i << " ";
    }
}