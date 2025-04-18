// all functions in this class will use heapsort
#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include<vector>
#include<queue>
using namespace std;

using namespace std;

class Heap {
  public:
    void stateSort(const map<string, vector<string>> &hospital_data) {
      auto temp = [](const pair<string, vector<string>> &a, const pair<string, vector<string>> &b) {
        // state is 4th index of hospita csv
        return a.second[4] < b.second[4];
      };
      // using priority queue for heapsort
      priority_queue<pair<string, vector<string>>, vector<pair<string, vector<string>>>, decltype(temp)> heap(temp);
      for (const auto &x : hospital_data) {
        heap.push(x);
      }
      // printing state and hospital name information
      while (!heap.empty()) {
        const auto &[name, data] = heap.top();
        cout << "Hospital: " << name << " | State: " << data[4] << endl;
        heap.pop();
      }
    }
    void ratingSort(const map<string, vector<string>> &hospital_data) {
      auto temp = [](const pair<string, vector<string>> &a, const pair<string, vector<string>> &b) {
        int rowa = a.second[10].empty() ? 0 : stoi(a.second[10]);
        int rowb = b.second[10].empty() ? 0 : stoi(b.second[10]);
        // returning higher rating first
        return rowa < rowb;
      };
      // using priority queue for heapsort
      priority_queue<pair<string, vector<string>>, vector<pair<string, vector<string>>>, decltype(temp)> heap(temp);
      for (const auto &x : hospital_data) {
        heap.push(x);
      }
      // printing rating and hospital name information
      while (!heap.empty()) {
        const auto &[name, data] = heap.top();
        cout << "Hospital: " << name << " | Rating: " << data[10] << endl;
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

    void createcities(multimap<string, vector<string>> rawdata, string city);
    void heapsortcities();
};