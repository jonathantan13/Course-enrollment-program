#pragma once
#include <string>
#include "Student.h"
#include "Admin.h"

using namespace std;

class System {
private:
	string courses[5] = {"Data structures", "Networking", "Data forensic", "Ethical hacking", "System Analysis"};
	int courseCount = 5;

	Student* students = nullptr;
	int studentCount = 0;

	Admin* admins = nullptr;
	int adminCount = 0;

public:
	System() {}

	void registerStudent() {
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

		cout << username << " successfully created." << endl;
	}

	bool loginStudent(string username, string password) {
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

	void availableCourses() {
		cout << "\n-------------------------------------" << endl;
		cout << "Available courses: " << endl;
		for (int i = 0; i < courseCount; i++) {
			cout << i + 1 << ". " << courses[i] << endl;
		}
		cout << "-------------------------------------" << endl;
		cout << "Select from 1 - " << courseCount << " to enroll: ";
	}

	Student* findStudent(string username) {
		for (int i = 0; i < studentCount; i++) {
			if (students[i].getUsername() == username) {
				return &students[i];
			}
		}
	}

	void studentEnrollment(Student* student, int selection) {
		student->enroll(courses[selection - 1]);
	}
};