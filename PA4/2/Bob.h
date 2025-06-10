#ifndef BOB_H
#define BOB_H

#include "Robot.h"

class Bob : public Robot {
public:
    // Constructor
    Bob(int capacity);
    
    // Run function - calculates sum of squares of all part ids
    virtual int run() const override;
    
protected:
    // Get robot type name
    virtual std::string get_type() const override;
};

#endif // BOB_H