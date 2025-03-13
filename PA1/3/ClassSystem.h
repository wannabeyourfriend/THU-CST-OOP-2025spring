#pragma once
#include "Student.h"
#include <vector>
using namespace std;
class ClassSystem
{
private:
    int totalLectures;
    vector<Student> students;

public:
    ClassSystem();
    void addClassNumber();
    void addStudent(Student student);
    Student getStudentById(int i);
    Student getStudentByName(string name);
    void signIn(string name);
};