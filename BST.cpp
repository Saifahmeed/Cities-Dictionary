/*
Name: Saif Ahmed Elsayed Abd Elfattah
ID: 900225535
*/
#include "BST.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>
#include <fstream>
using namespace std;

// Preorder traversal to display BST nodes
template <typename Key, typename Data>
void BST<Key, Data>::preorder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    cout << "Key: " << node->key << ", Data: " << node->data << endl;
    preorder(node->left);
    preorder(node->right);
}

// Level-order traversal to display BST nodes
template <typename Key, typename Data>
void BST<Key, Data>::levelorder(Node* node) const {
    if (node == nullptr) {
        return;
    }
    queue<Node*> q; // Create a queue for level-order traversal
    q.push(node); // Push the root node to the queue
    while (!q.empty()) {
        Node* current = q.front();
        cout << "Key: " << current->key << ", Data: " << current->data << endl;
        q.pop();
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// Recursive function to insert a node in the BST
template <typename Key, typename Data>
typename BST<Key, Data>::Node* BST<Key, Data>::insert(Node* node, const Key& key, const Data& data) {
    if (node == nullptr) {
        return new Node(key, data);
    }
    if (key < node->key) {
        node->left = insert(node->left, key, data);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key, data);
    }
    return node;
}

// Recursive function to search for a key in the BST
template <typename Key, typename Data>
bool BST<Key, Data>::search(Node* node, const Key& key) const {
    if (node == nullptr) {
        return false;
    }
    if (key == node->key) {
        return true;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

// Recursive function to retrieve data associated with a key in the BST
template <typename Key, typename Data>
Data BST<Key, Data>::retrieve(Node* node, const Key& key) const {
    if (node == nullptr) {
        return Data();
    }
    if (key == node->key) {
        return node->data;
    }
    if (key < node->key) {
        return retrieve(node->left, key);
    }
    return retrieve(node->right, key);
}

// Inorder traversal to display BST nodes
template <typename Key, typename Data>
void BST<Key, Data>::traverse(Node* node) const {
    if (node == nullptr) {
        return;
    }
    traverse(node->left);
    cout << "Key: " << node->key << ", Data: " << node->data << endl;
    traverse(node->right);
}

// Save the BST to a file in preorder traversal order
template <typename Key, typename Data>
void BST<Key, Data>::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        preorderSaveToFile(root, file);
        file.close();
    } else {
        cerr << "Failed to open file for writing." << endl;
    }
}

// Recursive function to save the BST to a file in preorder traversal order
template <typename Key, typename Data>
void BST<Key, Data>::preorderSaveToFile(Node* node, ofstream& file) const {
    if (node == nullptr) {
        return;
    }
    file << node->key << "," << node->data.latitude << "," << node->data.longitude << "," << node->data.country << endl;
    preorderSaveToFile(node->left, file);
    preorderSaveToFile(node->right, file);
}

// Function to change latitude and longitude values to decimal values.
double DegMinSecToDecimal(const string& value) {
    double degrees = 0.0;
    double minutes = 0.0;
    double seconds = 0.0;
    istringstream ss(value);
    char degreeSymbol, minuteSymbol, secondSymbol;
    ss >> degrees >> degreeSymbol;

    // Extract the minutes part
    ss.ignore(1); // Skip the degree symbol
    ss >> minutes >> minuteSymbol;

    // Extract the seconds part
    ss.ignore(1); // Skip the minute symbol
    ss >> seconds >> secondSymbol;

    // Convert degrees, minutes, and seconds to the final decimal value
    double decimalValue = degrees + (minutes / 60.0) + (seconds / 3600.0);

    // Check the hemisphere (N or S for latitude, E or W for longitude)
    if (value.find("S") != string::npos || value.find("W") != string::npos) {
        decimalValue = -decimalValue;
    }

    return decimalValue;
}

// Load BST from a file
template <typename Key, typename Data>
void BST<Key, Data>::loadFromFile(const string& filename) {
    clear();  // Clear the existing tree

    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string city, latitudeStr, longitudeStr, country;

            // Use getline with ',' as the delimiter to split the line into parts
            if (getline(iss, city, ',') &&
                getline(iss, latitudeStr, ',') &&
                getline(iss, longitudeStr, ',') &&
                getline(iss, country)) {
                // Parse latitude and longitude values
                double latitude = DegMinSecToDecimal(latitudeStr);
                double longitude = DegMinSecToDecimal(longitudeStr);

                // Create a CityData object with the parsed data
                CityData data(latitude, longitude, country);

                // Insert the city and data into the BST
                insert(city, data);
            }
        }
        file.close();
    } else {
        cerr << "Failed to open file for reading." << endl;
    }
}

// Recursive function to clear the BST
template <typename Key, typename Data>
void BST<Key, Data>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Earth radius Constant.
const double EarthRadiusKm = 6371.137;

// Convert degrees, minutes, seconds to decimal degrees
double convertToDecimal(double degrees, double minutes, double seconds, char hemisphere) {
    double decimal = degrees + (minutes / 60.0) + (seconds / 3600.0);
    if (hemisphere == 'S' || hemisphere == 'W') {
        decimal = -decimal;
    }
    return decimal;
}

// Convert degrees to radians
double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Calculate the great-circle distance between two locations
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat = toRadians(lat2 - lat1);
    double deltaLon = toRadians(lon2 - lon1);

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) +
               cos(toRadians(lat1)) * cos(toRadians(lat2)) *
               sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EarthRadiusKm * c;

    return distance;
}

// Recursive function to remove a node with a given key from the BST
template <typename Key, typename Data>
typename BST<Key, Data>::Node* BST<Key, Data>::remove(Node* node, const Key& key) {
    if (node == nullptr) {
        return node;
    }
    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = node->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        node->key = temp->key;
        node->data = temp->data;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

// Explicit instantiation of the template class for specific types
template class BST<string, CityData>;
