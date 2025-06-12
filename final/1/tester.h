#pragma once
#include "agent.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Tester : public Agent {
protected:
    char char_marker;
    int flag;
    int test_pass;
public:

    Tester(int id, std::string& codes, char char_marker_, int flag_) : Agent(id, codes) {
        char_marker = char_marker_;
        flag = flag_;
        test_pass = 0;
    }
    virtual void action() override {
        int num_char = std::count(codes.begin(), codes.end(), char_marker);
        if ((num_char % 2) == (flag % 2)) {
            test_pass ++;
        }
        else {
            return;
        }
    }
    virtual void report() override {
        //Tester {agent_id}: {test_passed} tests passed
        //Tester {agent_id}: {test_passed} tests passed
        std::cout << "Tester " << this->get_agent_id() << ": " << test_pass << " tests passed" << std::endl;
    }
};  