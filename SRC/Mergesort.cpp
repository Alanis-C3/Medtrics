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

void Mergesort::createcitiesmerge(multimap<string, vector<string>> rawdata, string city) {
  for (const auto& key : rawdata) {
    if (key.second[1] == city) {
      cityData.push_back({key.first, key.second[20]}); //put hosital in vector container since merge sort works best with arrays/vectors
    }
  }
}
void Mergesort::mergecity(vector<pair<string, string>>& arr, int left, int mid, int right) {
  //logic from discussion slides for module 8 , slide 13
  int leftSize = mid - left + 1;
  int rightSize = right - mid;

  vector<pair<string, string>> leftArr(leftSize), rightArr(rightSize);

  for (int i = 0; i < leftSize; i++) {
    leftArr[i] = arr[left + i];
  }
  for (int i = 0; i < rightSize; i++) {
    rightArr[i] = arr[mid + 1 + i];
  }

  int leftPtr = 0, rightPtr = 0;
  int mergedPtr = left;

  while (leftPtr < leftSize && rightPtr < rightSize) {
    int leftPriority = priority[leftArr[leftPtr].second];
    int rightPriority = priority[rightArr[rightPtr].second];

    if (leftPriority <= rightPriority) {
      arr[mergedPtr++] = leftArr[leftPtr++];
    }
    else {
      arr[mergedPtr++] = rightArr[rightPtr++];
    }
  }

  while (leftPtr < leftSize) {
    arr[mergedPtr++] = leftArr[leftPtr++];
  }
  while (rightPtr < rightSize) {
    arr[mergedPtr++] = rightArr[rightPtr++];
  }
}

  void Mergesort::mergesortcities(vector<pair<string, string>>& arr, int left, int right){
    if (left < right) {
      int mid = left + (right - left) / 2;
      mergesortcities(arr, left, mid);
      mergesortcities(arr, mid + 1, right);
      mergecity(arr, left, mid, right);
    }
  }

void Mergesort::mergesort_cities(){
    if (!cityData.empty()) {
      mergesortcities(cityData, 0, cityData.size() - 1);
    }
  for (const auto& [hospital, timeliness] : cityData) { //print hospitals in order after mergesort
    cout << hospital << " - " << timeliness << endl;
  }
}

