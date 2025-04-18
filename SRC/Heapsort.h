// all functions in this class will use heapsort
#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include<vector>
#include<queue>
using namespace std;


class Heapsort {
    map<string, string> cities;
    // Custom comparator for the timeliness (Timeliness of care national comparison)
public:
    struct CustomCompare {
        unordered_map<string, int> priority = {
            {"Above the National average", 0},
            {"Same as the National average", 1},
            {"Below the National average", 2},
            {"Not Available", 3}
        };

        bool operator()(const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) const {
            // Compare based on the second string (the timeliness value)
            return priority.at(a.second) > priority.at(b.second);  // Use ">" for max-heap behavior
        }
    };

    void createcities(map<string, vector<string>> rawdata, string city);
    void heapsortcities();
};