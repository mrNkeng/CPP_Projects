/*
 
 */

/* 
 * File:   Passenger.h
 * Author: Aminkeng
 *
 * Created on May 8, 2020, 12:22 PM
 */

#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
using namespace std;

class Passenger {
    
    
private:
    
    int Key;
    
    string passLN;
    
    char passType;
    
    int Row;

    
    
public:
    
/**
 * 
 */
Passenger();

/**
 * 
 * @param info
 */   
Passenger(string info);

/**
 * 
 * @return 
 */
int getKey() const;

/**
 * 
 * @return 
 */
string getpassLN() const;

/**
 * 
 * @return 
 */
char getpassType() const;

/**
 * 
 * @return 
 */
int getRow() const;

/**
 * 
 * @param newkey
 */
void setKey(int newKey);

/**
 * 
 * @param newpassLN
 */
void setpassLN(string newpassLN);

/**
 * 
 * @param newpassType
 */
void setpassType(char newpassType);

/**
 * 
 * @param newRow
 */
void setRow(int newRow);

//overloaded operators
   bool operator < (const Passenger& rhs) const;
   bool operator > (const Passenger& rhs) const;
   bool operator == (const Passenger& rhs) const;
        
   friend ostream& operator<< (ostream& out, Passenger& rhs);
};


#endif /* PASSENGER_H */


