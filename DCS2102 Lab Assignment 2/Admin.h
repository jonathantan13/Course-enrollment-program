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
    string getUsername();
    string getPassword();
};