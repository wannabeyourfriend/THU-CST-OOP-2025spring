#include "Part.h"

// Constructor implementation
Part::Part(int id) : id(id) {}

// Get the id of the part
int Part::get_id() const {
    return id;
}