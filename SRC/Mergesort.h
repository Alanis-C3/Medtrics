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
    void mergesortState(vector<pair<string, vector<string>>> & hos, int start, int end);
    void mergeState(vector<pair<string, vector<string>>> & hos, int start, int mid, int end);
    // recursive helper functions for mergesort (overall rating)
    void mergesortRate(vector<pair<string, vector<string>>> & hos, int start, int end);
    void mergeRate(vector<pair<string, vector<string>>> & hos, int start, int mid, int end);
  public:
    // merge sort for state
    void stateSort(vector<pair<string, vector<string>>> & hos);
    // merge sort for overall rating
    void ratingSort(vector<pair<string, vector<string>>> & hos);

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