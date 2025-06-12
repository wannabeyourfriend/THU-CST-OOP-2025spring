#pragma once
#include <iostream>
#include "Robot.h"
class Bob : public Robot {
public:
    Bob(int capacity_);

    virtual int run() const override;

protected:
    virtual std::string get_type() const override;
    
};