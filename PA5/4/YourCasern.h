#pragma once

#include "Footman.h"
#include "Commander.h"
#include "Belong.h"
#include "Casern.h"

class HumanFootman :  public Footman {
public:
    //TODO
    HumanFootman(std::string id) : Footman(id) {}
};

class OrcFootman :  public Footman {
public:
    //TODO
    OrcFootman(std::string id) : Footman(id) {}
};

class HumanCommander :  public Commander {
public:
    //TODO
    HumanCommander(std::string id) : Commander(id) {}
};

class OrcCommander :  public Commander {
public:
    //TODO
    OrcCommander(std::string id) : Commander(id) {}
};

class HumanBelong :  public Belong {
public:
    //TODO
    HumanBelong(Footman* f, Commander* c) : Belong(f, c) {}
};

class OrcBelong :  public Belong {
public:
    //TODO
    OrcBelong(Footman* f, Commander* c) : Belong(f, c) {}
};

class HumanCasern : public Casern {
public:
    //TODO
    std::string getKind() override {
        return "HumanCasern";
    }
};

class OrcCasern : public Casern {
public:
	//TODO
    std::string getKind() override {
        return "OrcCasern";
    }
};
