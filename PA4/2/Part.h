#ifndef PART_H
#define PART_H

class Part {
private:
    int id; // The number stored in the part

public:
    // Constructor
    Part(int id = 0);
    
    // Get the id of the part
    int get_id() const;
};

#endif // PART_H