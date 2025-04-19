// all functions in this class will use heapsort
#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include<vector>
#include<queue>
using namespace std;

class Heap {
    //float time;
public:
    // struct to help with stateSort function
    struct StateComp {
        bool operator()(const pair<string, string>& a, const pair<string, string>& b) const {
            // alphabetical order for states
            return a.second > b.second;
        }
    };
    void stateSort(multimap<string, vector<string>> rawdata, string state) {
        priority_queue<pair<string, string>, vector<pair<string, string>>, StateComp> heap;
        for (const auto& record : rawdata) {
            if (record.second[4] == state) {
                // hospital name & state (index is 4)
                heap.push(make_pair(record.first, record.second[4]));
            }
        }
        while (!heap.empty()) {
            cout << heap.top().first << " - State: " << heap.top().second << endl;
            heap.pop();
        }
    }
    struct RatingComp {
        bool operator()(const pair<string, string>& a, const pair<string, string>& b) const {
            // maxHeap to return higher rating
            return stoi(a.second) < stoi(b.second);
        }
    };
    // struct to help with ratingSort function
    void ratingSort(multimap<string, vector<string>> rawdata, string rating) {
        priority_queue<pair<string, string>, vector<pair<string, string>>, RatingComp> heap;
        for (const auto& record : rawdata) {
            if (!record.second[10].empty() && record.second[10] == rating) {
                // hospital name and rating (index is 10)
                heap.push(make_pair(record.first, record.second[10]));
            }
        }
        while (!heap.empty()) {
            cout << heap.top().first << " - Rating: " << heap.top().second << endl;
            heap.pop();
        }
    }
};
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

    void heapsortcities(multimap<string, vector<string>> rawdata, string city);
    float gettime();
};