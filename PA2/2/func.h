#pragma once
#include "Test.h"

// f1 函数：接收一个 Test 对象，返回一个 Test 对象
Test f1(Test t) {
    t.print("a");
    return t;      // 会调用拷贝构造函数
}

// f2 函数：接收一个 Test 对象，返回一个 Test 引用
Test& f2(Test& t) {
    t.print("b");
    return t;      // 直接返回引用，不会调用构造函数
}

// f3 函数：接收两个 Test 对象，交换它们的内容
void f3(Test& a, Test& b) {
    Test temp(std::move(a));  // 移动构造
    a = std::move(b);         // 移动赋值
    b = std::move(temp);      // 移动赋值，temp 被析构
}