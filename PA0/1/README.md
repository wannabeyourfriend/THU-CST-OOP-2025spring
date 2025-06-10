### 2025/3/1选择题解析整理

> C++11中，类内的非静态成员变量可以在类的构造函数外指明初始化参数。-->正确的

```cpp
//C++11 允许在类内对参数进行初始化
class P {
private:
	int data = 1; 
	void add(P a);
public:
	void add(int i) { data += i;}
}
void P::add(P a) { data += a.data;}
```

> 常量对象可以成为非常量成员函数的参数。-->正确的

解析：拷贝构造函数。其参数是语言所规定的，是同类对象的常量引用。

```cpp
class Person {
	int id;
	···
public:
	Person(const Person& src) { id = src.id; ···}
}
```

> **静态对象成员函数可以访问`this`指针  ---> 错误的**

解析：不可以。`this`指针是用于指向对象实例的地址，而静态函数不与对象实例挂钩。

> 对于自定义类型的静态数据成员，如果在.h文件中同时完成声明和定义，则链接可能会失败

解析：头文件可能会被多个文件调用，链接时静态数据成员可能被定义多次。

> **创建和删除对象时，new[]和delete同时使用可能会导致内存泄漏**

解析：new[]意为给一个数组分配内存（会分配n个位置），delete表示释放指针指向的地址的内存（只会释放掉1个位置）。这样会导致剩下n-1个位置的内存无法释放，从而导致泄漏。

>读代码题

```cpp

#include <iostream>
using namespace std;

class MyInt{
public:
    MyInt(int i = 0) : val(i)  // (a)
    {    }
    MyInt(const MyInt& src) : val(src.val)  // (b) -> 拷贝构造，const MyInt& sr为常量左值引用
    {    }
    MyInt(MyInt&& src) : val(src.val)  // (c) -> 移动构造，MyInt&& src为右值引用
    {    }
    operator int() const  // (d)
    { 
        return val; 
    }
    MyInt& operator=(MyInt&& rhs)  // (e)
    {
        val = rhs.val;
        return *this;
    }
    MyInt& operator=(const MyInt& rhs)  // (f)
    {
        val = rhs.val;
        return *this;
    }
    int get_value() const
    {
        return val;
    }
private:
    int val;
};

void print(MyInt obj)
{
    cout << obj.get_value() << endl;
}

void print(int value)
{
    cout << value << endl;
}

int main()
{
    MyInt a;
    a = -3.8;  // (1)
    auto b = a + 1;  // (2)
    auto c = a;  // (3)
    print(a); print(b); print(c);  // (4)
    return 0;
}
```

解析：分别分析(1),(2),(3),(4)处的构造、赋值情况。

（1）处：会先将double转换为int，调用(a)处构造对象，最后调用(e)处进行移动赋值构造。

（2）处：编译器会自动推导a+ 1的类型是int，将a转换为int类型的变量，最后得到int类型的c，值为-2

（3）处：因为是直接定义和给c赋值，所以会直接调用移动构造函数（c）处，得到MyInt类型的变量c

（4）处：调用print来打印val的值，分别是-3\n-2\n-3

> 读代码题

```cpp
#include<iostream>
 using namespace std;

 class Base {
 public:
     virtual void f1(float x) {
         cout << "Base::f1 " << x << endl;
     }
     void f2(float x) {
         cout << "Base::f2 " << x << endl;
     }
 };

 class Derived : public Base {
 public:
     virtual void f1(float x) { // overwrite
         cout << "Derived::f1 " << x << endl;
     }
     void f2(int x) {				 					// (1)
         cout << "Derived::f2 " << x << endl;
     }
 };

 int main(void) {
     Base x;
     Derived y;        
     Base* pb1 = &x; 
     Base* pb2 = &y;
     Derived* pd = &y; 

     pd->f2(3.14f);			// (2)

     return 0;
 }
```

