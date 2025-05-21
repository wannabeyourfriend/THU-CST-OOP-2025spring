#include "Map.h"

Map::Map(int n) {
    capacity = n;
    data = new Pair[capacity]; // Allocate an array of Pair objects
    sz = 0;                    // Initially, the map contains no elements
}

Map::~Map() {
    delete[] data; // Deallocate the array of Pair objects
}

int& Map::operator[](const std::string& key) {
    for (int i = 0; i < sz; ++i) {
        if (data[i].hasKey(key)) {
            return data[i].getVal(); 
        }
    }

   
    data[sz].reset(key, 0); // Set key; value is 0 by default or by reset
    
    return data[sz++].getVal(); 
}

int Map::operator[](const std::string& key) const {
    for (int i = 0; i < sz; ++i) {
        if (data[i].hasKey(key)) {
            return data[i].getVal(); // Key found, return its value (by value copy)
        }
    }
    return 0;
}

int Map::size() const {
    return sz;
}