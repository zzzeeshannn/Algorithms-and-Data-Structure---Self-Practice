//
// Created by zee on 5/30/21.
//

# include <iostream>
# include <unordered_map>
# include <unordered_set>

using namespace std;

int main(){

    // Declaration using unordered map
    std::unordered_map<std::string, int> grades;

    // Different ways to insert
    grades["Stark"] = 100;
    grades.insert({"Banner", 99});
    grades.insert(std::pair<std::string, int>{"Rogers", 12});

    // Search and change
    grades["Rogers"] = 6;

    // Iterate
    for (const std::pair<std::string, int> &temp : grades){
        std::cout << "Name: " << temp.first << std::endl;
        std::cout << "Grade: " << temp.second << std::endl << std::endl;
    }

    // Declaration using unordered map
    std::unordered_set<std::string> shield;

    // Insert
    shield.insert("Coulson");
    shield.insert(std::string{"Fury"});

    // Iterate
    std::cout << "\nShield Members: \n";
    for (const std::string &temp2 : shield){
        std::cout << "Name: " << temp2 << std::endl;
    }
}