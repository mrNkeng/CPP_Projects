/* 
 * @file:   main.cpp
 * @author: Aminkeng Nkeng
 *
 * Created on March 21, 2019, 9:02 PM
 */

#include "Film1.h"
#include "FilmDB.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// Function prototypes
void readFile(const string FILENAME, FilmDB& films);
void displayMainMenu();
void displayReportsMenu();
void displaySearchMenu();

int main() {
    // Constants and Variables
    const string FILENAME = "Films2017.csv";
    FilmDB films;
    string options, options1, options2;
    string sTitle, pStudio, kword;
    int rMonth;
    
    // Read the film data into the database
    readFile(FILENAME, films);

    cout << "\n Welcome To Nkeng's 2017 Movie Sorter \n";

    // Main menu loop
    while (true) {
        displayMainMenu();
        cin >> options;

        if (options == "X" || options == "x") {
            break;
        }
        else if (options == "A" || options == "a") {
            cout << " \n This application consists of the top 100 films in 2017!\n"
                 << "You can generate a report from the main menu.\n"
                 << "PLEASE ENJOY!!!\n";
        }
        else if (options == "R" || options == "r") {
            displayReportsMenu();
            cin >> options1;
            
            if (options1 == "T" || options1 == "t") {
                films.FilmReport();
            }
            else if (options1 == "R" || options1 == "r") {
                films.RankReport();
            }
            else {
                cout << "\n Invalid option in Reports Menu, please try again.\n";
            }
        }
        else if (options == "S" || options == "s") {
            displaySearchMenu();
            cin >> options2;
            
            if (options2 == "T" || options2 == "t") {
                cout << "What movie title would you like to search for?" << endl;
                cin >> sTitle;
                films.SearchTitle(sTitle);
            }
            else if (options2 == "K" || options2 == "k") {
                cout << "What keyword would you like to search for?" << endl;
                cin >> kword;
                films.SearchKeyword(kword);
            }
            else if (options2 == "S" || options2 == "s") {
                cout << "What production studio would you like to search for?" << endl;
                cin >> pStudio;
                films.SearchStudio(pStudio);
            }
            else if (options2 == "M" || options2 == "m") {
                cout << "What month of release would you like to search for?" << endl;
                cin >> rMonth;
                films.ReleaseMonth(rMonth);
            }
            else {
                cout << "\n Invalid option in Search Menu, please try again.\n";
            }
        }
        else {
            cout << "\n Invalid option, please try again.\n";
        }
    }

    return 0;
}

// Function to read file and populate FilmDB object
void readFile(const string FILENAME, FilmDB& films) {
    string inString;
    ifstream inFile (FILENAME);
    
    if (!inFile) {
        cout << "Error opening file - " << FILENAME << endl;
    }
    else {
        getline(inFile, inString);
        while (inFile) {
            Film1 newFilm(inString);
            films.add(newFilm);
            getline(inFile, inString);
        }
        inFile.close();
    }
}

void displayMainMenu() {
    cout << "---------------------------------------------\n";
    cout << "  MAIN MENU\n";
    cout << "  A - About the Application\n";
    cout << "  R - Reports\n";
    cout << "  S - Search the Database\n";
    cout << "  X - Exit the Program\n";
    cout << "Enter your selection -> ";
}

void displayReportsMenu() {
    cout << "---------------------------------------------\n";
    cout << "  REPORTS MENU\n";
    cout << "  T - Order by Film Title report\n";
    cout << "  R - Order by Rank report\n";
    cout << "  X - Return to main menu\n";
    cout << "Enter your selection -> ";
}

void displaySearchMenu() {
    cout << "---------------------------------------------\n";
    cout << "  SEARCH MENU\n";
    cout << "  T - Search by Title\n";
    cout << "  K - Search by Keyword(s)\n";
    cout << "  S - Search by Studio\n";
    cout << "  M - Search by Month of Release\n";
    cout << "  X - Return to main menu\n";
    cout << "Enter your selection -> ";
}










































































/*
#include "Film1.h"
#include "FilmDB.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// Function prototypes
void readFile(const string FILENAME, FilmDB& films);

int main() {
    // Constants and Variables
    const string FILENAME = "Films2017.csv";
    FilmDB films;
    string options, options1, options2, kword, sTitle, pStudio;
    int rMonth;

    // Welcome Message
    cout << "Welcome To Nkeng's 2017 Movie Sorter" << endl;

    // Main menu loop
    while (options != "X") {
        // Main menu options
        cout << "MAIN MENU \n"
             << "A - About the Application \n"
             << "R - Reports \n"
             << "S - Search the Database \n"
             << "X - Exit the Program \n"
             << "Enter your selection -> ";
        cin >> options;

        if (options == "A") {
            // About section
            cout << "This application consists of the top 100 films in 2017! You can "
                 << "generate a report from the main menu [...]"
                 << "PLEASE ENJOY!!!" << endl;
        }
        else if (options == "R") {
            // Reports menu
            cout << "REPORTS MENU \n"
                 << "T - Order by Film Title report \n"
                 << "R - Order by Rank report \n"
                 << "X - Return to main menu \n"
                 << "Enter Selection ->";
            cin >> options1;
            
            // Reports menu actions
            if (options1 == "T") {
                films.FilmReport();
            }
            else if (options1 == "R") {
                films.RankReport();
            }
        }
        else if (options == "S") {
            // Search menu
            cout << "Search MENU "
                 << "T - Search by Title \n"
                 << "K - Search by Keyword(s) \n"
                 << "S - Search by Studio \n"
                 << "M - Search by month of release \n"
                 << "X - Return to main menu \n"
                 << "Enter Selection ->";
            cin >> options2;
        
        if (options2 == "T") {
            cout << "What movie title would you like to search for ?" << endl;
            cin >> sTitle;
            films.SearchTitle(sTitle);
        }
        else if (options2 == "K") {
            cout << "What keyword would you like to search for ?" << endl;
            cin >> kword;
            films.SearchKeyword(kword);
        }
        else if (options2 == "S") {
            cout << "What production Studio would you like to search for ?" << endl;
            cin >> pStudio;
            films.SearchStudio(pStudio);
        }
        else if (options2 == "M") {
            cout << "What month of release would you like to search for ?" << endl;
            cin >> rMonth;
            films.ReleaseMonth(rMonth);
        }
        
    }
    
}         
   
    
    return 0;
}

// Function to read file and populate FilmDB object
void readFile(const string FILENAME, FilmDB& films) {
    string inString;
    ifstream inFile (FILENAME);
    
    if (!inFile) {
        cout << "Error opening file - " << FILENAME << endl;
    }
    else {
        getline(inFile, inString);
        while (inFile) {
            Film1 newFilm(inString);
            films.add(newFilm);
            getline(inFile, inString);
        }
        inFile.close();
    }
}
        */   


