#ifndef SWITCH_H
#define SWITCH_H

#include <vector>

template <class T>
class MySwitch {
private:
    // 定义一个结构体来存储每个case的信息
    struct Case {
        T flag;                  // case的条件值
        void (*op)(int&);        // 操作函数指针
        int* target;             // 操作对象指针
        bool shouldBreak;        // 是否需要break
        
        Case(T f, void(*o)(int&), int* t, bool sb) : 
            flag(f), op(o), target(t), shouldBreak(sb) {}
    };
    
    std::vector<Case> cases;     // 存储所有的case
    
public:
    // 构造函数
    MySwitch() {}
    
    // 添加一个case
    void addCase(T flag, void(*op)(int&), int* target, bool shouldBreak) {
        cases.push_back(Case(flag, op, target, shouldBreak));
    }
    
    // 执行switch逻辑
    void execute(T value) {
        for (auto& c : cases) {
            if (value == c.flag) {
                // 执行操作
                c.op(*(c.target));
                
                // 如果需要break，则终止匹配
                if (c.shouldBreak) {
                    break;
                }
            }
        }
    }
};

#endif // SWITCH_H