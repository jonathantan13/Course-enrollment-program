#pragma once
#include <string>
#include "Course.h"

using namespace std;

class Student;
class Admin;

class System {
private:
    Student* students = nullptr;
    int studentCount = 0;

    Admin* admin; 

    Course* courseHead = nullptr;
    int courseCount = 0;
public:
    System();
    ~System(); 

    bool loginAdmin(string username, string password);
    Admin* findAdmin();

    void printCourses(bool enroll = false);
    void addCourse(string courseCode, string courseName);
    void removeCourse(string courseCode);

    void registerStudent();
    bool loginStudent(string username, string password);
    Student* findStudent(string username);
    void studentEnrollment(Student* student, int selection);
};