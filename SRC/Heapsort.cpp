// all functions use heap sort
#include "Heapsort.h"
#include <iostream>
#include <map>
#include <string>
#include<vector>
#include<queue>
using namespace std;

void Heapsort::heapsortcities(multimap<string, vector<string> > rawdata, string city) {
    priority_queue<pair<string, string>, vector<pair<string, string>>, CustomCompare> heap; //creates empty heap
    for (const auto& key : rawdata) {
        if (key.second[1] == city) {
            heap.push(make_pair(key.first, key.second[20])); // adds into heap so heap can sort after each insertation
        }
    }
    // Print sorted hospitals by timeliness
    while (!heap.empty()) {
        cout << heap.top().first << " - " << heap.top().second << endl;
        heap.pop();
    }
}



