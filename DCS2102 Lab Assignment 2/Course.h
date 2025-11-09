#pragma once
#include <string>

using namespace std;

// This struct is used by all three classes
struct Course {
	string courseCode;
	string courseName;
	Course* next;

	Course(string c, string n, Course* np = nullptr) : courseCode(c), courseName(n), next(np) {}
};
