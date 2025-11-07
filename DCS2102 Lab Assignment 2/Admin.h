#pragma once
#include <string>
#include <iostream>
using namespace std;

class Admin {
private:
    string username;
    string password;

public:
    Admin() {
        username = "admin";
        password = "password";
    }

    Admin(string u, string p) {
        username = u;
        password = p;
    }

    string getUsername() { return username; }
    string getPassword() { return password; }

    void showMenu(string courses[], int& courseCount) {
        int choice;
        do {
            cout << "\n--- Admin Menu ---\n";
            cout << "1. View all courses\n";
            cout << "2. Add a course\n";
            cout << "3. Remove a course\n";
            cout << "4. Logout\n";
            cout << "Choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "\nAvailable courses:\n";
                for (int i = 0; i < courseCount; i++)
                    cout << i + 1 << ". " << courses[i] << endl;
                break;

            case 2: {
                if (courseCount >= 10) {
                    cout << "Course list full!\n";
                    break;
                }
                string newCourse;
                cout << "Enter course name: ";
                cin.ignore();
                getline(cin, newCourse);
                courses[courseCount++] = newCourse;
                cout << "Course added!\n";
                break;
            }

            case 3: {
                cout << "Enter course number to remove: ";
                int num;
                cin >> num;
                if (num < 1 || num > courseCount) {
                    cout << "Invalid course number!\n";
                    break;
                }
                for (int i = num - 1; i < courseCount - 1; i++)
                    courses[i] = courses[i + 1];
                courseCount--;
                cout << "Course removed!\n";
                break;
            }

            case 4:
                cout << "Logging out...\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }
        } while (choice != 4);
    }
};
