#pragma once
#include <string>
using namespace std;

//Allows a user to register by providing their personal information
void registerUser();

//Prompts the user to enter their usernameand password for login
void login();


bool checkLoginUser(const string& name, const string& password);

bool checkLoginTransaction(const string& name);