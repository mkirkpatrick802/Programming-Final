#include "bank.h"

int main()
{
    int menuSelection = 0;
    do
    {
        bool tellerLogin();
    } while (tellerLogin() == false);
    
    welcomeMessage();
   

    while (menuSelection != 3)
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
            login();
            break;
        case 3:
            quit();
            break;
        default:
            break;
        }
    }
    
}
