#include "System.h"   
#include "Student.h"  
#include "Admin.h"    
#include <iostream>

using namespace std;

System::System() {
    this->admin = new Admin(); 
}

System::~System() {
    delete admin;        
    delete[] students;   

    Course* current = courseHead;
    while (current != nullptr) {
        Course* courseToDelete = current;
        current = current->next;
        delete courseToDelete;
    }
    cout << "System shutting down, all memory freed." << endl;
}

bool System::loginAdmin(string username, string password) {
    return username == admin->getUsername() && password == admin->getPassword();
}

Admin* System::findAdmin() {
    return this->admin;
}

void System::printCourses(bool enroll) {
    cout << "\n-------------------------------------" << endl;
    cout << "Available courses: " << endl;

    int i = 1;
    Course* current = courseHead;

    while (current != nullptr) {
        cout << i << ". " << current->courseName << " (" << current->courseCode << ")" << endl;
        current = current->next;
        i++;
    }

    cout << "-----------------------------------" << endl;
    if (enroll == true) {
        if (courseCount > 0) {
            cout << "Select from 1 - " << courseCount << " to enroll: ";
        }
        else {
            cout << "No courses available." << endl;
        }
    }
}

void System::addCourse(string courseCode, string courseName) {
    Course* newCourse = new Course(courseCode, courseName);

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
    courseCount++;
    cout << "Course '" << courseName << "' added to system." << endl;
}

void System::removeCourse(string courseCode) {
    if (courseHead == nullptr) {
        cout << "There are no courses to drop." << endl;
        return;
    }

    if (courseHead->courseCode == courseCode) {
        Course* courseToDelete = courseHead;
        courseHead = courseHead->next;
        cout << courseToDelete->courseName << " successfully removed." << endl;
        delete courseToDelete;
        courseCount--;
        return;
    }

    Course* previous = courseHead;
    Course* current = courseHead->next;

    while (current != nullptr && current->courseCode != courseCode) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << courseCode << " does not exist!" << endl;
    }
    else {
        previous->next = current->next;
        cout << current->courseName << " successfully removed." << endl;
        delete current;
        courseCount--;
    }
}

void System::registerStudent() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    for (int i = 0; i < studentCount; i++) {
        if (username == students[i].getUsername()) {
            cout << "Username is taken, please use a unique username!";
            return;
        }
    }

    cout << "Password: ";
    cin >> password;

    Student newStudent(username, password);

    Student* newStudents = new Student[studentCount + 1];
    for (int i = 0; i < studentCount; i++) {
        newStudents[i] = students[i];
    }
    newStudents[studentCount] = newStudent;
    delete[] students;
    students = newStudents;
    studentCount++;

    cout << username << " successfully created." << endl << endl;
}

bool System::loginStudent(string username, string password) {
    for (int i = 0; i < studentCount; i++) {
        if (username == students[i].getUsername()) {
            if (password == students[i].getPassword()) {
                cout << "Welcome, " << username << endl;
                return true;
            }
        }
    }
    cout << "\nIncorrect credentials, please try again!" << endl;
    return false;
}

Student* System::findStudent(string username) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getUsername() == username) {
            return &students[i];
        }
    }
    return nullptr; 
}

void System::studentEnrollment(Student* student, int selection) {
    if (selection <= 0 || selection > courseCount) {
        cout << "Invalid selection." << endl;
        return;
    }

    Course* targetCourse = courseHead;

    for (int i = 1; i < selection && targetCourse != nullptr; i++) {
        targetCourse = targetCourse->next;
    }

    if (targetCourse != nullptr) {
        student->enroll(targetCourse);
    }
    else {
        cout << "Invalid selection." << endl;
    }
}