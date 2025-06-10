#pragma once

#include "AbstractFactory.h"
#include "YourCasern.h"

class HumanFactory: public AbstractFactory
{
public:
    //TODO
    Casern* createCasern() override {
        return new HumanCasern();
    }
    
    Footman* createFootman(std::string id) override {
        return new HumanFootman(id);
    }
    
    Commander* createCommander(std::string id) override {
        return new HumanCommander(id);
    }
    
    Belong* createBelong(Footman* f, Commander* c) override {
        return new HumanBelong(f, c);
    }
};

class OrcFactory : public AbstractFactory {
public: 
    //TODO
    Casern* createCasern() override {
        return new OrcCasern();
    }
    
    Footman* createFootman(std::string id) override {
        return new OrcFootman(id);
    }
    
    Commander* createCommander(std::string id) override {
        return new OrcCommander(id);
    }
    
    Belong* createBelong(Footman* f, Commander* c) override {
        return new OrcBelong(f, c);
    }
};
