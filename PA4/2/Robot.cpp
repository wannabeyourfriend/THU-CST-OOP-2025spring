#include "Robot.h"

// Constructor
Robot::Robot(int capacity) : capacity(capacity), current_parts(0) {
    parts = new Part[capacity];
}

// Destructor
Robot::~Robot() {
    delete[] parts;
}

// Check if the robot is fully assembled
bool Robot::is_full() const {
    return current_parts >= capacity;
}

// Add a part to the robot
void Robot::add_part(const Part& part) {
    if (current_parts < capacity) {
        parts[current_parts++] = part;
    }
}

// Output stream operator overloading
std::ostream& operator<<(std::ostream& os, const Robot& robot) {
    os << "Build robot " << robot.get_type();
    return os;
}