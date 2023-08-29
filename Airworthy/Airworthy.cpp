/*
 * File: Airworthy.cpp
 * Author: Aminkeng
 *
 * This file contains the implementation of the Airworthy class. The class
 * provides methods to read passenger data from text files, calculate priority
 * values for boarding based on different methods, and simulate the time taken
 * for boarding. It uses ArrayMaxHeap to store and manage passengers based on
 * their boarding priorities.
 */


#include "Airworthy.h"
#include "ArrayMaxHeap.h"
#include "Passenger.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "HeapADT.h"
using namespace std;

/**
 * Constructor that initializes my variables
 * It also creates my ArrayMaxHeaps
 */
Airworthy::Airworthy() {

}

/**
 * key - the priority value for the PriorityQueue
where 'H' is a child or passenger who needs help in boarding,
'E' is an elite passenger (frequent flyer), and 'G' is a general boarding passenger
row where passenger is seated; must be a number between 1 and 26, where rows 1-4 are first class
 *  and rows 10 and 11 are exit rows
 * rows 23-26
rows 17-22
rows 11-16
rows 5-10
 * 
 */

/**
 * This function is calculating the old method for leading passengers
 * to be loaded into old heap
 * @param info
 */

void calculation1(Passenger& info) {
    if(info.getpassType() == 'H' ) {
        info.setKey(50);
    }
    else if (info.getRow() >= 1 && info.getRow() <= 4) {
        info.setKey(45);
    }
    else if (info.getpassType() == 'E') {
        info.setKey(40);
    }
    else if (info.getRow() >=10 && info.getRow() <= 11) {
        info.setKey(40);
    }
    else if (info.getRow() >=23 && info.getRow() <= 26) {
        info.setKey(35);
    }
    else if(info.getRow() >=17 && info.getRow() <=22){
        info.setKey(30);
    }
    else if(info.getRow() >=11 && info.getRow() <=16){
        info.setKey(25);
    }
    else if(info.getRow() >=5 && info.getRow() <=10)
        info.setKey(20);
}

/**
 *This function is calculating the new method for leading passengers
 *to be loaded into a new heap
 * @param info
 */
void calculation2(Passenger& info) {
    if(info.getpassType() == 'H' ) {
        info.setKey(50);
    }
    else if (info.getRow() >= 1 && info.getRow() <= 4) {
        info.setKey(45);
    }
    else if (info.getpassType() == 'E') {
        info.setKey(40);
    }
    else if(info.getpassType() == 'G')
    info.setKey(30);
}



/**
 * This function will read from the file and load the queues with error checking
 * @param FILENAME
 */
void Airworthy::fileWork(const string FILENAME) {
    string inString;
    ifstream inFile (FILENAME);
    if (!inFile)
		cout << "Error opening file - " << FILENAME << endl;
	else {
		getline (inFile, inString);
		while (inFile) {
			Passenger oldPass(inString);
                        calculation1(oldPass);
                        oldHeap.add(oldPass);
                        Passenger newPass(inString);
                        calculation2(newPass);
                        newHeap.add(newPass);
			getline (inFile, inString);
		}
		inFile.close();
	}
}

/**
 * This function serves as a simulation run for comparing the time
 * it takes to load the passengers.
 */

void Airworthy::runner() {
    int prevRow;
    prevRow = 99;
    Passenger pass1;
    Passenger pass2;
    oldTime = 0;
    newTime = 0;
    
    //cout << "Total Passengers" << oldHeap.getItemCount() << endl;
    
    while (!oldHeap.isEmpty()) {
        pass1 = oldHeap.peek();
        cout << pass1;
        oldHeap.remove();
        //cout << setw(10) << pass1.getpassLN() <<
               // "\t" << pass1.getpassType() <<
                //"\t" << pass1.getRow() << endl;
        
        if (pass1.getRow() > prevRow ) {
            oldTime = oldTime +1;
        }
        else oldTime = oldTime +25;
        
        prevRow = pass1.getRow();
        
    }
    
    //This will convert the seconds in minutes
    double nMin = oldTime/60;
    cout << endl;
    cout << "The calculated boarding time based on the traditional boarding method is: " << nMin << " minutes" << "\n" << endl;
    cout << endl;
    
    while (!newHeap.isEmpty()) {
        pass2 = newHeap.peek();
        cout << pass2;
        newHeap.remove();
        //cout << setw(10) << pass2.getpassLN() <<
                //"\t" << pass2.getpassType() <<
               // "\t" << pass2.getRow() << endl;
        
        if (pass2.getRow() > prevRow ) {
            newTime = newTime +1;
        }
        else newTime = newTime +25;
        
        prevRow = pass2.getRow();
    
    }
    //This will convert the seconds in minutes
    double nMin2 = newTime / 60;
    cout << endl;
    cout << "The calculated boarding time based on the newly proposed boarding method is: " << nMin2 << " minutes" << "\n" << endl;
    cout << endl;
}

 Passenger Airworthy::peekOldHeap() {
        if (oldHeap.isEmpty()) {
            throw std::runtime_error("Heap is empty!");
        }
        return oldHeap.peek();
    }

    bool Airworthy::validatePassenger(Passenger& p) {
        // Check row number, must be between 1 and 26
        if (p.getRow() < 1 || p.getRow() > 26) {
            return false;
        }
        
        // Check passenger type, must be 'H', 'E' or 'G'
        char type = p.getpassType();
        if (type != 'H' && type != 'E' && type != 'G') {
            return false;
        }
        
        return true;
    }



