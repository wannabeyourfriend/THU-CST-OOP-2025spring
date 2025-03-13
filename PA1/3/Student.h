#pragma once
#include <string>
using namespace std;
class Student
{
private:
    string StudentName;
    int PresentTimes;
    int AbsentTimes;

public:
    Student(string name);
    string getName();
    int getPresentTimes();
    int getAbsentTimes();
    void addPresent();
    void addAbsent();
    void removeAbsent();
};