#pragma once
#include <string>
#include "Course.h" // Needs to know what a Course is

using namespace std;

class Student {
private:
    string password;
    string username;

    Course* courseHead = nullptr;
    int enrolledCount = 0;
    int MAX_COURSES = 6;

public:
    Student();
    Student(string username, string password);
    ~Student(); 

    void enroll(Course* course);
    void dropCourse(string courseCode);
    void enrolledCourses();
    string getUsername();
    string getPassword();
};