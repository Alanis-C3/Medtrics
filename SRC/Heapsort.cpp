// all functions use heap sort
#include "Heapsort.h"
#include <iostream>
#include <map>
#include <string>
#include<vector>
#include<queue>
#include <chrono> // for measureing run time of function
using namespace std;

void Heapsort::heapsortcities(multimap<string, vector<string> > rawdata, string city) {
    auto start = chrono::high_resolution_clock::now();
    priority_queue<pair<string, string>, vector<pair<string, string>>, CustomCompare> heap; //creates empty heap
    for (const auto& key : rawdata) {
        if (key.second[1] == city) {
            heap.push(make_pair(key.first, key.second[20])); // adds into heap so heap can sort after each insertation
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start; // finds time it took to sort hospitals
    // Print sorted hospitals by timeliness
    while (!heap.empty()) {
        cout << heap.top().first << " - " << heap.top().second << endl;
        heap.pop();
    }
    time = duration.count();
    cout << "Run time: " << time << " seconds" << endl;
}

float Heapsort::gettime() {
    return time;
}




