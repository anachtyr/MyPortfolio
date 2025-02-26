#ifndef ITEM_FREQUENCY_H
#define ITEM_FREQUENCY_H

#include <string>
#include <map>
using namespace std;

class ItemFrequency {
private:
    map<string, int> itemCounts;
    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string outputFileName = "frequency.dat";

    bool loadData();
    bool saveData();

public:
    ItemFrequency();
    int getItemFrequency(const string& item); // For retrieving specific item frequency
    void printAllFrequencies(); // For printing full numerical list
    void printHistogram(); // For printing full histogram
};

#endif