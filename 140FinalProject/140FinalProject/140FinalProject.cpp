#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int const MAIN_MENU_WIDTH = 10;

void makeLogInScreen();
void createNewAcount();
void logIn();
void quit();

int main()
{
    makeLogInScreen();

}


void makeLogInScreen()
{
    int tellerInput;

    cout << "Hello and Welcome to Lake Champlain Banking teller system!" << endl; 
    cout << endl;
    
    do 
    {
        cout << "Please select an option." << endl;
        cout << setw(MAIN_MENU_WIDTH) << left << "1: Create new acount" << endl;
        cout << setw(MAIN_MENU_WIDTH) << left << "2: log into existing acount" << endl;
        cout << setw(MAIN_MENU_WIDTH) << left << "3: quit" << endl;
        cout << endl;

        cin >> tellerInput;

        if (tellerInput == 1)
        {
            createNewAcount();
        }
        else if (tellerInput == 2)
        {
            logIn();
        }
        else if (tellerInput == 3)
        {
            quit();
        }
        else
        {
            cout << "Error, bad input" << endl;
            cout << endl;
        } 
    } while (tellerInput < 1 || tellerInput > 3);
}
    

void createNewAcount()
{

}

void logIn()
{

}

void quit()
{
    cout << "exiting program" << endl;
}
