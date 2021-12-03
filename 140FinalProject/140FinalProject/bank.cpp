//Michael, John
// yo

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

    const int TELLER_WIDTH = 25;

    ifstream fin;
    fin.open("tellers.dat");
    if (!fin.is_open())
    {
        cout << "Teller's file cannot be found" << endl;
        return false;
    }

    fin >> tellerIdActual;
    fin >> tellerIdPassActual;

    cout << right << setw(TELLER_WIDTH) << "Enter teller ID: ";
    cin >> tellerIdInput;

    cout << right << setw(TELLER_WIDTH) << "Enter teller Password: ";
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
    const int CREATE_WIDTH = 40;

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

    cout << setw(CREATE_WIDTH) << right << "Please Input Social Security Number: ";
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

    cout << setw(CREATE_WIDTH) << right << "Please Input Your Full Name: ";
    cin.ignore();
    getline(cin, name);
    fout << name << endl;

    cout << setw(CREATE_WIDTH) << right << "Please Input Your Address: ";
    cin.ignore();
    getline(cin, address);
    fout << address << endl;

    cout << setw(CREATE_WIDTH) << right << "Please Input Your Phone Number: ";
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
                buildPhone += ")";
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

    cout << endl;
    cout << setw(CREATE_WIDTH) << right << "Account Successfully created!" << endl;
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
        cout << "Login successfull, please select an option" << endl;
    }

    return convertStrToInt(accountNum);
    fin.close();
}

void displayOptions()
{
    const int OPTIONS_WIDTH = 20;

    cout << endl;
    cout << right << setw(OPTIONS_WIDTH) << "1: Deposit" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "2: Withdraw" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "3: Update Info" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "4: Search for Info" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "5: Check Balance" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "6: Delete acount" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "7: Quit" << endl;
    cout << endl;
}

void deposit(float balance, int accountNum)
{
    float depositAmount;
    string accountName = to_string(accountNum) + ".dat";

    ofstream fout;
    fout.open(accountName);

    if (!fout.is_open())
    {
        cout << "Failed to find deposit file: " << accountName << endl;
    }

    cout << "How much do you wish to deposit?" << endl;
    cin >> depositAmount;

    balance = balance + depositAmount;
    fout << balance << endl;

    cout << "Your balance is now " << balance << endl;
    fout.close();
}

void withdraw(float balance, int accountNum)
{
    float withdrawAmount;
    string accountName = to_string(accountNum) + ".dat";

    ofstream fout;
    fout.open(accountName);

    if (!fout.is_open())
    {
        cout << "Failed to find deposit file: " << accountName << endl;
    }

    cout << "How much do you wish to withdraw?" << endl;
    cin >> withdrawAmount;

    if (withdrawAmount < balance)
    {
        balance = balance - withdrawAmount;
        fout << balance << endl;
        cout << "Your balance is now " << balance << endl;
    }
    fout.close();
}

void updateInfo(int accountNum)
{
    int option;

    const int OPTIONS_WIDTH = 20;

    cout << "What info do you want to change?" << endl;
    cout << endl;

    cout << right << setw(OPTIONS_WIDTH) << "1: Social Security Number" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "2: Name" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "3: Address" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "4: Phone Number" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "5: Quit" << endl;
    cout << endl;

    cin >> option;
}

void searchInfo(int accountNum)
{
    const int OPTIONS_WIDTH = 20;
    int option;
    string accountName = "accounts.dat";
    string line;
    bool accountFound = false;
    string accountInfo[10];

    ifstream fin;
    fin.open(accountName);

    cout << "What info do you wish to search for?" << endl;
    cout << endl;

    cout << right << setw(OPTIONS_WIDTH) << "1: Social Security Number" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "2: Name" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "3: Address" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "4: Phone Number" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "5: Quit" << endl;
    cout << endl;

    cin >> option;

    for (int i = 0; i < numberOfLines(accountName) && !accountFound; i++)
    {
        getline(fin, line);
        if (line == to_string(accountNum))
        {
            accountFound = true;
            for (int j = 0; j < 5; j++) 
            {
                getline(fin, line);
                accountInfo[j] = line;
            }
        }
    }

    switch (option)
    {
    case 1:
        cout << accountInfo[0] << endl;
        break;
    case 2:
        cout << accountInfo[1] << endl;
        break;
    case 3:
        cout << accountInfo[2] << endl;
        break;
    case 4:
        cout << accountInfo[3] << endl;
        break;
    case 5:
        cout << accountInfo[4] << endl;
        break;
    }
}

float checkBalance(int accountNum)
{
    float balance = 0;
    string accountName = to_string(accountNum) + ".dat";

    ifstream fin;
    fin.open(accountName);

    if (!fin.is_open())
    {
        cout << "Failed to find deposit file: " << accountName << endl;
    }

    fin >> balance;
    
    cout << "Your balance is " << balance << endl;
    return balance;
    fin.close();
}

void deleteAccount(int accountNum)
{
    string option;

   
    cout << "Are you sure you wish to delete your account? y for yes n for no." << endl;
    cin >> option;
    
    if (option == "y" || option == "Y")
    {
        string accountName = "accounts.dat";
        string line;
        bool accountFound = false;
        string accountInfo[10];
        string saveInfo[10];

        ifstream fin;
        fin.open(accountName);

        for (int i = 0; i < numberOfLines(accountName); i++)
        {

            getline(fin, line);


            if (line != to_string(accountNum))
            {

                ofstream fout;
                fout.open("Temp.txt");
                fout << line << endl;

                for (int p = 0; p < 4; p++)
                {
                    getline(fin, line);
                    fout << line << endl;

                }
                fout.close();
            }
            else if (line == to_string(accountNum))
            {
                for (int j = 0; j < 4; j++)
                {
                    ifstream fin2;
                    fin2.open("Delete.txt");
                    getline(fin2, line);
                    fin2.close();
                }
            }
            fin.close();


            ofstream fout;
            fout.open(accountName);

            fin.open("Temp.txt");

            for (int i = 0; i < 5; i++)
            {
                getline(fin, line);
                fout << line << '\r';
            }
            fout.close();
        }
             
        ofstream fout;
        fout.open("Temp.txt");

        for (int i = 0; i < numberOfLines("Temp.txt"); i++)
        {
            fout << "" << endl;
        }

        
    }
    else if (option == "n" || option == "N")
    {
        cout << "Returning to menu" << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
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