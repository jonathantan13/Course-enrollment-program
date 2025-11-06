// DCS2102 Lab Assignment 2.cpp : Jonathan Tan

#include <iostream>
#include "System.h"
using namespace std;

int main()
{
    System* system = new System();
    bool running = true;
    int selection;

    while (running) {
        cout << "----------------------------------" << endl;
        cout << "Course enrollment program" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Student register" << endl;
        cout << "2. Student login" << endl;
        cout << "3. Admin login" << endl;
        cout << "Make your selection (1 - 3): ";
        cin >> selection;
        switch (selection) {
        case 1: system->registerStudent(); break;
        case 2: system->loginStudent(); break;
        case 3: cout << "Waiting for Anderson's part"; break;
        default: cout << "Invalid selection, please try again!" << endl;
        }
    }
}

// TODO:
// 1) Create 3 classes: Student, Admin, and System. 
// All instances of the Student class can enroll in courses. 
// All instances of the Admin class will be allowed to add or remove courses.
// All instances of the System will keep track of all users and admins as well as the available courses