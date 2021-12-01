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
            updateInfo();
            break;
        case 4:
            searchInfo();
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
