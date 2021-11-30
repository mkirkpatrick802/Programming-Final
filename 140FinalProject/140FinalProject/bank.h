/*
Author: Michael Kirkpatrick, John Groton
Class : CSI-140-01/02 : Intro to Programming
Assignment : Final Project
Date Assigned : 11/8/21
Due Date : 12/6/21 11:59PM

Description :
You have been hired as the lead programmer for a bank. Your immediate task is to create a new system for the bank tellers for their daily tasks. Your system must allow the tellers to perform the following tasks. However, in order to perform these tasks, the bank teller must be logging into the system first.

Certification of Authenticity :

I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/

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
void login();
void displayOptions();
void quit();
bool tellerLogin();
int newAccountNumber();
int convertStrToInt(string stringValue);
int numberOfLines(string fileName);
void deposit(float& balance, string acountNum);
void withdraw(float& balance, string acountNum);
void updateInfo();
void searchInfo();
void checkBalance(float balance);
void deleteAcount();