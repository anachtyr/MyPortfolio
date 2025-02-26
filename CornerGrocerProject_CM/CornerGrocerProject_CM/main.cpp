/*
 *  CornerGrocerProject_CM.cpp
 *
 *  Date: 21 February 2025
 *  Author: Chris Mainieri
 *
 */
#include <iostream>
#include <limits>
#include "ItemFrequency.h"
using namespace std;

int main() {
    ItemFrequency itemFrequency;
    int choice;
    string item;

    do {
        // Print menu:
        cout << "\nCorner Grocer Item Tracker Menu\n";
        cout << "1. Find item frequency\n";
        cout << "2. Print all frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Input validation for user choice:
        while (!(cin >> choice)) { // Check if input is a number
            cout << "Invalid input. Please enter a number: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }

        switch (choice) {
        case 1: // Execute first menu option (Item search)
            cout << "Enter item to search: ";
            cin >> item;
            cout << "Frequency of " << item << ": " << itemFrequency.getItemFrequency(item) << endl;
            break;
        case 2: // Execute second menu option (Full frequency list)
            itemFrequency.printAllFrequencies();
            break;
        case 3: // Execute third menu option (Full frequency histogram)
            itemFrequency.printHistogram();
            break;
        case 4: // Execute fourth menu option (Exit Program)
            cout << "Exiting program. Thank you for using the Corner Grocer Item Tracker.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}