#pragma once
#include <string>
using namespace std;

//Allows a user to register by providing their personal information
void registerUser();

//Prompts the user to enter their usernameand password for login
void login();

// Function to check if a user with a given name and password exists in the list
bool checkLoginUser(const string& name, const string& password);

// Function to check if a user with a given name exists in the list
bool checkLoginTransaction(const string& name);