![图片](https://mmbiz.qpic.cn/mmbiz_png/QBYmoGK3Mnia6gOTmrxhzgA9WE2rtiacrG0RiaMcBicQrI61aaywJMcRyQDotGbziaPkk2EFL0WTRulxf5XzgG7PrTg/640?wx_fmt=png&from=appmsg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**A.**`Derived` **类不仅继承了** `Base::f2(float x)` **，而且额外定义了函数名相同，函数参数不同的** `Derived::f2(int x)`**，从而实现了函数重载。**

**B.** `Derived::f1()` **实现了对** `Base::f1() `**的重写覆盖。**

**C. (1) 处发生了重写隐藏。如果在此处加入** `override` **关键字变为** `void f2() override (int x)`**，则可以实现重写覆盖。**

**D. 由于 (1) 处发生了重写隐藏，因此 (2) 处将输出** `Derived::f2 3.14`

解析：`virtual void f1(float x)`是一个虚函数，表示可以被派生类重写，

A是错的，不是函数重载，而是重写。虚函数可以被派生类重写，这里A选型实际上应该是`erived::f1()` **实现了对** `Base::f1() `**的重写覆盖**,因此B是对的。而C是错误的，`override`用于辅助类型检查，只有重写覆盖的类型才可以通过编译，而不是将其他变为重写覆盖。

> **在一个类中可以有多个构造函数，它们构成了函数的重载；析构函数没有参数，所以不能重载，一个类仅有一个析构函数**

> **拷贝构造函数的形参一般被设定为本类对象的常量引用**

> **构造函数没有返回值类型，函数名与类名相同**

> 设计模式相关的表述：
>
> 1. **结构型模式关注对象之间结构关系上的抽象，从而提升对象结构的可维护性、代码的健壮性，能在结构层面上尽可能的解耦合**
> 2. **如果在一个系统里面有许多类，它们仅仅在行为上有区别，那么使用策略模式可以动态地让一个对象在许多行为中选择一种行为**
> 3. **模板方法在接口的一个方法中定义算法的骨架，将一些步骤的实现延迟到子类中，使得子类可以在不改变算法结构的情况下，重新定义算法中的某些步骤**
> 4. **开闭原则的含义是一个软件对象（类，模版，函数等）对于扩展是开放的，但是对于修改是封闭的**

一些比较细节的问题：

1.**当 std::vector 的 size 达到 capacity，仍然可以继续调用 push_back() 函数添加元素。** 解析：当 `std::vector` 的 `size` 达到 `capacity` 时，仍然可以继续调用 `push_back()` 向 `vector` 中添加元素。`capacity` 是 `vector` 当前能够存储的最大元素数量，而 `size` 是当前存储的元素数量。当调用 `push_back()` 时，如果 `size` 达到 `capacity`，`vector` 会自动重新分配更大的内存空间以适应更多的元素。通常，`capacity` 会在重新分配时扩展为当前 `capacity` 的两倍。因此，即使 `size` 达到 `capacity`，`push_back()` 依然有效，`vector` 会根据需要扩展内存，确保元素的添加不受限制

2.end迭代器指向的是**最后一个字符的后一个位置**

3.std::vector 在大小发生改变时，可能致使所有迭代器失效：当 `std::vector` 的大小发生改变时，特别是在执行如 `push_back()`、`insert()` 或 `resize()` 等操作时，可能会导致底层数据存储重新分配（reallocation）。在这种情况下，所有指向旧数据位置的迭代器会失效，因为内存地址可能已经被改变。具体来说，`std::vector` 的底层存储是连续的数组。当容量（`capacity`）不够时，`vector` 会分配一个新的、更大的内存块，并将现有元素复制到新的位置。这个过程会使得原来的迭代器指向的内存地址变得无效。因此，任何指向原始数据的迭代器、指针或引用在重新分配发生后都可能失效。为了避免此类问题，应该尽

量避免在 `vector` 大小变化时继续使用旧的迭代器。总结：`std::vector` 在大小变化时可能会导致所有迭代器失效，尤其是涉及重新分配内存时

4.如果类中没有定义任何构造函数，也没有显式删除默认构造函数，则编译器会合成默认构造函数

5.全局对象在main()函数调用之前构造，在main()函数执行完之前不会被析构

6.使用全局对象可能会使得代码之间的耦合性增大，因此尽量少用全局变量

7.**析构和构造的顺序问题**：造是先成员再整体，析构是**先整体再成员**