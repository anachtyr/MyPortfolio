#include "ItemFrequency.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

// Helper function to trim leading and trailing whitespace from a string
string trim(const string& str) {
    string result;
    string::const_iterator start = str.begin();
    while (start != str.end() && isspace(*start)) {
        ++start;
    }
    string::const_iterator end = str.end();
    while (end != start && isspace(*(end - 1))) {
        --end;
    }
    result.assign(start, end);
    return result;
}

ItemFrequency::ItemFrequency() {
    if (!loadData()) { // Error handling for failure to load data
        cerr << "Failed to load data. Exiting." << endl;
        exit(1);
    }
    if (!saveData()) { // Error handling for failure to save data to frequency.dat
        cerr << "Failed to save data. Exiting." << endl;
        exit(1);
    }
}

bool ItemFrequency::loadData() {
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) { // Error handling for failure to open input file
        cerr << "Error opening input file: " << inputFileName << endl;
        return false;
    }

    string item;
    while (getline(inputFile, item)) {
        item = trim(item);
        if (item.empty()) continue; // Skip empty lines
        itemCounts[item]++; // Increment the count for the item
    }

    inputFile.close();
    return true;
}

bool ItemFrequency::saveData() {
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) { // Error handling for failure to open output file
        cerr << "Error opening output file: " << outputFileName << endl;
        return false;
    }

    for (const auto& pair : itemCounts) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    outputFile.close();
    return true;
}

int ItemFrequency::getItemFrequency(const string& item) {
    auto it = itemCounts.find(item);
    if (it != itemCounts.end()) {
        return it->second;
    }
    else { // Returns 0 if item is not in the item list
        return 0;
    }
}

void ItemFrequency::printAllFrequencies() {
    if (itemCounts.empty()) { // Message for handling empty item list
        cout << "No items found in the inventory.\n";
        return;
    }

    cout << "\nItem Frequencies:\n";

    int maxItemLength = 0;
    for (const auto& pair : itemCounts) {
        maxItemLength = max(maxItemLength, (int)pair.first.length());
    }

    for (const auto& pair : itemCounts) {
        cout << setw(maxItemLength + 2) << left << pair.first << " " << pair.second << endl;
    }
}

void ItemFrequency::printHistogram() {
    if (itemCounts.empty()) { // Message for handling empty item list
        cout << "No items found in the inventory.\n";
        return;
    }
    cout << "\nItem Frequency Histogram:\n";

    int maxItemLength = 0;
    for (const auto& pair : itemCounts) {
        maxItemLength = max(maxItemLength, (int)pair.first.length());
    }

    for (const auto& pair : itemCounts) {
        cout << setw(maxItemLength + 2) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}