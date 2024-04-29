/*
Name: Saif Ahmed Elsayed Abd Elfattah
ID: 900225535
*/
#include "BST.h"
#include "BST.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    BST<string, CityData> cityDictionary;
    string cityFile = "MCity_List.txt"; // File to save the dictionary to

    // Load the dictionary from the file
    cityDictionary.loadFromFile(cityFile);

    int choice;
    while (true) { // Loop until user chooses to exit
        cout << "Dictionary Menu:" << endl; // Options for the user
        cout << "1. Insert City" << endl;
        cout << "2. Search City" << endl;
        cout << "3. List All Cities" << endl;
        cout << "4. Calculate Distance" << endl; 
        cout << "5. Preorder Traversal:" << endl;
        cout << "6. Level-order Traversal:" << endl; 
        cout << "7. Save Dictionary" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Insert a new city into the dictionary
            string cityName;
            CityData data;
            cout << "Enter City Name: ";
            cin >> cityName;
            cout << "Enter Latitude: ";
            cin >> data.latitude;
            cout << "Enter Longitude: ";
            cin >> data.longitude;
            cout << "Enter Country: ";
            cin >> data.country;
            cityDictionary.insert(cityName, data);
        } else if (choice == 2) {
            // Search for a city in the dictionary
            string cityName;
            cout << "Enter City Name: ";
            cin >> cityName;
            if (cityDictionary.search(cityName)) {
                CityData data = cityDictionary.retrieve(cityName);
                cout << "City Name: " << cityName << endl;
                cout << "City Data: " << data << endl;
            } else {
                cout << "City not found." << endl;
            }
        } else if (choice == 3) {
            // List all cities in the dictionary using in-order traversal
            cout << "List of All Cities:" << endl;
            cityDictionary.traverse();
        } else if (choice == 4) {
            // Calculate the distance between two cities
            string city1, city2;
            cout << "Enter the first city name: ";
            cin >> city1;
            cout << "Enter the second city name: ";
            cin >> city2;
            if (cityDictionary.search(city1) && cityDictionary.search(city2)) {
                CityData data1 = cityDictionary.retrieve(city1);
                CityData data2 = cityDictionary.retrieve(city2);

                double distance = calculateDistance(data1.latitude, data1.longitude, data2.latitude, data2.longitude);
                cout << "Distance between " << city1 << " and " << city2 << ": " << distance << " km" << endl;
            } else {
                cout << "One or both cities not found." << endl;
            }
        } else if (choice == 5) {
            // Perform a preorder traversal and display the nodes
            cout << "Preorder Traversal:" << endl;
            cityDictionary.preorder();
        } else if (choice == 6) {
            // Perform a level-order traversal and display the nodes
            cout << "Level-order Traversal:" << endl;
            cityDictionary.levelorder();
        } else if (choice == 7) {
            // Save the dictionary to a file
            cityDictionary.saveToFile(cityFile);
            cout << "Dictionary saved to " << cityFile << endl;
        } else if (choice == 8) {
            // Exit the program
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
