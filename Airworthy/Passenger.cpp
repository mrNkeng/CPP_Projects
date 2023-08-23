/*
 * File: Passenger.cpp
 * Author: (Your Name)
 *
 * This file contains the implementation of the Passenger class. This class
 * encapsulates data related to an individual passenger, such as last name,
 * passenger type ('H', 'E', 'G'), and row number. It also provides methods
 * for setting and retrieving these attributes.
 */


#include "Passenger.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

Passenger::Passenger() {
}

Passenger::Passenger(string info) {

    string str;
    istringstream iss(info);
    
    getline(iss, passLN, ' ');
    
    getline(iss, str, ' ');
    passType = str[0]; 
    
    getline(iss, str);
    Row = stoi(str);
    
    Key = 0;
    
}

int Passenger::getKey() const{
    return Key;
}

string Passenger::getpassLN() const {
    return passLN;
}

char Passenger::getpassType() const {
    return passType;
}

int Passenger::getRow() const{
    return Row;
}

void Passenger::setKey(int newKey) {
    Key = newKey;
}

void Passenger::setpassLN(string newpassLN){
    passLN = newpassLN;
}

void Passenger::setpassType(char newpassType){
    passType = newpassType;
}

void Passenger::setRow(int newRow){
    Row = newRow;
}

//overloaded operators
bool Passenger::operator <(const Passenger& rhs) const {
    return (this->Key < rhs.Key);
}
bool Passenger::operator >(const Passenger& rhs) const {
    return (this->Key > rhs.Key);
}
bool Passenger::operator ==(const Passenger& rhs) const {
    return (this->Key == rhs.Key
            && rhs.passLN == this->passLN
            && rhs.passType == this->passType
            && rhs.Row == this->Row);
}

ostream& operator<< (ostream& out, Passenger& rhs) {
    out << setw(15) << left << rhs.passLN << "\t"
            << setw(5) << left << rhs.passType << "\t" 
            << "\t" << setw(5) << rhs.Row << endl;
    return out;
}
