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

#include "bank.h"

int main()
{
    int accountFound = 0;
    bool accountLogin = false;
    int menuSelection = 0;
    do
    {
        bool tellerLogin();
    } while (tellerLogin() == false);
    
    welcomeMessage();
   
    while (menuSelection != 3 && !accountLogin)
    {
        do
        {
            menuSelection = mainScreen();
        } while (menuSelection < 1 || menuSelection > 3);

        switch (menuSelection) // Menu Selection
        {
        case 1:
            createNewAccount();
            break;
        case 2:
            accountFound = login();
            accountLogin = true;
            break;
        case 3:
            quit();
            break;
        default:
            break;
        }
    }

    bool quit1 = false;
    
    while (accountLogin && accountFound != 0 && quit1 == false) 
    {
        float balance = 0;
        int input = 0;

        do
        {
            displayOptions();

            cin >> input;

        } while (input < 1 || input > 7);

        switch (input)
        {
        case 1:
            balance = checkBalance(accountFound);
            deposit(balance, accountFound);
            break;
        case 2: 
            balance = checkBalance(accountFound);
            withdraw(balance, accountFound);
            break;
        case 3:
            updateInfo(accountFound);
            break;
        case 4:
            searchInfo(accountFound);
            break;
        case 5: 
            checkBalance(accountFound);
            break;
        case 6: 
            deleteAccount();
            break;
        case 7:
            quit();
            quit1 = true;
            break;
        }
    }
}
