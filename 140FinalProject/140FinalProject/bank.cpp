#include "bank.h"

void welcomeMessage()
{
    cout << endl;
    cout << "Beglückwünschung" << endl;
    cout << "Hello and Welcome to Lake Champlain Banking teller system!" << endl;
    cout << endl;
}

int mainScreen()
{
    int const MAIN_MENU_WIDTH = 10;
    int tellerInput;

    cout << endl;
    cout << "Please select an option." << endl;
    cout << setw(MAIN_MENU_WIDTH) << left << "1: Create new account" << endl;
    cout << setw(MAIN_MENU_WIDTH) << left << "2: Log into existing account" << endl;
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


void createNewAccount()
{
    string social;
    string name;
    string address;
    string phoneNumber;
    ofstream fout;
    fout.open("accounts.dat", ios_base::app);
    if (!fout.is_open())
    {
        cout << "Account file cannot be found" << endl;
        return;
    }

    fout << newAccountNumber() << endl;

    cout << "Please Input Social Security Number: ";
    cin.ignore();
    getline(cin, social);
    fout << social << endl;

    cout << "Please Input Your Full Name: ";
    cin.ignore();
    getline(cin, name);
    fout << name << endl;

    cout << "Please Input Your Address: ";
    cin.ignore();
    getline(cin, address);
    fout << address << endl;

    cout << "Please Input Your Phone Number: ";
    cin.ignore();
    getline(cin, phoneNumber);
    fout << phoneNumber << endl;

    fout << " " << endl;
    fout.close();
}

void login()
{
    string soccialSecNum;

    cout << "Please enter customer's Social Secrity Number: ";
    getline(cin, soccialSecNum);

    ifstream fin;
    fin.open("accounts.dat");
    if (!fin.is_open())
    {
        cout << "Cannot find acount" << endl;
    }



    


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

    fin >> tellerIdActual;
    fin >> tellerIdPassActual;

    cout << "Enter teller ID: ";
    cin >> tellerIdInput;

    cout << "Enter teller Password: ";
    cin >> tellerPassInput;

    if (tellerIdInput == tellerIdActual && tellerPassInput == tellerIdPassActual)
    {
        return true;
    }
    else
    {
        return false;
    }

    fin.close();
}

int newAccountNumber()
{
    int accountNumber = 1;

    ifstream fin;
    fin.open("accounts.dat");
    if (!fin.is_open())
    {
        cout << "Account file cannot be found" << endl;
        return 1;
    }

    int i;
    for (i = 1; i <= numberOfLines("accounts.dat"); i++)
    {
        string line;
        getline(fin, line);
        if (convertStrToInt(line) != 0)
        {
            accountNumber = convertStrToInt(line) + 1;
        }
    }
    ofstream fout;
    fout.open(to_string(accountNumber) + ".dat");
    fout.close();
    fin.close();
    return accountNumber;
}

int numberOfLines(string fileName) 
{
    ifstream fin;
    fin.open(fileName);

    int numLines = 0;
    string unused;
    while (getline(fin, unused))
    {
        ++numLines;
    }

    return numLines;
}

int convertStrToInt(string stringValue)
{
    int intValue;
    stringstream str;

    for (char i : stringValue) 
    {
        if (isdigit(i) == 0) 
        {
            return 0;
        }
    }

    str << stringValue;

    str >> intValue;

    return intValue;
}