#include "Admin.h"    
#include "System.h"   

using namespace std;

Admin::Admin() {
    username = "admin";
    password = "admin123";
}

string Admin::getUsername() {
    return username;
}

string Admin::getPassword() {
    return password;
}