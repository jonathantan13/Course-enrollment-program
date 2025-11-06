// DCS2102 Lab Assignment 2.cpp : Jonathan Tan

#include <iostream>
#include "System.h"
using namespace std;

int main()
{
    System* system = new System();

    system->registerStudent();
    system->loginStudent("test", "test123");
}

// TODO:
// 1) Create 3 classes: Student, Admin, and System. 
// All instances of the Student class can enroll in courses. 
// All instances of the Admin class will be allowed to add or remove courses.
// All instances of the System will keep track of all users and admins as well as the available courses