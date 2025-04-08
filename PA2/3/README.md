## 题目描述

给定两个非负的分数 A=A1/A2和 B=B1/B2，你需要求出 A+B, A+B、AB、A/B ，并且判断这两个分数的大小。

对于输出的分数，需要化为最简形式，即输出分数的分子与分母最大公因数为 11。特别地，如果该分数为 00，输出 `0/1`；如果是一个不合法的分数（即除以 00 得到的分数），输出 `nan`。

你需要实现的是`Factor.h`和`Factor.cpp`。`main.cpp`已经给定了：

```cpp
//main.cpp
#include "Factor.h"
#include <iostream>

int main()
{
    using namespace std;
    Factor A, B;
    cin >> A;
    cin >> B;
    cout << A + B << endl;
    cout << A * B << endl;
    cout << A / B << endl;
    if (A < B)
        cout << "smaller" << endl;
    if (A > B)
        cout << "bigger" << endl;
    if (A == B)
        cout << "equal" << endl; 
    return 0;
}
```

编译命令是`g++ -std=c++11 Factor.cpp main.cpp -o main`。

## 输入格式

第一行一个非负分数 A*A*，格式为A1/A2*A*1/*A*2。

第二行一个非负分数 B*B*，格式为B1/B2*B*1/*B*2。

这里保证 0≤A1,B1≤1040≤*A*1,*B*1≤104，1≤A2,B2≤1041≤*A*2,*B*2≤104，且均为整数。

## 输出格式

第一行输出两个分数的和。

第二行输出两个分数的积。

第三行输出 AB*B**A* 的结果。

第四行，如果 A>B*A*>*B* 输出 `bigger`，如果 A<B*A*<*B* 输出 `smaller`，如果 A=B*A*=*B* 输出 `equal`。

以上输出分数的格式，如果不是不合法的分数，也为 `A/B`。

## 输入样例

```none
1/8
3/8
```

## 输出样例

```none
1/2
3/64
1/3
smaller
```

## 要求

你需要提交`Factor.h`和`Factor.cpp`，请将你的文件打包成一个zip压缩包并上传。你不需要提交`main.cpp`和`Makefile`。评测时，OJ会将提供的`main.cpp`贴入你的目录下进行编译并执行。

## 评分标准

OJ自动评测占100%。