#include "functions.h"
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int sum = custom_sum(a, b);
    cout << sum << endl;
    // 根据编译时的宏选项进行make操作
    int result;
#ifdef MINUS
    result = custom_minus(a, b);
    cout << result <<endl;

#endif

#ifdef PRODUCT
    result = custom_product(a, b);
    cout << result <<endl;

#endif

#ifdef DIVIDE
    result = custom_divide(a, b);
    cout << result <<endl;

#endif
    return 0;
}