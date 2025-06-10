#pragma once
#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;
class ClassSystem {
public:
    int classnumber;
    vector<Student> students;
public:
    ClassSystem() :classnumber(0) {
    }
    void addStudent(Student stu) {
        students.push_back(stu);
        return;
    }
    void addClassNumber() {
        classnumber++;
        //cout << "DEBUG" << classnumber << endl;
        for(auto& student : students) {
            student.addClass();
        }
        return;
    }
    void signIn(string name) {
        for(auto& student : students) {
            if(student.getName() == name) {
                student.signClass();
                //cout << "DEBUG STUDENT " << name << " " << student.getPresentTimes() << endl;
                return;
            }
        }
    }
    Student getStudentById(int i) {
        return students[i];
    }
    Student getStudentByName(string name) {
        for(auto& student : students) {
            if (student.getName() == name) {
                return student;
            }
        }
    }
};