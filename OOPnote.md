## OOP 笔记

- 友元类

  **friend**类可以访问其他声明了其自己的类的private和protecte成员

  ```cpp
  //一个类作为另外一个类的友元类
  class Geeks {
  	// GFG is a friend of Geeks
  	friend class GFG;
  }
  
  class GFG {
  	···
  }
  //一个全局函数作为另外一个类的友元函数
  friend return_type function_name (arguments);    // for a global function
  
  friend return_type class_name::function_name (arguments);    // for a member function of another class
  
  //另一个类的成员函数作为 Friend 函数
  ```

![Friend Function in C++ with Example](https://media.geeksforgeeks.org/wp-content/uploads/20220802105339/FriendFunctioninC-660x328.png)



> eg：`freind class`

```cpp
// C++ Program to demonstrate the
// functioning of a friend class
#include <iostream>
using namespace std;

class GFG {
private:
    int private_variable;

protected:
    int protected_variable;

public:
    GFG()
    {
        private_variable = 10;
        protected_variable = 99;
    }

    // friend class declaration
    friend class F;
};

// Here, class F is declared as a
// friend inside class GFG. Therefore,
// F is a friend of class GFG. Class F
// can access the private members of
// class GFG.
class F {
public:
    void display(GFG& t)
    {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable;
    }
};

// Driver code
int main()
{
    GFG g;
    F fri;
    fri.display(g);
    return 0;
}

```

> eg: `friend function`

```
```



### 小教员考试

#### 单选

1. 下面说法错误的是：

   A. C++11中，类内的非静态成员变量可以在类的构造函数外指明初始化参数。

   B. 常量对象可以成为非常量成员函数的参数

   C. 静态成员函数可以访问 this 指针。

   D. 对于自定义类型的静态数据成员，如果在.h文件中同时完成声明和定义，则链接可能会失败

   E. 创建和删除对象时，new[]和delete同时使用可能会导致内存泄漏

my answer：





### 今日教训：

模板类的成员函数必须要在类的定义中进行实现；原因是：模版类在编译的时候会根据不同的类型生成不同的实例

