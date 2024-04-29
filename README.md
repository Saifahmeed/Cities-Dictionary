# Major Cities Dictionary with Binary Search Tree

## Overview
A C++ implementation of a dictionary for major cities worldwide using a Binary Search Tree (BST) data structure. Retrieve city information efficiently by searching with the city name as the key. City data includes latitude, longitude, and the country in which the city exists. Features include adding new cities, searching for city data, listing all cities, calculating distances between cities, and saving/loading data from a file. Perfect for geographical data management projects!

## Problem Statement
Building a dictionary structure for major population cities on Earth using a Binary Search Tree. The structure should allow efficient retrieval of city information given the city name.

## Usage
### Dependencies
- C++11 compiler

### Installation
1. Clone this repository.
2. Compile the source files using your C++ compiler.
3. Run the executable file generated after compilation.

### How to Use
1. Load the dictionary from a file containing city data.
2. Choose from the following options:
   - Insert a new city into the dictionary.
   - Search for a city and retrieve its information.
   - List all cities stored in the dictionary.
   - Calculate the distance between two cities.
   - Perform a preorder traversal of the BST.
   - Perform a level-order traversal of the BST.
   - Save the dictionary to a file.
   - Exit the program.

### Example City Data Format
City data should be provided in the following format:
CityName,Latitude,Longitude,Country

Example:
Kandahar,31°37′N,65°43′E,Afghanistan


## Files
- `BST.h`: Header file containing the Binary Search Tree template class definition.
- `BST.cpp`: Source file containing the implementation of the Binary Search Tree template class.
- `main.cpp`: Main program file where the BST is used to create and manage the city dictionary.

## City Data Conversion
- The latitude and longitude values in degrees, minutes, and seconds format are converted to decimal degrees for processing.

## Additional Notes
- The program allows for the addition of new cities during separate runs, making the dictionary a growing one.
- City data is saved and loaded from a text file.
- Distance calculation between cities is based on their geographical coordinates using the Haversine formula.

## Contributors
- [Your Name]
