//right click clion screen to reload cmake project so directorys are correct

#include<iostream>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include <queue>
#include "SRC/Heapsort.h"



using namespace std;


map<string, vector<string>> dataimport() {
  //index 8 of vector is best rating number as a string
  // index 20 is timeliness of hsopital in vector as a string
  ifstream hospital("../Hospital_General_Information.csv");
  map<string, vector<string>> hospital_data;

  if (!hospital.is_open()) {
    cerr << "Failed to open file." << endl;
    return hospital_data;
  }
  string line;
  getline(hospital, line); // ignoring header from csv file

  while (getline(hospital, line)) {
    stringstream ss(line);
    string cell;
    vector<string> all_columns;
    string token;
    bool in_quotes = false;
    string temp;

    // handle quotes from csv
    for (char c : line) {
      if (c == '"') in_quotes = !in_quotes;
      if (c == ',' && !in_quotes) {
        all_columns.push_back(temp);
        temp = "";
      } else {
        temp += c;
      }
    }
    all_columns.push_back(temp);

    if (all_columns.size() < 3) continue;

    string key = all_columns[2]; // key for map is name of hospital to access

    vector<string> values;
    for (size_t i = 3; i < all_columns.size(); ++i) {
      if (all_columns[i].empty()) {
        values.push_back("0");
      } else {
        values.push_back(all_columns[i]);
      }
    } //push back all atributes into vector associated with hospital key
    hospital_data[key] = values;
  }
  //data.head() to see top to make sure inserting correctly
  // int count = 0;
  // for (const auto& entry : hospital_data) {
  //   cout << "Hospital Name: " << entry.first << endl;
  //   cout << "Attributes: ";
  //   for (const auto& val : entry.second) {
  //     cout << val << " | ";
  //   }
  //   cout << endl << "-------------------" << endl;
  //
  //   if (++count == 3) break; // stop after printing 3 entries
  // }
  return hospital_data;
}

int main(){
  map<string, vector<string>> data = dataimport();
  //testing
  Heapsort heap;
  try {
    heap.createcities(data,  "ATHENS");
    heap.heapsortcities();
  }
  catch(const std::exception& e){
  cout << "Heapsort failed" <<e.what() << endl;
  }
  catch (...) {  // Catch any other types of exceptions
    cout << "Heapsort failed due to an unknown error." << endl;
  }


  return 0;
};


