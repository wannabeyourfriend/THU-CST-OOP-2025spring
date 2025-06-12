#pragma once
#include <iostream>
#include "Robot.h"
class Alice : public Robot {
public:
    Alice(int capacity_);

    virtual int run() const override;

protected:
    virtual std::string get_type() const override;
    
};