#include"ClassSystem.h"
ClassSystem::ClassSystem()
{
    totalLectures = 0;
}
void ClassSystem::addClassNumber()
{
    totalLectures += 1;
    for (auto& student : students) {
        student.addAbsent();
    }
}
void ClassSystem::addStudent(Student student) {
    students.push_back(student);
}
Student ClassSystem::getStudentById(int i) {
    return students[i];
}
Student ClassSystem::getStudentByName(string name) {
    for (auto& student : students) {
        if (student.getName() == name) {
            return student;
        }
    }
    return Student("");
}
void ClassSystem::signIn(string name) {
    for (auto& student : students) {
        if (student.getName() == name) {
            student.removeAbsent();
            student.addPresent();
            break;
        }
    }
}