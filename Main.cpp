//right click clion screen to reload cmake project so directorys are correct
// new branch!
#include<iostream>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include <queue>
#include <algorithm>
#include <cctype>
#include <limits>
#include "SRC/Heapsort.h"
#include "SRC/Mergesort.h"



using namespace std;


multimap<string, vector<string>> dataimport() {
  //index 8 of vector is best rating number as a string
  // index 20 is timeliness of hsopital in vector as a string
  ifstream hospital("../Hospital_General_Information.csv");
  multimap<string, vector<string>> hospital_data; // multimap to account for hospitals with same name but different cities etc, like chain hopsitals

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
    hospital_data.insert({key, values});
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
string menu() {
  cout<< "Enter number of option you wish to continue with" << endl;
  cout << "1. Hospital ratings by states" << endl;
  cout << "2. Hospital timeliness by cities" << endl;
  string area;
  getline(cin, area);
  return area;
}
bool startover() {
  cout << "Would you like to start over? Y/N (please capatalize)" << endl;
  string answer;
  cin >> answer;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // gets rid of new line after cin
  if (answer == "Y") {
    return true;
    }
  else if (answer == "N") {
    return false;
  }
  return false;
}


int main(){
  multimap<string, vector<string>> data = dataimport();
  cout << "Welcome to Medtrics" << endl;
  cout<< "Find the best hospital for you in your area, compare dozens by their ratings." << endl;
  cout<< "Search by State or City" << endl;
  bool cont = true;
  while (cont) {
    string area = menu();
    if (area == "1") {
      cout << "Enter state intials (ex FL) for the state you wish to check:" << endl;
      string state;
      cin >> state;
      cout << "Would you like to compare ratings with merge sort or heap sort?" << endl;
      cout << "Enter merge or heap to continue"<< endl;
      string sorting;
      cin >> sorting;
      if (sorting == "heap") {
       cout << "--";
      }
      else if (sorting == "merge") {
        cout << "--";
      }
    }
    else if (area == "2"){
      cout << "Enter the city you wish to check:" << endl;
      string city;
      getline(cin, city); // use getline to account for spaces in city
      transform(city.begin(), city.end(), city.begin(),
                   [](unsigned char c){ return toupper(c); });
      cout << "Would you like to compare ratings with merge sort or heap sort?" << endl;
      cout << "Enter merge or heap to continue"<< endl;
      string sorting;
      cin >> sorting;
      if (sorting == "heap") {
        Heapsort heap; // calling class heapsort to make object
        heap.heapsortcities(data, city);
        cout << "would you like to compare runtime with merge sort? yes/no" << endl;
        string compare;
        cin >> compare;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // gets rid of new line after cin
        if (compare == "yes") {
          Mergesort merge;
          merge.createcitiesmerge(data, city);
          merge.mergesort_cities();

          cout << "heap sort took " << heap.gettime() << " seconds and merge sort took " << merge.gettime() << endl;
          if (heap.gettime() < merge.gettime()) {
            cout << "heap had faster run time performance" << endl;
          }
          else {
            cout << "merge had faster run time performance" << endl;
          }
        }
        else {
          continue;
        }
      }
      else if (sorting == "merge") {
        Mergesort merge;
        merge.createcitiesmerge(data, city);
        merge.mergesort_cities();
        cout << "would you like to compare runtime with heap sort? yes/no" << endl;
        string compare;
        cin >> compare;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // gets rid of new line after cin
        if (compare == "yes") {
          Heapsort heap; // calling class heapsort to make object
          heap.heapsortcities(data, city);

          cout << "heap sort took " << heap.gettime() << " seconds and merge sort took " << merge.gettime() << endl;
          if (heap.gettime() < merge.gettime()) {
            cout << "heap had faster run time performance" << endl;
          }
          else {
            cout << "merge had faster run time performance" << endl;
          }
        }
        else {
          continue;
        }
        }
      }
    cont = startover();

  }

  return 0;
};


