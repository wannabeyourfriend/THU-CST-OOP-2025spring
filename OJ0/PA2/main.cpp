#include "editor.h"
#include "judge.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{   
    
    for (int i = 1; i <= 4; i++)
    {
        string test_in = "test/exp" + to_string(i) + ".in";
        //string test_out = "test/exp" + to_string(i) + ".out";
        string result_out = "out/exp" + to_string(i) + ".out";
        operate_editor(test_in, result_out);
        // if (is_files_equal(result_out, test_out))
        // {
        //     cout << "Test " << i << " passed!" << endl;
        // }
        // else
        // {
        //     cout << "Test " << i << " failed!" << endl;
        // }
    }
    
    return 0;
}