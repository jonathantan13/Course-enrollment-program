#pragma once
#include <string>
#include "Student.h"
#include "Admin.h"

struct Course {
	std::string courseName;
	int capacity;
	int numberOfStudents;
};

class System {
private:
	Course* courses[1];
	Student* students[1];
	Admin* admins[1];
};