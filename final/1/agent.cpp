#include "agent.h"
#include "coder.h"
#include "tester.h"
#include <iostream>

Agent *Agent::create_agent(int agent_type, int id, std::string &codes)
{
    if(!agent_type) {
        Agent* Agent_ptr = new Coder(id, codes);
        //std::cout << "DEBUG Agent" << id << std::endl;
        return Agent_ptr;

    }
    else {
        char char_market;
        int flag;
        std::cin >> char_market >> flag;
        Agent* Agent_ptr = new Tester(id, codes, char_market, flag);
        return Agent_ptr;
    }
}