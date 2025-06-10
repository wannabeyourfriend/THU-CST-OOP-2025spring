#include "Bob.h"

// Constructor
Bob::Bob(int capacity) : Robot(capacity) {}

// Run function - calculates sum of squares of all part ids
int Bob::run() const {
    int sum = 0;
    for (int i = 0; i < capacity; ++i) {
        sum += parts[i].get_id() * parts[i].get_id();
    }
    return sum;
}

// Get robot type name
std::string Bob::get_type() const {
    return "Bob";
}