#include "Student.h"
#include <string>
using namespace std;
Student::Student(string name)
{
    StudentName = name;
    AbsentTimes = 0;
    PresentTimes = 0;
}
string Student::getName()
{
    return StudentName;
}
int Student::getPresentTimes()
{
    return PresentTimes;
}
int Student::getAbsentTimes()
{
    return AbsentTimes;
}
void Student::addPresent()
{
    PresentTimes++;
}
void Student::removeAbsent()
{
    AbsentTimes--;
}
void Student::addAbsent()
{
    AbsentTimes++;
}