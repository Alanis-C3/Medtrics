// merge sort location for all functions
#pragma once
#include<iostream>
#include<vector>
#include<map>
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