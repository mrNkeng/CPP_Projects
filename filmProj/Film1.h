/*
    File:   Film1.h
    Author: Aminkeng Nkeng
    Created: April 21, 2020

    Summary: 
    This Film1 class encapsulates the attributes and behavior related to a film,
    such as title, studio, opening date, gross earnings, and more. 
*/

#ifndef FILM1_H
#define FILM1_H

#include <string>
#include <iostream>

using namespace std;

class Film1 {
private:
    // Member variables for film details
    string FilmTitle;
    string Studio;
    string OpeningDate;
    double OpeningGross;
    double TotalGross;
    int Rank;
    int TotalTheaters;
    int OpeningTheaters;

public:
    // Utility function to format numbers
    string formatNumber(double numberToFormat) const;

    // Default constructor
    Film1();

    // Parameterized constructor
    Film1(string info);

    // Getters for all the film attributes
    string getFilmTitle() const;
    string getStudio() const;
    string getOpeningDate() const;
    double getTotalGross() const;
    double getOpeningGross() const;
    int getRank() const;
    int getTotalTheaters() const;
    int getOpeningTheaters() const;

    // Setters for all the film attributes
    void setFilmTitle(string newFilmTitle);
    void setStudio(string newStudio);
    void setOpeningDate(string newOpeningDate);
    void setTotalGross(double newTotalGross);
    void setOpeningGross(double newOpeningGross);
    void setRank(int newRank);
    void setTotalTheaters(int newTotalTheaters);
    void setOpeningTheaters(int newOpeningTheaters);

    // Overloaded operators for comparing Film1 objects
    bool operator<(const Film1& rhs) const;
    bool operator>(const Film1& rhs) const;
    bool operator==(const Film1& rhs) const;

    // Friend function to overload the ostream operator for easy printing
    friend ostream& operator<<(ostream& out, const Film1& rhs);
};

#endif /* FILM1_H */
