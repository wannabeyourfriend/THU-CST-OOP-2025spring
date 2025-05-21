#pragma once
#include "Pair.h"
#include <string> 

class Map{
    Pair * data; // Pointer to the array of Pair objects
    int sz;      
    int capacity; 
public:
    Map(int n);   
    ~Map();       

    
    int& operator[](const std::string& key);

    int operator[](const std::string& key) const;

    int size() const;
};