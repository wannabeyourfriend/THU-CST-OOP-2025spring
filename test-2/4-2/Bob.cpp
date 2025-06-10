#include "Bob.h"

Bob::Bob(int capacity_) : Robot(capacity_)
{
    //
}

int Bob::run() const
{
    int sum2 = 0;
    for(int i = 0; i < capacity; i++) {
        sum2 += parts[i].get_id() * parts[i].get_id();
    }
    return sum2;
}

std::string Bob::get_type() const {
    return "Bob";
}
