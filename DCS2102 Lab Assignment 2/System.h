#pragma once
#include <string>
#include "Student.h"
#include "Admin.h"

using namespace std;

struct Course {
	std::string courseName;
	int capacity;
	int numberOfStudents;
};

class System {
private:
	Course* courses = nullptr;
	int courseCount = 0;

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

	void loginStudent(string username, string password) {
		// I'm not sure if this is the most efficient way to do it, but this is the only way I know

		for (int i = 0; i < studentCount; i++) {
			if (username == students[i].getUsername()) {
				cout << "User found";
				return;
			}
		}

		cout << "User not found";
	}
};