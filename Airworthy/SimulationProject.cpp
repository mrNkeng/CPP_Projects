/* 
 * File: SimulationProject.cpp
 * Author: Aminkeng
 * 
 * This file contains the `main()` function that serves as the entry point
 * for the Airworthy Airlines boarding simulation program. It initializes
 * multiple instances of the Airworthy class, each corresponding to a different
 * flight capacity scenario (70%, 85%, and 100%). It then reads data from text
 * files and simulates the boarding procedures using the old and new methods.
 */


#include "SimulationProject.h"
#include "Passenger.h"
#include "ArrayMaxHeap.h"
#include "Airworthy.h"
#include <iostream>
#include <fstream>
using namespace std;

// Test if file is empty
bool isFileEmpty(const string& filename) {
    ifstream inFile(filename);
    return inFile.peek() == ifstream::traits_type::eof();
}

// Test for invalid passenger type and row number
bool validatePassenger(const Passenger& pass) {
    char type = pass.getpassType();
    int row = pass.getRow();
    return (type == 'H' || type == 'E' || type == 'G') && (row >= 1 && row <= 26);
}

// Describes the purpose and functionality of the program
void description() {
    cout << "\n Welcome to the Airworthy Airlines Boarding Simulation Program!\n\n";
    cout << "This program will perform a comparative analysis of two boarding procedures:\n";
    cout << "1. The traditional boarding method based on various factors like row number and passenger type.\n";
    cout << "2. A new proposed boarding method that primarily focuses on special cases and class types.\n";
    cout << "'H' is a child or passenger who needs help in boarding,'E' is an elite passenger (frequent flyer), and 'G' is a general boarding passenger";
    cout << "The program will simulate the time required to board passengers for flights operating at 70%, 85%, and 100% capacity.\n";
    cout << "The boarding process will be printed, displaying each passenger's last name, type, and row number.\n";
    cout << "Finally, the time taken for each boarding method will be compared.\n\n";
    cout << "Let's get started!\n\n";
}

int main() {
    // Define file names for different flight capacities
    const string FILENAME1 = "airworthy100.txt";
    const string FILENAME2 = "airworthy70.txt";
    const string FILENAME3 = "airworthy85.txt";
    
    // Initialize Airworthy objects for each flight capacity
    Airworthy group1;
    Airworthy group2;
    Airworthy group3;

    // Display the program description
    description();
    
    // Test for empty file
    if(isFileEmpty(FILENAME1) || isFileEmpty(FILENAME2) || isFileEmpty(FILENAME3)) {
        cout << "One or more input files are empty. Exiting program.\n";
        return 1;
    }
    
    // Run the simulation for 100% flight capacity and validate
    cout << "Simulating boarding for 100% flight capacity:\n";
    group1.fileWork(FILENAME1);
    Passenger testPass1 = group1.peekOldHeap();
    if(!validatePassenger(testPass1)) {
        cout << "Invalid passenger data found. Exiting simulation for 70% flight capacity.\n";
        return 1;
    }
    group1.runner();
    cout << "------------------------------------------------\n\n";
    
    // Run the simulation for 70% flight capacity
    cout << "Simulating boarding for 70% flight capacity:\n";
    group2.fileWork(FILENAME2);
    Passenger testPass2 = group2.peekOldHeap();
    if(!validatePassenger(testPass2)) {
        cout << "Invalid passenger data found. Exiting simulation for 70% flight capacity.\n";
        return 1;
    }
    group2.runner();
    cout << "------------------------------------------------\n\n";
    
    // Run the simulation for 85% flight capacity
    cout << "Simulating boarding for 85% flight capacity:\n";
    group3.fileWork(FILENAME3);
    Passenger testPass3 = group3.peekOldHeap();
    if(!validatePassenger(testPass3)) {
        cout << "Invalid passenger data found. Exiting simulation for 85% flight capacity.\n";
        return 1;
    }
    group3.runner();
    cout << "------------------------------------------------\n\n";
    
    cout << "Simulation complete. Thank you for using the Airworthy Airlines Boarding Simulation Program!\n";
            
    return 0;
}
