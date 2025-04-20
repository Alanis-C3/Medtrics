// cpp file for all functions using merge sort
// using logic from discussion slide 12 of module 8 sorting
#include <iostream>
#include <chrono> // for time
#include "Mergesort.h"
using namespace std;
// merge state functions:
// public function to sort States by merge sort
vector<pair<string, string>> sData;
void Merge::stateSort(multimap<string, vector<string>> rawdata, const string& state) {
// data cleaning
  sData.clear();
  for (const auto& x : rawdata) {
    const vector<string>& vals = x.second;
    if (vals.size() > 8 && vals[2] == state) {
      string rating = vals[8];
      // printings N/A if no ratings
      if (ratPriority.find(rating) == ratPriority.end()) {
        rating = "N/A";
      }
      sData.push_back({x.first, rating});
    }
  }
}
// helper function 1 where rating priorities are being compared
void Merge::mergestate(vector<pair<string, string>>& arr, int left, int mid, int right) {
// defining left size
  int leftS = mid - left + 1;
  // defining right size
  int rightS = right - mid;
  vector<pair<string, string>> leftArr(leftS), rightArr(rightS);
  for (int i = 0; i < leftS; i++) {
    leftArr[i] = arr[left + i];
  }
  for (int i = 0; i < rightS; i++) {
    rightArr[i] = arr[mid + 1 + i];
  }
  int leftPtr = 0, rightPtr = 0, mergedPtr = left;
  // divide & conquer logic
  while (leftPtr < leftS && rightPtr < rightS) {
    int leftPri = ratPriority.count(leftArr[leftPtr].second)
        ? ratPriority[leftArr[leftPtr].second] : ratPriority["N/A"];
    int rightPri = ratPriority.count(rightArr[rightPtr].second)
        ? ratPriority[rightArr[rightPtr].second] : ratPriority["N/A"];
    if (leftPri <= rightPri) {
      arr[mergedPtr++] = leftArr[leftPtr++];
    } else {
      arr[mergedPtr++] = rightArr[rightPtr++];
    }
  }
  while (leftPtr < leftS) {
    arr[mergedPtr++] = leftArr[leftPtr++];
  }
  while (rightPtr < rightS) {
    arr[mergedPtr++] = rightArr[rightPtr++];
  }
}
// helper function 2
void Merge::mergesortstates(vector<pair<string, string>>& arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergesortstates(arr, left, mid);
    mergesortstates(arr, mid + 1, right);
    mergestate(arr, left, mid, right);
  }
}
// public function (+ chrono information)
void Merge::mergesortChrono() {
  auto start = chrono::high_resolution_clock::now();
  if (!sData.empty()) {
    mergesortstates(sData, 0, sData.size() - 1);
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<float> duration = end - start;
  elapsedTime = duration.count();
  for (const auto& [hospital, state] : sData) {
    cout << hospital << " - " << state << endl;
  }
  cout << "Run time: " << elapsedTime << " seconds" << endl;
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
  auto start = chrono::high_resolution_clock::now();
    if (!cityData.empty()) {
      mergesortcities(cityData, 0, cityData.size() - 1);
    }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<float> duration = end - start; // finds time it took to sort hospitals

  for (const auto& [hospital, timeliness] : cityData) { //print hospitals in order after mergesort
    cout << hospital << " - " << timeliness << endl;
  }
  time = duration.count();
  cout << "Run time: " << time << " seconds" << endl;
}

float Mergesort::gettime() {
  return time;
}


