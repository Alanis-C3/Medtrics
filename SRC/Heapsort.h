// all functions in this class will use heapsort
#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include<vector>
#include<queue>
#include <chrono>
using namespace std;
class Heap {
    float elapsedTime = 0.0f;
public:
    // comparator for hospital overall rating
    struct RatingComp {
        unordered_map<string, int> ratPriority = {
            {"5", 0},
            {"4", 1},
            {"3", 2},
            {"2", 3},
            {"1", 4},
            {"Not Available", 5}
        };
        bool operator()(const pair<string, string>& a, const pair<string, string>& b) const {
            // using find() to find ratings a and b
            auto itA = ratPriority.find(a.second);
            auto itB = ratPriority.find(b.second);
            int pA = (itA != ratPriority.end()) ? itA->second : ratPriority.at("Not Available");
            int pB = (itB != ratPriority.end()) ? itB->second : ratPriority.at("Not Available");
            // return higher overall ratings first after finding
            return pA > pB;
        }
    };
    void stateSort(multimap<string, vector<string>> rawdata, const string& state) {
        auto start = chrono::high_resolution_clock::now();
        // minHeap to have the best ratings returned first
        priority_queue<pair<string, string>, vector<pair<string, string>>, RatingComp> heap;
        for (const auto& x : rawdata) {
            const vector<string>& key = x.second;
            // index of state is 4
            if (key.size() > 8 && key[2] == state) {
                // index of hospital overall rating is 8
                string rating = key[8];
                heap.push(make_pair(x.first, rating));
            }
        }
        cout << "Hospitals in state " << state << " by overall rating:\n";
        while (!heap.empty()) {
            cout << heap.top().first << " - Rating: " << heap.top().second << endl;
            heap.pop();
        }
        auto stop = chrono::high_resolution_clock::now();
        // using default to get seconds
        chrono::duration<double> duration = stop - start;
        cout << "Run time: " << duration.count()  << " seconds" << endl;
    }
    float getTime() {
        return elapsedTime;
    }
};
class Heapsort {
    map<string, string> cities;
    // Custom comparator for the timeliness (Timeliness of care national comparison)
    float elapsedTime = 0.0f;
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