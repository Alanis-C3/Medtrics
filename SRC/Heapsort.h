// all functions in this class will use heapsort
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#pragma once
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