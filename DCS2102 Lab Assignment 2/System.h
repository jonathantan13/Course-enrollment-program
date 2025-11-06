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

	bool loginStudent() {
		// I'm not sure if this is the most efficient way to do it, but this is the only way I know
		string username, password;

		cout << "Enter username: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;

		for (int i = 0; i < studentCount; i++) {
			if (username == students[i].getUsername()) {
				if (password == students[i].getPassword()) {
					cout << "Welcome, " << username << endl;
					return true;
				}
			}
		}

		cout << "\nIncorrect credentials, please try again!";
		return false;
	}

	void studentEnroll(string username) { // Assuming user has logged in
		cout << "Available courses: " << endl;
		for (int i = 0; i < studentCount; i++) {
			cout << i + 1 << ". " << courses[i] << endl;
		}
	}
};