// Michael, John

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdio.h>
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
void updateInfo(int accountNum);
void searchInfo(int accountNum);
float checkBalance(int accountNum);
void deleteAccount(int accountNum);
void moveInfo(int option, int accountNum);