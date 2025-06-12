// 非常经典的设计模式，是命令模式
#pragma once
#include <functional>
using namespace std;

class Click {
private:
    std::function<void()> func;
public:
    // TODO
    Click(std::function<void()> f = []{}) : func(f) {}
    // TODO
    void setClickCommand(std::function<void()> f) {
        func = f;
    }
    // TODO
    virtual void click() {
        func();
    }
};
class DoubleClick {
private:
    std::function<void()> func;
public:
    // TODO
    DoubleClick(std::function<void()> f = []{}) : func(f){
    }
    // TODO
    void setDoubleClickCommand(std::function<void()> f) {
        func = f;
    }
    // TODO
    virtual void doubleClick() {
        func();
    }
};