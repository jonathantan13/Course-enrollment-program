#pragma once
#include <string>
#include <iostream>

class System; 

using namespace std;

class Admin {
private:
    string username;
    string password;

public:
    Admin();

    void addCourse(System& system);
    void removeCourse(System& system);
    string getUsername();
    string getPassword();
};