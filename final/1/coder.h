#pragma once
#include "agent.h"
#include <iostream>
#include <string>
using namespace std;

class Coder: public Agent {
public:
    
    int char_coded;

public:
    Coder(int id, std::string& codes): Agent(id, codes) {
        char_coded = 0;
    }
    
    virtual void action() override {
        std::string incode;
        std::cin >> incode;
        codes = codes + incode;
        char_coded += incode.length();
    }
    virtual void report() override {
        int coder_id = this->get_agent_id();
        std::cout << "Coder " << coder_id << ": " << char_coded << " characters coded" << std::endl;
    }


};