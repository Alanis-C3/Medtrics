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
  // function takes in state variable from main
    void stateSort(vector<pair<string, vector<string>>> &hos, const string& state) {
      auto temp = [](const pair<string, vector<string>> &a, const pair<string, vector<string>> &b) {
        // state is 4th index of hospita csv
        return a.second[4] > b.second[4];
      };
      // using priority queue for heapsort
      priority_queue<pair<string, vector<string>>, vector<pair<string, vector<string>>>, decltype(temp)> minHeap(temp);
      for (const auto &x : hos) {
        if (x.second[4] == state) {
          minHeap.push(x);
        }
      }
      hos.clear();
      // state and hospital name information
      while (!minHeap.empty()) {
        hos.push_back(minHeap.top());
        minHeap.pop();
      }
    }
  // function takes rating variable from main
    void ratingSort(vector<pair<string, vector<string>>> &hos, const string& rating) {
      auto temp = [](const pair<string, vector<string>> &a, const pair<string, vector<string>> &b) {
        int rowa = a.second[10].empty() ? 0 : stoi(a.second[10]);
        int rowb = b.second[10].empty() ? 0 : stoi(b.second[10]);
        // returning higher rating first
        return rowa < rowb;
      };
      // using priority queue for heapsort
      priority_queue<pair<string, vector<string>>, vector<pair<string, vector<string>>>, decltype(temp)> maxHeap(temp);
      for (const auto &x : hos) {
        if (!x.second[10].empty() && x.second[10] == rating) {
          maxHeap.push(x);
        }
        hos.clear();
        // rating and hospital name information
        while (!maxHeap.empty()) {
          hos.push_back(maxHeap.top());
          maxHeap.pop();
        }
      }
    }
};
class Heapsort {
  float time;
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