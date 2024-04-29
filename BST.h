/*
Name: Saif Ahmed Elsayed Abd Elfattah
ID: 900225535
*/
#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to represent data associated with a city
struct CityData {
    double latitude;
    double longitude;
    string country;

    CityData() : latitude(0.0), longitude(0.0) {}

    CityData(double lat, double lon, const string& cntry) : latitude(lat), longitude(lon), country(cntry) {}

    // Overloaded output operator to display CityData
    friend ostream& operator<<(ostream& os, const CityData& data) {
        os << "Latitude: " << data.latitude << ", Longitude: " << data.longitude << ", Country: " << data.country;
        return os;
    }

    // Overloaded input operator to read CityData
    friend istream& operator>>(istream& is, CityData& data) {
        is >> data.latitude >> data.longitude >> data.country;
        return is;
    }
};

// Binary Search Tree (BST) template class
template <typename Key, typename Data>
class BST {
private:
    // Structure to represent a node in the BST
    struct Node {
        Key key;
        Data data;
        Node* left;
        Node* right;
        Node(const Key& k, const Data& d) : key(k), data(d), left(nullptr), right(nullptr) {}
    };
    
    Node* root;

    // Private member functions
    Node* insert(Node* node, const Key& key, const Data& data);
    bool search(Node* node, const Key& key) const;
    Data retrieve(Node* node, const Key& key) const;
    void traverse(Node* node) const;
    void clear(Node* node);
    Node* remove(Node* node, const Key& key);
    void preorder(Node* node) const;
    void levelorder(Node* node) const;

public:
    // Constructor
    BST() : root(nullptr) {}

    // Destructor
    ~BST() { clear(root); }

    // Public member functions
    void insert(const Key& key, const Data& data) { root = insert(root, key, data); }
    bool empty() const { return root == nullptr; }
    bool search(const Key& key) const { return search(root, key); }
    Data retrieve(const Key& key) const { return retrieve(root, key); }
    void traverse() const { traverse(root); }
    void preorderSaveToFile(Node* node, ofstream& file) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    void clear() { clear(root); }
    void remove(const Key& key) { root = remove(root, key); }
    void preorder() const { preorder(root); }
    void levelorder() const { levelorder(root); }
};

#endif
