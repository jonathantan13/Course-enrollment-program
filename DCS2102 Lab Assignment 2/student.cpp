#include "Student.h" 
#include <iostream>  

using namespace std;

Student::Student() {
    this->username = "";
    this->password = "";
}

Student::Student(string username, string password) {
    this->username = username;
    this->password = password;
}

Student::~Student() {
    Course* current = courseHead;
    while (current != nullptr) {
        Course* courseToDelete = current;
        current = current->next;
        delete courseToDelete;
    }
}

void Student::enroll(Course* course) {
    if (enrolledCount >= MAX_COURSES) {
        cout << "You have exceeded the number of enrollments! Please drop a course to enroll." << endl;
        return;
    }

    Course* current = courseHead;

    while (current != nullptr) {
        if (current->courseCode == course->courseCode) {
            cout << "You have already enrolled in this course!" << endl;
            return;
        }
        current = current->next;
    }

    Course* newCourse = new Course(course->courseCode, course->courseName);

    if (courseHead == nullptr) {
        courseHead = newCourse;
    }
    else {
        Course* current = courseHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newCourse;
    }

    enrolledCount++;
    cout << "Enrolled in " << newCourse->courseName << ". Total courses enrolled: " << enrolledCount << endl;
}

void Student::dropCourse(string courseCode) {
    if (courseHead == nullptr) {
        cout << "You have not enrolled in any courses yet." << endl;
        return;
    }

    if (courseHead->courseCode == courseCode) {
        Course* courseToDelete = courseHead;
        courseHead = courseHead->next;

        cout << courseToDelete->courseName << " successfully dropped." << endl;
        delete courseToDelete;
        enrolledCount--;
        return;
    }

    Course* previous = courseHead;
    Course* current = courseHead->next;

    while (current != nullptr && current->courseCode != courseCode) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "You are not enrolled in " << courseCode << endl;
    }
    else {
        previous->next = current->next;
        cout << current->courseName << " successfully dropped." << endl;
        delete current;
        enrolledCount--;
    }
}

void Student::enrolledCourses() {
    Course* current = courseHead;
    int i = 1;

    cout << "\n-------------------------------------" << endl;
    cout << "Enrolled courses (" << enrolledCount << "/" << MAX_COURSES << "): " << endl;

    if (current == nullptr) {
        cout << "(No courses enrolled)" << endl;
    }
    else {
        while (current != nullptr) {
            cout << i << ". " << current->courseName << " (" << current->courseCode << ")" << endl;
            current = current->next;
            i++;
        }
    }
    cout << "-------------------------------------" << endl;
}

string Student::getUsername() {
    return this->username;
}

string Student::getPassword() {
    return this->password;
}