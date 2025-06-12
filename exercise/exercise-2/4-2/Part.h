#pragma once
class Part 
{
private:
    int id;
public:
    Part(int id_ = 0) : id(id_) {}
    int get_id() const;
};