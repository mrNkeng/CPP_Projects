/*
    File: FilmDB.cpp
    Author: Aminkeng Nkeng
    Created: April 29, 2020

    Summary:
    The FilmDB class provides methods for adding films to a database and searching
    for them based on different criteria.
*/

#include "FilmDB.h"
#include "BinarySearchTree.h"

// Initialize static members
string FilmDB::StudioSearch = "";
string FilmDB::TitleSearch = "";
string FilmDB::KeywordSearch = "";
bool FilmDB::found = true;
int FilmDB::MonthSearch = 0;
int FilmDB::RankSearch = 0;

// Global utility functions for film display and search
void display(Film1& item) {
    cout << item << endl;
}

// Show films with a specific rank.
void justRank(Film1& item) {
    if (item.getRank() == FilmDB::RankSearch) {
        FilmDB::found = true;
        cout << item << endl;
    }
}

// Search films by title.
void SearchByTitle(Film1& item) {
    if (item.getFilmTitle() == FilmDB::TitleSearch) {
        FilmDB::found = true;
        cout << item << endl;
    }
}

// Search films by the studio.
void SearchByStudio(Film1& item) {
    if (item.getStudio() == FilmDB::StudioSearch) {
        FilmDB::found = true;
        cout << item << endl;
    }
}
// Search films by a keyword in their title.
void SearchByKeyword(Film1& item) {
    if (item.getFilmTitle().find(FilmDB::KeywordSearch) != string::npos) {
        FilmDB::found = true;
        cout << item << endl;
    }
}

// Search films by their release month.
void ReleaseDateSearch(Film1& item) {
    string month;
    if (FilmDB::MonthSearch == 1)
        month = "Jan";
    else if (FilmDB::MonthSearch == 2)
        month = "Feb";
    else if (FilmDB::MonthSearch == 3)
        month = "Mar";
    else if (FilmDB::MonthSearch == 4)
        month = "Apr";
    else if (FilmDB::MonthSearch == 5)
        month = "May";
    else if (FilmDB::MonthSearch == 6)
        month = "Jun";
    else if (FilmDB::MonthSearch == 7)
        month = "Jul";
    else if (FilmDB::MonthSearch == 8)
        month = "Aug";
    else if (FilmDB::MonthSearch == 9)
        month = "Sep";
    else if (FilmDB::MonthSearch == 10)
        month = "Oct";
    else if (FilmDB::MonthSearch == 11)
        month = "Nov";
    else month = "Dec";
    if (item.getOpeningDate().find(month) != string::npos){
        FilmDB::found = true;
        cout << item << endl;
    }
}


// Default constructor initializes FilmBST.
FilmDB::FilmDB() {
    BinarySearchTree<Film1> FilmBST;
}

// Adds a new film to the database.
void FilmDB::add(const Film1& films) {
    FilmBST.add(films);
}

// Searches for a film by title and displays it if found.
void FilmDB::SearchTitle(string filmTitle) {
    TitleSearch = filmTitle;
    found = false;
    FilmBST.inorderTraverse(SearchByTitle);
    if (!found) {
        cout << "Sorry, That request was not found." << endl;
    }
}


// Searches for a film by studio and displays it if found.
void FilmDB::SearchStudio(string studioTitle) {
    StudioSearch = studioTitle;
    found = false;
    FilmBST.inorderTraverse(SearchByStudio);
    if (!found) {
        cout << "Sorry, That request was not found." << endl;
    }
}

// Searches for a film by a keyword and displays it if found.
void FilmDB::SearchKeyword(string keyword) {
    KeywordSearch = keyword;
    found = false;
    FilmBST.inorderTraverse(SearchByKeyword);
    if (!found) {
        cout << "Sorry, That request was not found." << endl;
    }
}

// Displays all films ranked from 1 to 100.
void FilmDB::RankReport() {
    for (RankSearch = 1; RankSearch <= 100; ++RankSearch) {
        FilmBST.inorderTraverse(justRank);
    }
}

// Displays all films in the database.
void FilmDB::FilmReport() {
    FilmBST.inorderTraverse(display);
}

// Searches for films by their release month and displays them if found.
void FilmDB::ReleaseMonth(int month) {
    MonthSearch = month;
    found = false;
    FilmBST.inorderTraverse(ReleaseDateSearch);
    if (!found) {
        cout << "Sorry, That request was not found." << endl;
    }
}