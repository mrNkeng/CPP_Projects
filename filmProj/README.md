# 2017 Movie Sorter

## Table of Contents
1. [Project Description](#project-description)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Data Structures Used](#data-structures-used)
5. [Classes and Logic](#classes-and-logic)
6. [Getting Started](#getting-started)
7. [Author](#author)

## Project Description
This Movie Sorter is designed to provide an interactive way to sort and search through the top 100 films of 2017. The project reads from a CSV file to fetch the data and offers a menu-driven interface for a variety of sorting and searching operations.

## Features
- Sort films by Title
- Sort films by Rank
- Search films by Title
- Search films by Keywords
- Search films by Studio
- Search films by Month of Release
- User-friendly menu-driven interface

## Technologies Used
- C++
- File I/O

## Data Structures Used
- Binary Search Tree: Used for efficient sorting and searching operations.
  
## Classes and Logic

### Film1 Class
**Attributes:**
- Various attributes to hold details about each film (e.g., title, rank, etc.)

**Methods:**
- Getter and Setter methods for the attributes.

### FilmDB Class
**Attributes:**
- A binary search tree to hold `Film1` objects.

**Methods:**
- `FilmReport`: Sorts films by title and displays the report.
- `RankReport`: Sorts films by rank and displays the report.
- Various search methods to find films based on different attributes.

### main.cpp
This is the driver file containing the main method. It interacts with the `Film1` and `FilmDB` classes to handle user inputs and display outputs.

## Getting Started
1. Clone the repository.
2. Navigate to the project folder.
3. Compile and run `main.cpp` to start the program.

## Author
Aminkeng Nkeng
