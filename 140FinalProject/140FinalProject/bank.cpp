#include "bank.h"

///////////////////////
//////// START ////////
///////////////////////

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

/////////////////////////////////
//////// Create Accounts ////////
/////////////////////////////////

void createNewAccount()
{
    stringstream str;
    string social;
    string name;
    string address;
    string phoneNumber;
    int j = 0;
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
    for (char i : social) 
    {
        if (isdigit(i)) 
        {
            str << i;
            j++;
            if (j == 3) 
            {
                str << "-";
            }
            else if (j == 5)
            {
                str << "-";
            }
            else if (j == 9)
            {
                break;
            }
        }
    }
    str >> social;
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
    getline(cin, phoneNumber);
    string buildPhone;
    int p = 0;
    for (char i : phoneNumber) // NOT WORKING AND HAVE NO FUCKING IDEA WHY
    {
        if (isdigit(i))
        {
            
            p++;
            if (p == 1)
            {
                // str << "("
                buildPhone += "(";
            }
            else if (p == 4)
            {
                // str << ")"
                buildPhone += ")-";
            }
            else if (p == 7)
            {
                // str "-"
                buildPhone += "-";
            }

            buildPhone += i;

            if (p == 10)
            {
                break;
            }
            
        }
    }
    phoneNumber = buildPhone;
    fout << phoneNumber << endl;

    fout << " " << endl;
    fout.close();
}

int newAccountNumber()
{
    int num = 0;
    string lastAccount[6];
    int accountNumber = 1;
    const int STARTING_BALANCE = 0;

    ifstream fin;
    fin.open("accounts.dat");
    if (!fin.is_open())
    {
        cout << "Account file cannot be found" << endl;
        return 1;
    }

    int i;
    for (i = 0; i < numberOfLines("accounts.dat"); i++)
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
    fout << STARTING_BALANCE;

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

///////////////////////////////////
//////// Login To Account ////////
//////////////////////////////////


int login()
{
    string accountNum;

    cout << "Please enter account number: ";
    cin >> accountNum;
    cin.ignore();

    ifstream fin;
    fin.open(accountNum + ".dat");
    if (!fin.is_open())
    {
        cout << "Cannot find account file" << endl;
        return 0;
    }
    else
    {
        cout << "Login succesfull, please select an option" << endl;
    }

    return convertStrToInt(accountNum);
}

void displayOptions()
{
    cout << endl;
    cout << "1: Deposit" << endl;
    cout << "2: Withdraw" << endl;
    cout << "3: Update Info" << endl;
    cout << "4: Serach for Info" << endl;
    cout << "5: Check Balance" << endl;
    cout << "6: Delete acount" << endl;
    cout << "7: Quit" << endl;
    cout << endl;
}

void deposit(float balance, int accountNum)
{
    float depositAmount;

    ofstream fout;
    fout.open(accountNum + ".dat");

    if (!fout.is_open())
    {
        cout << "Failed to find deposit file" << endl;
    }

    cout << "How much do you wish to deposit?" << endl;
    cin >> depositAmount;

    balance = balance + depositAmount;
    fout << balance << endl;

    cout << "Your balance is now " << balance << endl;
}

void withdraw(float balance, int accountNum)
{
    float withdrawAmount;

    ofstream fout;
    fout.open(accountNum + ".dat");

    if (!fout.is_open())
    {
        cout << "Failed to find deposit file" << endl;
    }

    cout << "How much do you wish to withdraw?" << endl;
    cin >> withdrawAmount;

    if (withdrawAmount < balance)
    {
        balance = balance - withdrawAmount;
        fout << balance << endl;
        cout << "Your balance is now " << balance << endl;
    }
}

void updateInfo()
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

void searchInfo()
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

float checkBalance(int accountNum)
{
    float balance = 0;
    ifstream fin;
    fin.open(accountNum + ".dat");

    if (!fin.is_open())
    {
        cout << "Failed to find deposit file" << endl;
    }

    fin >> balance;
    
    cout << "Your balance is " << balance << endl;
    return balance;
}

void deleteAccount()
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

void quit()
{
    cout << "Exiting Program" << endl;
}

/////////////////////////
//////// Utility ////////
/////////////////////////

int convertStrToInt(string stringValue)
{
    int intValue = 0;
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