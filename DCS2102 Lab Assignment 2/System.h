#pragma once
#include <string>
#include "Student.h"
#include "Admin.h"
#include "Course.h"

using namespace std;

class System {
private:
	Student* students = nullptr;
	int studentCount = 0;

	Admin* admins = nullptr;
	int adminCount = 0;

	Course* courseHead = nullptr;
	int courseCount = 0;
public:
	System() {}

	void printCourses() {
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
		if (courseCount > 0) {
			cout << "Select from 1 - " << courseCount << " to enroll: ";
		} else {
			cout << "No courses available." << endl;
		}
	}

	void addCourse(string courseCode, string courseName) {
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
	}

	void removeCourse() {
		
	}

	void findCourse() {

	}

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

		cout << username << " successfully created." << endl << endl;
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

	Student* findStudent(string username) {
		for (int i = 0; i < studentCount; i++) {
			if (students[i].getUsername() == username) {
				return &students[i];
			}
		}
	}

	void studentEnrollment(Student* student, int selection) {
		Course* targetCourse = courseHead;

		for (int i = 0; i < selection - 1; i++) {
			targetCourse = targetCourse->next;
		}

		if (targetCourse != nullptr) {
			student->enroll(targetCourse);
		} else {
			cout << "Invalid selection." << endl;
		}
	}
};