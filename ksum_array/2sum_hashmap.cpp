//
// Created by zee on 5/31/21.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int count_onepasshash(int defaultArray[], int arrayLength, int target){
    int totalCount = 0;
    std::unordered_map<int, int> record;

    for (int i = 0; i < arrayLength; ++i) {
        auto found = record.find(target - defaultArray[i]);
        if (found != record.end()){
            totalCount += found->second;
        }
        record[defaultArray[i]]++;
    }
    return totalCount;
}


int count_twopasshash(int defaultArray[], int arrayLength, int target){
    int totalCount = 0;

    // Loop to add entries to the hashmap
    std::unordered_map<int, int> records;
    for (int i = 0; i < arrayLength; i++) {
        records[defaultArray[i]]++;
    }

    // Loop that checks if the pair is present
    for (int i = 0; i < arrayLength; i++) {
        int remain = target - defaultArray[i];
        totalCount += records[remain];
        std::cout << remain;
    }
    totalCount /= 2;
    return totalCount;
}

int main(){
    // Defining an array here
    int defaultArray[] = {2, 7, 5, 4, 11, 15, -2};
    int arrayLength = sizeof(defaultArray)/ sizeof(defaultArray[0]);
    // Target sum for pair
    int target = 9;

    int totalPairs = count_twopasshash(defaultArray, arrayLength, target);
    std::cout << "The total number of pairs meeting (from two pass hash) the target is: " << totalPairs << endl;

    int totalPairs2 = count_onepasshash(defaultArray, arrayLength, target);
    std::cout << "The total number of pairs meeting (from one pass hash) the target is: " << totalPairs2 << endl;
}
