#pragma once
#include <string>
using namespace std;

class Student {
private:
	string password;
	string username;
public:
	Student() { // Default constructor for dynamic arrays (how tedious)
		this->username = "";
		this->password = "";
	};

	Student(string username, string password) {
		this->username = username;
		this->password = password;
	}

	string getUsername() {
		return this->username;
	}
};