#pragma once
#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include <vector>


class Casern {
    //TODO
protected:
    std::vector<Footman*> footmen;
    std::vector<Commander*> commanders;
    std::vector<Belong*> belongs;
public:
    virtual std::string getKind() = 0;
	//TODO
    virtual ~Casern() {}
    
    void addFootman(Footman* footman) {
        footmen.push_back(footman);
    }
    
    void addCommander(Commander* commander) {
        commanders.push_back(commander);
    }
    
    void addBelong(Belong* belong) {
        belongs.push_back(belong);
    }
    
    Footman* getFootmanbyIndex(int index) {
        return footmen[index];
    }
    
    Commander* getCommanderbyIndex(int index) {
        return commanders[index];
    }
    
    Belong* getBelongbyIndex(int index) {
        return belongs[index];
    }
};