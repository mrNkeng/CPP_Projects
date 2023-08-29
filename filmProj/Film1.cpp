/* 
 * File:   Film1.cpp
 * Author: Aminkeng Nkeng
 * 
 * Created on April 21, 2020, 11:58 AM

*The Film1 class is designed to encapsulate various attributes of a film including its title, studio, 
earnings, number of theaters, and opening date. It provides constructors for initialization, getter and 
setter methods for each attribute, and overloaded operators for object comparison. The class also 
includes utility functions for formatting output.
*/

#include "Film1.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// Default constructor
Film1::Film1() {
}

// Overloaded constructor that initializes the film properties from a string
Film1::Film1(string info) {
    string str;
    istringstream iss(info);
    
    getline(iss, str, ',');
    Rank = stoi(str);
       
    getline(iss, FilmTitle, ',');
        
    getline(iss, Studio, ',');
        
    getline (iss, str, ',');
    TotalGross = stod(str);
        
    getline (iss, str, ',');
    TotalTheaters = stoi(str);
        
    getline (iss, str, ',');
    OpeningGross = stod(str);
        
    getline (iss, str, ',');
    OpeningTheaters = stoi(str);
        
    getline(iss, OpeningDate);
}

string Film1::getFilmTitle() const {
    return FilmTitle;
}

string Film1::getOpeningDate() const {
    return OpeningDate;
}

string Film1::getStudio() const {
    return Studio;
}

double Film1::getOpeningGross() const {
    return OpeningGross;
}

double Film1::getTotalGross() const {
    return TotalGross;
}

int Film1::getOpeningTheaters() const {
    return OpeningTheaters;
}

int Film1::getRank() const{
    return Rank;
}

int Film1::getTotalTheaters() const{
    return TotalTheaters;
}

void Film1::setFilmTitle(string newFilmTitle) {
    FilmTitle = newFilmTitle;
}

void Film1::setOpeningDate(string newOpeningDate) {
    OpeningDate = newOpeningDate;
}

void Film1::setStudio(string newStudio) {
    Studio = newStudio;
}

void Film1::setOpeningGross(double newOpeningGross){
    OpeningGross = newOpeningGross;
}

void Film1::setTotalGross(double newTotalGross){
    TotalGross = newTotalGross;
}

void Film1::setOpeningTheaters(int newOpeningTheaters){
    OpeningTheaters = newOpeningTheaters;
}

void Film1::setRank(int newRank){
    Rank = newRank;
}

void Film1::setTotalTheaters(int newTotalTheaters){
    TotalTheaters = newTotalTheaters;
}




//overloaded operators
bool Film1::operator <(const Film1& rhs) const {
    return (this->FilmTitle < rhs.FilmTitle);
}
bool Film1::operator >(const Film1& rhs) const {
    return (this->FilmTitle > rhs.FilmTitle);
}
bool Film1::operator ==(const Film1& rhs) const {
    return (this->FilmTitle == rhs.FilmTitle
            && rhs.OpeningDate == this->OpeningDate
            && rhs.Studio == this->Studio
            && rhs.OpeningGross == this->OpeningGross
            && rhs.TotalGross == this->TotalGross
            && rhs.OpeningTheaters == this->OpeningTheaters
            && rhs.Rank == this->Rank
            && rhs.TotalTheaters == this->TotalTheaters);
}

// Utility method for formatting numbers
string Film1::formatNumber(double numberToFormat) const {

// Declare an ostringstream variable

ostringstream format;

 

// Insert parameter into stringstream object

//   formatted with decimal point and precision of 2

format << setprecision(2) << showpoint << fixed << numberToFormat;

 

// Convert stringstream to a string

string formatCommas = format.str();

// Are commas needed? (Comma needed when length >= 7)

    if (formatCommas.length() >= 7) {

    // Get the starting position to start entering the commas
    int i = formatCommas.length()-6;

    // Insert comma every 3rd position from the last until the position is at 1 or less
        while (i >= 1){
            formatCommas.insert(i, 1, ',');
            i = i-3;
        }
    }

    // Return the number formatted as a string with commas added

    return formatCommas;

}



// Overloaded stream output operator for Film1
ostream& operator<< (ostream& out, const Film1& rhs) {
    string f1 = rhs.formatNumber(rhs.OpeningGross);
    string f2 = rhs.formatNumber(rhs.TotalGross);
    out << fixed << setprecision(1);
    out << setw(50) << left << rhs.FilmTitle << "\t"
            << setw(5) << left << rhs.OpeningDate + "\t" + rhs.Studio
            << "\t$" << setw(20) << right << f1 << "\t"
            << '$' << setw(25) << left << f2 << "\t" 
            << rhs.OpeningTheaters << "\t" << rhs.Rank << "\t"
            << rhs.TotalTheaters;
    return out;
}