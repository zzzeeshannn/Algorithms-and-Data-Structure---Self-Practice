//
// Created by zee on 5/31/21.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int count(int defaultArray[], int arrayLength, int target){
    int totalCount = 0;

    for (int i = 0; i < arrayLength-1; ++i) {
        std::unordered_map<int, int> record;
        for (int j = i+1; j < arrayLength; ++j) {
            record[defaultArray[j]]++;
        }
        for (int j = i+1; j < arrayLength; ++j) {
            int tempSum = defaultArray[i] + defaultArray[j];
            int remain = target - tempSum;
            // std::cout << remain << " " << defaultArray[i] << " " << defaultArray[j] << endl;
            totalCount += record[remain];
        }
    }
    totalCount /= 2;
    return totalCount;
}


int main(){
    // Defining an array here
    int defaultArray[] = {2, 7, 5, 4, 11, 15, 1};
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Target sum for triples
    int target = 12;

    // int totalPairs = count_twopasshash(defaultArray, arrayLength, target);
    // std::cout << "The total number of pairs meeting (from two pass hash) the target is: " << totalPairs << endl;

    int totalPairs2 = count(defaultArray, arrayLength, target);
    std::cout << "The total number of pairs meeting (from one pass hash) the target is: " << totalPairs2 << endl;
}
