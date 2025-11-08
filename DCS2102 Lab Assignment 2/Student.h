#pragma once
#include <string>
using namespace std;

class Student {
private:
	string password;
	string username;

	int MAX_COURSES = 6;
	string courses[6];
	int enrolledCount = 0;

public:
	Student() {
		this->username = "";
		this->password = "";
	};

	Student(string username, string password) {
		this->username = username;
		this->password = password;
	}

	void enroll(string course) {
		if (enrolledCount >= MAX_COURSES) {
			cout << "You have exceeded the number of enrollments! Please drop a course to enroll." << endl;
			return;
		}
		
		for (int i = 0; i < MAX_COURSES; i++) {
			if (course == courses[i]) {
				cout << "You have already enrolled in this course!" << endl;
				return;
			}
		}

		courses[enrolledCount] = course;
		enrolledCount++;

		cout << "Enrolled in " << course << ". Total courses enrolled: " << enrolledCount;
	}

	void dropCourse(string course) {

	}

	void enrolledCourses() {
		cout << "\n-------------------------------------" << endl;
		cout << "Enrolled courses: " << endl;
		for (int i = 0; i < enrolledCount; i++) {
			cout << i + 1 << ". " << courses[i] << endl;
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
