// all functions use heap sort
#include "Heapsort.h"
#include <iostream>
#include <map>
#include <string>
#include<vector>
#include<queue>
using namespace std;

void Heapsort::createcities(multimap<string, vector<string> > rawdata, string city) {
    for (const auto& key : rawdata) {
        if (key.second[1] == city) {
            cities[key.first] = key.second[20]; // putting hospital into new map with just timeliness for sorting
        }
    }
}

void Heapsort::heapsortcities() {
    priority_queue<pair<string, string>, vector<pair<string, string>>, CustomCompare> heap; //creates empty heap

    //sorts based off struct of custom comparator
    for (const auto& key : cities) {
        heap.push(key);
    }
    // Print sorted hospitals by timeliness

    while (!heap.empty()) {
        cout << heap.top().first << " - " << heap.top().second << endl;
        heap.pop();

    }


}


