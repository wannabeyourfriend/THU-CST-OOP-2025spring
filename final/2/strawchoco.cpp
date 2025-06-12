#include "strawchoco.h"
using namespace std;
#include <iostream>
void Chocolate::zoo(EventInterface *)
{
    increase_mood(5);
}

void Chocolate::shop(EventInterface *)
{
    increase_mood(1);
}


void Chocolate::birthday()
{
    
}

// int Chocolate::getId() {
//     return 1;
// }

void Strawberry::zoo(EventInterface* s) 
{
    increase_mood(1);

    Chocolate* pC = dynamic_cast<Chocolate*>(s);
    if (pC != nullptr ) {
        increase_mood(5);
        //std::cout << "DEBUG" << std::endl;

    }
    else {
    }

}

void Strawberry::shop(EventInterface* s) {
    increase_mood(5);
    Chocolate* pC = dynamic_cast<Chocolate*>(s);
    if (pC != nullptr) {
        increase_mood(5);
        //std::cout << "DEBUG" << std::endl;

    }
    else {
    }
}


void Strawberry::birthday()
{

}

// int Strawberry::getId() {
//     return 0;
// }

