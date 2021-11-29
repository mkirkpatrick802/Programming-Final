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
    string acountNum;

    cout << "Please enter acount number: ";
    cin >> acountNum;
    cin.ignore();

    ifstream fin;
    fin.open(acountNum + ".dat");
    if (!fin.is_open())
    {
        cout << "Cannot find acount file" << endl;
    }
    else
    {
        int input;

        float balance;
        fin >> balance;

        do
        {
            cout << "Login succesfull, please select an option" << endl;
            cout << endl;
            cout << "1: Deposit" << endl;
            cout << "2: Withdraw" << endl;
            cout << "3: Update Info" << endl;
            cout << "4: Serach for Info" << endl;
            cout << "5: Check Balance" << endl;
            cout << "6: Delete acount" << endl;
            cout << "7: Quit" << endl;
            cout << endl;
            
            cin >> input;

        } while (input < 1 || input > 7);

        if (input == 1)
        {
            deposit(balance, acountNum);
        }
        else if (input == 2)
        {
            withdraw(balance, acountNum);
        }
        else if (input == 3)
        {
            int option;

            cout << "What info do you want to change?" << endl;
            cout << endl;
            
            cout << "1: Social Security Number" << endl;
            cout << "2: Name" << endl;
            cout << "3: Address" << endl;
            cout << "4: Phone Number" << endl;
            cout << "5: Quit" << endl;
            cout << endl;

            cin >> option;
        }
        else if (input == 4)
        {
            int option;

            cout << "What info do you wish to search for?" << endl;
            cout << endl;

            cout << "1: Social Security Number" << endl;
            cout << "2: Name" << endl;
            cout << "3: Address" << endl;
            cout << "4: Phone Number" << endl;
            cout << "5: Quit" << endl;
            cout << endl;

            cin >> option;

        }
        else if (input == 5)
        {
            cout << "Your balance is " << balance << endl;
        }
        else if (input == 6)
        {
            string option;

            do
            {
                cout << "Are you sure you wish to delete you acount? y for yes n for no." << endl;
                cin >> option;
            } while (option != "y" || option != "Y" || option != "n" || option != "N");
            

            if (option == "y" || option == "Y")
            {

            }
            else if (option != "n" || option != "N")
            {

            }

        }
        else if (input == 7)
        {
            quit();
        }
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

void deposit(float & balance, string acountNum)
{
    float depositAmount;

    ofstream fout;
    fout.open(acountNum + ".dat");

    if (!fout.is_open())
    {
        cout << "Failed to find deposit file" << endl;
    }

    cout << "How much do you wish to deposit?" << endl;
    cin >> depositAmount;

    balance = balance + depositAmount;
    fout << balance + depositAmount << endl;

    cout << "Your balance is now " << balance << endl;
}

void withdraw(float & balance, string acountNum)
{
    float withdrawAmount;

    ofstream fout;
    fout.open(acountNum + ".dat");

    if (!fout.is_open())
    {
        cout << "Failed to find deposit file" << endl;
    }

    cout << "How much do you wish to withdraw?" << endl;
    cin >> withdrawAmount;

    if (withdrawAmount < balance)
    {
        fout << balance - withdrawAmount << endl;
        balance = balance - withdrawAmount;
        cout << "Your balance is now " << balance << endl;
    }
}