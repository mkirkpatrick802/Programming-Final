/*
Author: Michael Kirkpatrick, John Groton
Class : CSI-140-01/02 : Intro to Programming
Assignment : Module-06-Assignment 2A
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
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int mainScreen();
void createNewAcount();
void login();
void quit();
bool tellerLogin();


int main()
{
    int menuSelection = 0;
    do
    {
        bool tellerLogin();
    } while (tellerLogin() == false);
    

    do 
    {
        menuSelection = mainScreen();
    } while (menuSelection < 1 || menuSelection > 3);

    switch (menuSelection) // Menu Selection
    {
        case 1:
            createNewAcount();
            break;
        case 2:
            login();
            break;
        case 3:
            quit();
            break;
        default:
            break;
    }
}


int mainScreen()
{
    int const MAIN_MENU_WIDTH = 10;
    int tellerInput;

    cout << endl;
    cout << "Hello and Welcome to Lake Champlain Banking teller system!" << endl; 
    cout << endl;

    cout << "Please select an option." << endl;
    cout << setw(MAIN_MENU_WIDTH) << left << "1: Create new acount" << endl;
    cout << setw(MAIN_MENU_WIDTH) << left << "2: Log into existing acount" << endl;
    cout << setw(MAIN_MENU_WIDTH) << left << "3: Quit" << endl;
    cout << endl;
    
    cin >> tellerInput;

    while (cin.fail()) // Makes Sure That the input is an Int
    {
        cin.clear();
        cin.ignore();
        cout << endl;
        cout << "Please Enter Correct Input" << endl;
    }

    return tellerInput;
}
    

void createNewAcount()
{

}

void login()
{

}

void quit()
{
    cout << "Exiting Program" << endl;
}

bool tellerLogin()
{
    string tellerIdInput;
    string tellerPassInput;

    string tellerIdActual;
    string tellerIdPassActual;

    ifstream fin;
    fin.open("tellers.dat");
    
    if (!fin.is_open())
    {
        cout << "Teller's file cannot be found" << endl;
        return false;
    }


}
