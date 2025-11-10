#include "Admin.h"    
#include "System.h"   

using namespace std;

Admin::Admin() {
    username = "admin";
    password = "admin123";
}

void Admin::addCourse(System& system) {
    string courseName, courseCode;

    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, courseName);

    cout << "Enter course code: ";
    cin >> courseCode;

    system.addCourse(courseCode, courseName);
}

void Admin::removeCourse(System& system) {
    string courseCode;

    cout << "Enter course code you wish to remove: ";
    cin >> courseCode;

    system.removeCourse(courseCode);
}

string Admin::getUsername() {
    return username;
}

string Admin::getPassword() {
    return password;
}