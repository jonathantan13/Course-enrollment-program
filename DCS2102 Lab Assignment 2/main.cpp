// DCS2102 Lab Assignment 2.cpp : Jonathan Tan

#include <iostream>
#include "System.h"
using namespace std;

void studentMenu(System&, string);
void adminMenu();

int main()
{
    System* system = new System();
    bool running = true;
    int selection;

    while (running) {
        cout << "----------------------------------" << endl;
        cout << "Course enrollment program" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Create student account" << endl;
        cout << "2. Student login" << endl;
        cout << "3. Admin login" << endl;
        cout << "4. Exit" << endl;
        cout << "Make your selection (1 - 3): ";
        cin >> selection;
        
        if (selection == 1) {
            system->registerStudent();
        } else if (selection == 2) {
            string username, password;

            cout << "Enter username: ";
            cin >> username;

            cout << "Password: ";
            cin >> password;

            if (system->loginStudent(username, password)) studentMenu(*system, username);
        } else if (selection == 3) {

        } else if (selection == 4) {
            break;
        } else {
            cout << "Invalid selection, please try again!" << endl;
        }
    }
}

void studentMenu(System& system, string username) {
    cout << "Hello from the student menu";
}

void adminMenu() {

}

// TODO:
// 1) Create 3 classes: Student, Admin, and System. 
// All instances of the Student class can enroll in courses. 
// All instances of the Admin class will be allowed to add or remove courses.
// All instances of the System will keep track of all users and admins as well as the available courses