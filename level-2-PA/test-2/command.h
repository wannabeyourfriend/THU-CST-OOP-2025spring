#pragma once
#include "window.h"
#include <iostream>
#include <memory> //使用shared_ptr
#include <list> // 使用std::list
using namespace std;

class ClearAll {
    std::list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    ClearAll(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox) {
    }
    //重载(),使得对象可以像函数一样调用
    void operator()()
    {
        // 构建一个临时的list用来记录改变了哪些Checkbox
        list<Checkbox*> t;
        for(auto & it : checkbox)
        {
            if(it->status == 1) {
                t.push_back(it.get());
                it->status = 0;
            }
            it->status = 0;
        }
        history.push_back(t);

    }
};

class SelectAll {
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    SelectAll(list<shared_ptr<Checkbox>> checkbox) :checkbox(checkbox) {}
    void operator()() {
        list<Checkbox*> t;
        for (auto& it : checkbox){
            if (it->status == 0) {
                t.push_back(it.get());
                it->status = 1;
            }
            history.push_back(t);
        }
    }
};

class Submit {
    list<shared_ptr<Checkbox>> checkbox;
public:
    // TODO
    Submit(list<shared_ptr<Checkbox>> checkbox) : checkbox(checkbox) {}
    void operator()() {
        for(auto & it : checkbox)
        {
            if(it->status == 1)
            {
                cout << it->getName() << " is selected" << endl;
            }
            else{
                cout << it->getName() << " is not selected" << endl;
            }
        }
    }
};