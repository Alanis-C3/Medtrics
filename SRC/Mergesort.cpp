// cpp file for all functions using merge sort
// using logic from discussion slide 12 of module 8 sorting
#include <iostream>
#include "Mergesort.h"
using namespace std;
// merge state functions:
// recursive helper function, merge sorting state in alphabetical order
void Merge::mergeState(vector<pair<string, vector<string>>> &hos, int start, int mid, int end) {
  vector<pair<string, vector<string>>> temp;
  int i = start, j = end + 1;
  while (i <= start && j <= end) {
    // 4 since state is the 4th index in the csv
    if (hos[i].second[4] < hos[j].second[4]) {
      temp.push_back(hos[i++]);
    }else{
      temp.push_back(hos[j++]);
    }
  }
  while (i <= start && j <= end) {
    temp.push_back(hos[i++]);
    temp.push_back(hos[j++]);
  }
  // copying merged information back to temp vector
  for (int k = i; k <= end; k++) {
    hos[k] = temp[k-1];
  }
}
// recursive helper for mergeState function
void Merge::mergesortState(vector<pair<string, vector<string>>> &hos, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergesortState(hos, start, mid);
    mergesortState(hos, mid + 1, end);
    mergeState(hos, start, mid, end);
  }
}
// public merge function
void Merge::stateSort(vector<pair<string, vector<string>>> &hos) {
  if (!hos.empty()) {
    mergesortState(hos, 0, hos.size() - 1);
  }
}
// merge rating functions:
// recursive helper function, merge sorting rating in descending order
void Merge::mergeRate(vector<pair<string, vector<string>>> &hos, int start, int mid, int end) {
  vector<pair<string, vector<string>>> temp;
  int i = start, j = mid + 1;
  while (i <= mid && j <= end) {
    int rowi = hos[i].second[10].empty() ? 0 : stoi(hos[i].second[10]);
    int rowj = hos[j].second[10].empty() ? 0 : stoi(hos[j].second[10]);
    if (rowi > rowj) {
      temp.push_back(hos[i++]);
    }else{
      temp.push_back(hos[j++]);
    }
  }
  while (i <= mid && j <= end) {
    temp.push_back(hos[i++]);
    temp.push_back(hos[j++]);
  }
  for (int k = i; k <= end; k++) {
    hos[k] = temp[k-1];
  }
}
// recursive helper for ratingSort
void Merge::mergesortRate(vector<pair<string, vector<string>>> &hos, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergesortRate(hos, start, mid);
    mergesortRate(hos, mid + 1, end);
    mergeRate(hos, start, mid, end);
  }
}
// public ratingSort function
void Merge::ratingSort(vector<pair<string, vector<string>>> &hos) {
  if (!hos.empty()) {
    mergesortRate(hos, 0, hos.size() - 1);
  }
}