#include "Alice.h"

Alice::Alice(int capacity_) : Robot(capacity_)
{
    //
}

int Alice::run() const
{
    int sum = 0;
    for(int i = 0; i < capacity; i++) {
        sum += parts[i].get_id();
    }
    return sum;
}

std::string Alice::get_type() const {
    return "Alice";
}
