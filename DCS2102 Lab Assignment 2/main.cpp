// DCS2102 Lab Assignment 2.cpp : Jonathan Tan

#include <iostream>
#include "System.h"
#include "Student.h"
#include "Admin.h"

using namespace std;

void studentMenu(System&, string);
void adminMenu(System&);

int main()
{
    System* system = new System();
    int selection;

    // Some starting courses for test purposes (parameters: courseCode, courseName)
    cout << "(FOR TESTING PURPOSES)" << endl;
    system->addCourse("DS", "Data Structures");
    system->addCourse("NW", "Networking");
    system->addCourse("SA", "System Analysis");
    cout << endl;

    while (true) {
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
            cout << "(For testing purposes, the username is admin and password is admin123)" << endl;

            string username, password;

            cout << "Enter username: ";
            cin >> username;

            cout << "Password: ";
            cin >> password;

            if (system->loginAdmin(username, password)) adminMenu(*system);
            else cout << "Incorrect credentials!" << endl;
        } 
        else if (selection == 4) break;
        else cout << "Invalid selection, please try again!" << endl;
    }
}

void studentMenu(System& system, string username) {
    int selection;
    Student* student = system.findStudent(username);
    
    cout << endl;
    while (true) {
        cout << "\n-------------------------------------" << endl;
        cout << "Student Menu (Logged in as: " << username << ")" << endl;
        cout << "---------------------------------------" << endl;
        cout << "1. Enroll in a course" << endl;
        cout << "2. Drop a course" << endl;
        cout << "3. View enrolled courses" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter choice: ";

        cin >> selection;

        if (selection == 1) {
            int courseSelection;

            system.printCourses(true);
            cin >> courseSelection;

            system.studentEnrollment(student, courseSelection);
            
        } else if (selection == 2) {
            string courseCode;

            student->enrolledCourses();

            cout << "Enter course code you wish to drop: ";
            cin >> courseCode;

            student->dropCourse(courseCode);
        } 
        else if (selection == 3) student->enrolledCourses();
        else if (selection == 4) break;
        else cout << "Invalid selection, please try again!" << endl;
    }
    return;
}

void adminMenu(System& system) {
    int selection;

    cout << endl;
    while (true) {
        cout << "\n-------------------------------------" << endl;
        cout << "Course menu (Logged in as admin)" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1. Add course" << endl;
        cout << "2. Remove course" << endl;
        cout << "3. View all courses" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter choice: ";

        cin >> selection;

        if (selection == 1) {
            string courseName, courseCode;

            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, courseName);

            cout << "Enter course code: ";
            cin >> courseCode;

            system.addCourse(courseCode, courseName);
        }
        else if (selection == 2) {
            string courseCode;

            cout << "Enter course code you wish to remove: ";
            cin >> courseCode;

            system.removeCourse(courseCode);
        }
        else if (selection == 3) system.printCourses(false);
        else if (selection == 4) break;
        else cout << "Invalid selection, please try again!" << endl;
    }
    return;
}
