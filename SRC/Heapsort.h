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
    //float time;
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
            // minHeap for higher overall rating
            return ratPriority.at(a.second) > ratPriority.at(b.second);
        }
    };
    void stateSort(multimap<string, vector<string>> rawdata, const string& state) {
        auto start = chrono::high_resolution_clock::now();
        // minHeap to have the best ratings returned first
        priority_queue<pair<string, string>, vector<pair<string, string>>, RatingComp> heap;
        for (const auto& x : rawdata) {
            const vector<string>& key = x.second;
            // index of state is 4
            if (key[6] == state) {
                // index of hospital name is 1
                string hospitalName = key[3];
                // index of hospital overall rating is 11
                string rating = key[12];
                heap.push(make_pair(hospitalName, rating));
            }
        }
        cout << "Hospitals in state " << state << " sorted by overall rating:\n";
        while (!heap.empty()) {
            cout << heap.top().first << " - Rating: " << heap.top().second << endl;
            heap.pop();
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Run time: " << duration.count() / 1e6 << " seconds" << endl;
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