#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Student {
private:
    string studentname;
    int attends;
    int classnumber;
public:
    Student(string name_) : attends(0), classnumber(0) {
        studentname = name_;
        //cout << "Student " << name << " created" << endl;
    }
    string getName() {
        return studentname;
    }
    void signClass() {
        this->attends += 1; 
        //cout << "Student attend " << studentname << " " << attends << endl; 
        return;
    }
    int getPresentTimes() {
        //cout << "Student attend " << name << " " << classnumber << endl;
        return attends;
    }
    int getAbsentTimes() {
        int absents = classnumber - attends;
        return absents;
    }
    void addClass() {
        //cout << "DEBUG " << studentname << " classnumber++" << classnumber << endl;

        this->classnumber += 1;
        //cout << "DEBUG " << studentname << " classnumber++" << classnumber << endl;

        return;
    }
    ~Student() {}
};