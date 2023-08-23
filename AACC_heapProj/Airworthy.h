/*

 */

/* 
 * File:   Airworthy.h
 * Author: Aminkeng
 *
 * Created on May 8, 2020, 1:05 PM
 */

#ifndef AIRWORTHY_H
#define AIRWORTHY_H

#include "Passenger.h"
#include "ArrayMaxHeap.h"

class Airworthy {
    
    private:
        //These private attributes will aid in calculating the time it takes for passengers to board
        int oldTime;
        
        int newTime;
        
        //This is my initialiazed heap in which the passengers will be entered
        ArrayMaxHeap<Passenger> oldHeap;
        
        ArrayMaxHeap<Passenger> newHeap;
public:
    //constructor
    Airworthy();
    
    /**
     * This function will read the data from the input file
     * and load the data into two priority queues.
     */
    void fileWork(const string FILENAME);
    
    /**
     * This function will run a simulation of the program.
     */
    void runner();

    // Function prototype
    Passenger peekOldHeap();  
    bool validatePassenger(Passenger& p);

};

#endif /* AIRWORTHY_H */

