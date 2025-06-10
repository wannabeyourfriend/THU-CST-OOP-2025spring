#include "editor.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

bool is_files_equal(string file1, string file2) // 比较两个文件的内容是否相同
{
    ifstream f1(file1.c_str());
    ifstream f2(file2.c_str());
    if (!f1.is_open() || !f2.is_open())
    {
        return false;
    }
    if (f1.tellg() != f2.tellg())
    {
        return false;
    }
    f1.seekg(0, std::ios::beg);
    f2.seekg(0, std::ios::beg);
    const size_t bufferSize = 4096;
    std::vector<char> buffer1(bufferSize);
    std::vector<char> buffer2(bufferSize);

    while (true)
    {
        f1.read(buffer1.data(), bufferSize);
        f2.read(buffer2.data(), bufferSize);

        std::streamsize count1 = f1.gcount();
        std::streamsize count2 = f2.gcount();

        if (count1 != count2)
        {
            return false;
        }

        if (count1 == 0)
        {
            if (f1.eof() && f2.eof())
            {
                break;
            }
            else
            {
                return false;
            }
        }

        if (memcmp(buffer1.data(), buffer2.data(), count1) != 0)
        {
            return false;
        }
    }

    return true;
}
void operate_editor(string inputfilepath, string outputfilepath) // 编辑器操作，将inputfilepath文件中的指令经过编辑器操作后，将其输出到outputfilepath文件中
{
    ifstream fin(inputfilepath);
    ofstream fout(outputfilepath);
    TextEditor t;
    int cmd_num = 0;
    fin >> cmd_num;
    string empty;
    getline(fin, empty);
    for (int i = 0; i < cmd_num; i++)
    {
        string cmd;
        getline(fin, cmd);
        t.apply(cmd);
    }
    fin.close();
    fout.close();
}