#pragma once
#include <string>
using namespace std;

const int FullEnroll = 5;

class Student {
private:
	string name, id;
	string* enrollCourse;
	int courseCount;
	string password;
	string username;

public:
	Student() { // Default constructor for dynamic arrays (how tedious)
		name = "";
		id = "";
		courseCount = 0;
		enrollCourse = new string[FullEnroll];
		this->username = "";
		this->password = "";
	};

	~Student() {
		delete[]enrollCourse;
	}

	void setInfo(string SName, string SId) {
		name = SName;
		id = SId;
	}

	string getName() {
		return name;
	}

	string getId() {
		return id;
	}

	int getCourseCount(){
		return courseCount;
	}

	void enrollCourses(string courseId) {
		if (courseCount >= FullEnroll) {
			cout << "Your Course is Full." << endl;
			return;
		}
		for (int i = 0; i < courseCount; i++) {
			if (enrollCourse[i] == courseId) {
				cout << "You have Already Enroll This Course." << endl;
				return;
			}
		}
		enrollCourse[courseCount++] = courseId;
		cout << " Enroll Done! " << courseCount << "/" << FullEnroll << endl;
	}

	void dropCourses(string courseId) {
		for (int i = 0; i < courseCount; i++) {
			if (enrollCourse[i] == courseId) {
				for (int j = i; j < courseCount; j++) {
					enrollCourse[j] = enrollCourse[j + 1];
					courseCount--;
					cout << "Dropped Done! " << courseCount << "/" << FullEnroll << endl;
					return;
				}
			}
			else cout << "Course Not Found" << endl;
		}
	}

	void viewCourse() {
		cout << "NAME : " << name << " ID : " << id << endl;
		if (courseCount == 0) {
			cout << "Not Course Enroll yet.";
		}
		else {
			for (int i = 0; i < courseCount; i++) {
				cout << " - " << enrollCourse[i] << endl;
			}
		}
	}

	Student(string username, string password) {
		this->username = username;
		this->password = password;
	}

	string getUsername() {
		return this->username;
	}

	string getPassword() {
		return this->password;
	}
};
