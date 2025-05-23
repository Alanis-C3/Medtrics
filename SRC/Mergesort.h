// merge sort location for all functions
#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;

//class mergesort{
//
//  // these two functions would use merge sort
//  void bestHopsital(string state, map<>); // edited later
//  void bestTime();
//  }
class Merge {
  private:
    // recursive helper functions for mergesort (State)
    float elapsedTime = 0.0f;
    void mergesortstates(vector<pair<string, string>>& arr, int left, int right);
    void mergestate(vector<pair<string, string>>& arr, int left, int mid, int right);
  public:
  // using same rating priority logic in heap sort for state
    unordered_map<string, int> ratPriority = {
      {"5", 1},
      {"4", 2},
      {"3", 3},
      {"2", 4},
      {"1", 5},
      {"Not Available", 6}
    };
    // merge sort for state
    void stateSort(multimap<string, vector<string>> rawdata, const string& state);
    void mergesortChrono();
    float getTime() {
      return elapsedTime;
    }

};

class Mergesort {
  float time;
  //map<string, string> cities;
  vector<pair<string, string>> cityData;  // hospital name -> timeliness string (for sorting)
  void mergesortcities(vector<pair<string, string>>& arr, int left, int right);
  void mergecity(vector<pair<string, string>>& arr, int left, int mid, int right);
public:
  // Custom comparator for the timeliness (Timeliness of care national comparison)
  unordered_map<string, int> priority = {
    {"Above the National average", 0},
    {"Same as the National average", 1},
    {"Below the National average", 2},
    {"Not Available", 3}
  };
  void createcitiesmerge(multimap<string, vector<string>> rawdata, string city);
  void mergesort_cities(); // calls private merge sort, so that main does not have parameters to take in
  float gettime();
};