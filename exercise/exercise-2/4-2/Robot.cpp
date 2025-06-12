#include "Robot.h"

Robot::Robot(int capacity_) : capacity(capacity_), current_parts(0)
{
    parts = new Part[capacity];
}

Robot::~Robot()
{
    delete[] parts;
}

bool Robot::is_full() const
{
    return current_parts >= capacity;
}

void Robot::add_part(const Part &part)
{
    if(current_parts < capacity) {
        parts[current_parts++] = part;
    }
}

std::ostream &operator<<(std::ostream &out, const Robot &robot)
{
    out << "Build robot " << robot.get_type();
    return out;    
}
