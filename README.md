# THU-CST-OOP-2025spring

面向对象程序设计

6次PAs

### 清华大学学生纪律处分管理规定实施细则

#### 第六章　学术不端、违反学习纪律的行为与处分

第二十一条 有下列违反课程学习纪律情形之一的，给予警告以上、留校察看以下处分：

（一）课程作业抄袭严重的；

（二）实验报告抄袭严重或者篡改实验数据的；

（三）期中、期末课程论文抄袭严重的；

（四）在课程学习过程中严重弄虚作假的其他情形。

# OOP

课堂笔记、选择题解析

### Lecture1

- 命令行基础操作

```
cd <-> pwdmkdirtype nul>a.cpp <-> touch a.cppdir <-> lscd ..cd <mydir>del a.cpp <-> rm a.cpprmdir /s OOP2020 <-> rm -r OOP2020move a.cpp OOP2020
```

TextHTMLCSSJavascriptCC++C#JavaPythonSqlSwiftJSON

将a.cpp移动至OOP2020目录 `test` 

move a.cpp OOP2020\ (Win)

mv a.cpp OOP2020/ (Linux/MAC)

将a.cpp拷贝至OOP2020目录

copy a.cpp OOP2020\ (Win)

cp a.cpp OOP2020/ (Linux/MAC)

将a目录下的所有文件拷贝到OOP2020目录

xcopy /e a OOP2020 (Win)

cp –r a OOP2020 (Linux/MAC)

- ssh操作

https://wangdoc.com/ssh/basic

自学材料：

C++中的面向对象编程

```
https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/?ref=gcse_outind
```

TextHTMLCSSJavascriptCC++C#JavaPythonSqlSwiftJSON

TextHTMLCSSJavascriptCC++C#JavaPythonSqlSwiftJSON

### Lecture2

C++程序的产生过程：**源程序**->编译器（语法分析+静态类型检查->**语法树建构**->遍历语法树，生成目标代码，汇编语言或机器代码，**生成目标模块.o/.obj**）->链接器（一组目标模块**链接**为可执行程序，处理函数和变量引用）->**可执行程序**

**多文件组织分步骤编译代码示例**

```bash
# 假设存在ex5\_main.cpp和func.cpp两个源文件


g++-c ex5\_main.cpp -o main.o # 编译ex5\_main.cpp生成main.o目标文件



g++-c func.cpp -o func.o # 编译func.cpp生成func.o目标文件



g++main.o func.o -o test2 # 将main.o和func.o链接为可执行文件test2
```

**函数与变量的声明和定义**

**函数声明与定义**：函数声明用于告知编译器函数的名称、参数类型和返回类型，如`int ADD(int a, int b);`，变量名可省略；函数定义是实现函数功能的代码，如`int ADD(int a, int b){return a + b;}`。同一个函数可以多次声明，但只能有一次定义，否则会导致链接错误。

**变量声明与定义**：变量定义会为变量分配内存空间，如`int x = 0;` 、`int arr[100];` ，`int x;`也是变量定义（定义但未初始化）；变量声明使用`extern`关键字，不会分配内存，如`extern int x;` 、`extern int arr[100];` ，`extern`也可用于函数声明，但不是必需的，常用于全局变量在不同文件内的共享。

**宏定义的使用**

**简单宏替换**：`#define`指令用于将一个标识符定义为一个字符串，如`#define PI 3.1415926535` ，在 C++ 中常被`const`取代。

**带参数宏定义**：`#define <宏名>(<参数表>) <字符串>`，如`#define sqr(x) ( (x) * (x) )` ，在 C++ 中一般被内联函数取代。

**防止头文件重复包含**：可使用`header guards`（`#ifndef __BODYDEF_H__ #define __BODYDEF_H__ // 头文件内容 #endif` ）或`#pragma once` ，`#pragma once`更简单且能保证物理上的同一文件不被编译 / 读取多次，速度更快。

**用于 Debug 输出**：通过`#ifdef`等指令控制程序是否输出调试信息，如`#ifdef DEBUG cout << "val:" << val << endl; #endif` 。

**MAKE 工具**

**作用**：用于自动化大型编译工作，减少编译时间，确保编译选项正确，链接正确的程序模块和程序库，还能简化任务重复执行过程，减少说明文档编写工作量。

**Makefile 编写规则**：遵循`<target> : <prerequisites>` `[tab] <command>`格式，当`prerequisites`中有文件比`target`文件新时，执行`command`。

**示例**

```bash
\# 注释以#开头
\# all: main test表示all目标依赖main和test目标
all: main test&#x20;
main: main.cpp student.cpp
&#x20;   g++ -o main main.cpp student.cpp # 编译生成main可执行文件
test: student.cpp student\_test.cpp
&#x20;   g++ -o test student\_test.cpp student.cpp # 编译生成test可执行文件
clean:
&#x20;   rm main test # 删除main和test可执行文件
```

TextHTMLCSSJavascriptCC++C#JavaPythonSqlSwiftJSON

**高级语法**：自动变量（`$@`目标文件、`$^`所有依赖文件、`$<`第一个依赖文件）、通配符（`%` ）、判断与循环（可使用 Bash 语法）。

**程序命令行参数**：`main(int argc, char** argv)`中，`argc`表示命令行参数的个数，`argv`是一个字符指针数组，存储命令行参数。使用时需注意检查`argc`的值，避免数组越界访问。

**GDB 调试工具**

**编译选项**：使用`g++ -g a.cpp –o a.out`编译程序，`-g`选项用于在可执行程序中包含标准调试信息。

**常用指令**：`gdb a.out`启动调试；`run`运行程序；`break +行号`设置断点，可带条件设置；`watch x`监测变量变化；`continue`跳至下一个断点；`step`单步执行（进入函数）；`next`单步执行（不进入函数）；`print x`输出变量值，还可修改变量；`display x`持续监测变量；`list`列出程序源代码；`quit`退出调试。

**课后实践**

**基本尝试**：编写包含多个`.h`和`.cpp`文件的小程序，设计全局函数和变量并在多个`.cpp`文件中引用，编写 Makefile 实现自动关联编译。

**高级尝试**：理解开源项目（`https://github.com/moses-smt/giza-pp/` ）中的 Makefile，学习其复杂的构建规则和变量使用。

```bash
.PHONY: gizapp mkcls-v2
all: gizapp mkcls-v2
gizapp:	$(MAKE) -C GIZA++-v2
mkcls-v2:	$(MAKE) -C mkcls-v2
clean:	$(MAKE) -C GIZA++-v2 clean	$(MAKE) -C mkcls-v2 clean
```

TextHTMLCSSJavascriptCC++C#JavaPythonSqlSwiftJSON
