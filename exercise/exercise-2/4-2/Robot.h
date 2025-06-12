#pragma once
#include<iostream>
#include<string>
#include"Part.h"
class Robot 
{
protected:
    Part* parts; // 部件构成的数组
    int capacity;
    int current_parts;
public:
    Robot(int capacity_);

    virtual ~Robot();

    bool is_full() const;

    void add_part(const Part& part);

    virtual int run() const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Robot& robot);

protected:
    //纯虚函数
    virtual std::string get_type() const=0;
};