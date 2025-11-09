#pragma once
#include <string>
#include "Course.h"
using namespace std;

class Student {
private:
	string password;
	string username;

	Course* courseHead = nullptr;
	int enrolledCount = 0;
	int MAX_COURSES = 6;

public:
	Student() {
		this->username = "";
		this->password = "";
	};

	Student(string username, string password) {
		this->username = username;
		this->password = password;
	}

	void enroll(Course* course) {
		if (enrolledCount >= MAX_COURSES) {
			cout << "You have exceeded the number of enrollments! Please drop a course to enroll." << endl;
			return;
		}

		Course* current = courseHead;

		while (current != nullptr) {
			if (current->courseCode == course->courseCode) {
				cout << "You have already enrolled in this course!" << endl;
				return;
			}
			current = current->next;
		}

		Course* newCourse = new Course(course->courseCode, course->courseName);

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

		enrolledCount++;
		cout << "Enrolled in " << course->courseName << ". Total courses enrolled: " << enrolledCount;
	}

	void dropCourse(string courseCode) {
		if (courseHead == nullptr) {
			cout << "You have not enrolled in any courses yet." << endl;
			return;
		}

		if (courseHead->courseCode == courseCode) {
			Course* nodeToDelete = courseHead;
			courseHead = courseHead->next;

			cout << nodeToDelete->courseName << " successfully dropped." << endl;
			delete nodeToDelete;
			enrolledCount--;
			return;
		}

		Course* previous = courseHead;
		Course* current = courseHead->next;

		while (current != nullptr && current->courseCode != courseCode) {
			previous = current;
			current = current->next;
		}

		if (current == nullptr) {
			cout << "You are not enrolled in " << courseCode << endl;
		} else {
			previous->next = current->next;

			cout << current->courseName << " successfully dropped." << endl;
			delete current;
			enrolledCount--;
		}
	}

	void enrolledCourses() {
		Course* current = courseHead;
		int i = 1;

		cout << "\n-------------------------------------" << endl;
		cout << "Enrolled courses: " << endl;
		while (current != nullptr) {
			cout << i << ". " << current->courseName << " (" << current->courseCode << ")" << endl;
			current = current->next;
		}
		cout << "-------------------------------------" << endl;
	}

	string getUsername() {
		return this->username;
	}

	string getPassword() {
		return this->password;
	}
};
