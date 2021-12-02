// Michael, John

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

void welcomeMessage();
int mainScreen();
void createNewAccount();
int login();
void displayOptions();
void quit();
bool tellerLogin();
int newAccountNumber();
int convertStrToInt(string stringValue);
int numberOfLines(string fileName);
void deposit(float balance, int accountNum);
void withdraw(float balance, int accountNum);
void updateInfo();
void searchInfo();
float checkBalance(int accountNum);
void deleteAccount();