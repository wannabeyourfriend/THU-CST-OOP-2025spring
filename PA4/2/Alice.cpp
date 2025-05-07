#include "Alice.h"

// Constructor
Alice::Alice(int capacity) : Robot(capacity) {}

// Run function - calculates sum of all part ids
int Alice::run() const {
    int sum = 0;
    for (int i = 0; i < capacity; ++i) {
        sum += parts[i].get_id();
    }
    return sum;
}

// Get robot type name
std::string Alice::get_type() const {
    return "Alice";
}