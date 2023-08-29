/* 
 * File:   FilmDB.h
 * Author: Aminkeng Nkeng
 * 
 * Created on April 29, 2020, 1:02 PM
 */

#ifndef FILMDB_H
#define FILMDB_H

#include "Film1.h"
#include "BinarySearchTree.h"

// Class definition for FilmDB
class FilmDB {
public:
    // Default constructor
    FilmDB();
    
    // Method to add a Film1 object to the binary search tree
    void add(const Film1& films);
    
    // Method to search for a film by title
    void SearchTitle(string filmTitle);
    
    // Method to search for a film by studio
    void SearchStudio(string studioTitle);
    
    // Method to search for a film by keyword
    void SearchKeyword(string keyword);
    
    // Method to display films by their rank
    void RankReport();
    
    // Method to display all films in the database
    void FilmReport();
    
    // Method to search for films released in a particular month
    void ReleaseMonth(int month);
    
    // Static variables used for searching
    static string TitleSearch;
    static string StudioSearch;
    static string KeywordSearch;
    static bool found;
    static int MonthSearch;
    static int RankSearch;

private:
    // Binary search tree to store Film1 objects
    BinarySearchTree<Film1> FilmBST;
};

#endif /* FILMDB_H */
