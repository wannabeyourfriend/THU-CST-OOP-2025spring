#pragma once
#include "event.h"
class Chocolate : public EventInterface{
public:
    int mood;
    int id;
public:
    Chocolate() : EventInterface() {
        mood = 0;
        id = 0;
    } 
    virtual void zoo(EventInterface*);
    virtual void shop(EventInterface*);
    virtual void birthday();
    //int getId();
    
};

class Strawberry : public EventInterface{
public:
    int mood;
    int id;
public:
    Strawberry() : EventInterface() {
        mood = 0;
        id = 1;
    } 
    virtual void zoo(EventInterface*);
    virtual void shop(EventInterface*);
    virtual void birthday();
    //int getId();
    
};
