// all functions in this class will use heapsort
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#pragma once
using namespace std;

class Heap {
  public:
    void stateSort(vector<pair<string, vector<string>>> &hos) {
      auto temp = [](const pair<string, vector<string>> &a, const pair<string, vector<string>> &b) {
        // state is 4th index of hospita csv
        return a.second[4] > b.second[4];
      };
      // using priority queue for heapsort
      priority_queue<pair<string, vector<string>>, vector<pair<string, vector<string>>>, decltype(temp)> minHeap(temp);
      for (const auto &x : hos) {
        minHeap.push(x);
      }
      hos.clear();
      // state and hospital name information
      while (!minHeap.empty()) {
        hos.push_back(minHeap.top());
        minHeap.pop();
      }
    }
    void ratingSort(vector<pair<string, vector<string>>> &hos) {
      auto temp = [](const pair<string, vector<string>> &a, const pair<string, vector<string>> &b) {
        int rowa = a.second[10].empty() ? 0 : stoi(a.second[10]);
        int rowb = b.second[10].empty() ? 0 : stoi(b.second[10]);
        // returning higher rating first
        return rowa < rowb;
      };
      // using priority queue for heapsort
      priority_queue<pair<string, vector<string>>, vector<pair<string, vector<string>>>, decltype(temp)> maxHeap(temp);
      for (const auto &x : hos) {
        maxHeap.push(x);
      }
      hos.clear();
      // rating and hospital name information
      while (!maxHeap.empty()) {
        hos.push_back(maxHeap.top());
        maxHeap.pop();
      }
    }
};