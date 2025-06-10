#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "Part.h"

class Robot {
protected:
    Part* parts;       // Array of parts
    int capacity;      // Total number of parts needed
    int current_parts; // Current number of parts added
    
public:
    // Constructor
    Robot(int capacity);
    
    // Destructor
    virtual ~Robot();
    
    // Check if the robot is fully assembled
    bool is_full() const;
    
    // Add a part to the robot
    void add_part(const Part& part);
    
    // Run the robot (to be implemented by derived classes)
    virtual int run() const = 0;
    
    // Friend function for output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Robot& robot);
    
protected:
    // Virtual function to get robot type name (for output)
    virtual std::string get_type() const = 0;
};

#endif // ROBOT_H