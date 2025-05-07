#ifndef ALICE_H
#define ALICE_H

#include "Robot.h"

class Alice : public Robot {
public:
    // Constructor
    Alice(int capacity);
    
    // Run function - calculates sum of all part ids
    virtual int run() const override;
    
protected:
    // Get robot type name
    virtual std::string get_type() const override;
};

#endif // ALICE_H