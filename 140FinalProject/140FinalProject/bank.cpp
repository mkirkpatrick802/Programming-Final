//Michael, John

#include "bank.h"

///////////////////////
//////// START ////////
///////////////////////

/*      Purpose: Allow the teller to login into the system
*       Pre: Input from the user
*       Post: Whether or not the teller is allowed to login into the system
* 
*************************************************************************/

bool tellerLogin()
{
    string tellerIdInput;
    string tellerPassInput;

    string tellerIdActual;
    string tellerIdPassActual;

    const int TELLER_WIDTH = 25;
    const string TELLER_FILE = "tellers.dat";

    ifstream fin;
    fin.open(TELLER_FILE);
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

/*      Purpose: Displays a welcome message to the user
*       Pre: Teller must have logged in
*       Post: outputs text to the console
*
*************************************************************************/
void welcomeMessage()
{
    cout << endl;
    cout << "Beglückwünschung" << endl;
    cout << "Hello and Welcome to Lake Champlain Banking teller system!" << endl;
    cout << endl;
}

/*      Purpose: Displays options to the teller on what to do
*       Pre: Teller must be loged in
*       Post: gets the chosen option from the user and uses it to show next function
*
*************************************************************************/
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

/*      Purpose: Creates acount new account data and outputs them to the accounts.dat fil correctly formatted
*       Pre: Teller must have chosesen to make new accounts and accounts.dat file must exist
*       Post: creates a correctly formatted accounts and outputs it to the accounts.dat file
*
*************************************************************************/
void createNewAccount()
{
    const int CREATE_WIDTH = 40;
    const int SOCIAL_FORMAT_1 = 3;
    const int SOCIAL_FORMAT_2 = 5;
    const int SOCIAL_FORMAT_3 = 9;
    const int PHONE_FORMAT_1 = 1;
    const int PHONE_FORMAT_2 = 4;
    const int PHONE_FORMAT_3 = 7;
    const int PHONE_FORMAT_4 = 10;

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
            if (j == SOCIAL_FORMAT_1)
            {
                str << "-";
            }
            else if (j == SOCIAL_FORMAT_2)
            {
                str << "-";
            }
            else if (j == SOCIAL_FORMAT_3)
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
    for (char i : phoneNumber)
    {
        if (isdigit(i))
        {
            
            p++;
            if (p == PHONE_FORMAT_1)
            {
                buildPhone += "(";
            }
            else if (p == PHONE_FORMAT_2)
            {
                buildPhone += ")";
            }
            else if (p == PHONE_FORMAT_3)
            {
                buildPhone += "-";
            }

            buildPhone += i;

            if (p == PHONE_FORMAT_4)
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

/*      Purpose: Creates a new an unique account number for each account made
*       Pre: create account function must be called
*       Post: outputs a new accounts number
*
*************************************************************************/
int newAccountNumber()
{
    const int NEXT_ACCOUNT = 1;
    const int NOT_DIGITS = 0;
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
        if (convertStrToInt(line) != NOT_DIGITS)
        {
            accountNumber = convertStrToInt(line) + NEXT_ACCOUNT;
        }
    }

    ofstream fout;
    fout.open("data\\" + to_string(accountNumber) + ".dat");

    fout.close();
    fin.close();
    return accountNumber;
}

///////////////////////////////////
//////// Login To Account ////////
//////////////////////////////////

/*      Purpose: Allows the teller to log users in that already have accounts
*       Pre: account must already have been made
*       Post: logs into an account and allows the options for that account to be displayed
*
*************************************************************************/
int login()
{
    string accountNum;

    cout << "Please enter account number: ";
    cin >> accountNum;
    cin.ignore();

    ifstream fin;
    fin.open("data\\" + accountNum + ".dat");
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

/*      Purpose: displays the options for the teller on what to do when logged in
*       Pre: user must be logged in
*       Post: text showing what options are avalible
*
*************************************************************************/
void displayOptions()
{
    const int OPTIONS_WIDTH = 20;

    cout << endl;
    cout << right << setw(OPTIONS_WIDTH) << "1: Deposit" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "2: Withdraw" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "3: Update Info" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "4: Search for Info" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "5: Check Balance" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "6: Delete account" << endl;
    cout << right << setw(OPTIONS_WIDTH) << "7: Quit" << endl;
    cout << endl;
}

/*      Purpose: Allows user to deposit money to their balance file, also needs the balance from the balance file and the acount number
*       Pre: user must be logged in and have selected the deposit option from the menu
*       Post: changes the user's balacne based on how much money is deposited
*
*************************************************************************/
void deposit(float balance, int accountNum)
{
    const int DECIMAL_POINTS = 2;
    float depositAmount;
    string accountName = "data\\" + to_string(accountNum) + ".dat";

    ofstream fout;
    fout.open(accountName);

    if (!fout.is_open())
    {
        cout << "Failed to find deposit file: " << accountName << endl;
    }

    cout << "How much do you wish to deposit?" << endl;
    cin >> depositAmount;

    balance = balance + depositAmount;
    fout << setprecision(DECIMAL_POINTS) << fixed << balance << endl;

    cout << "Your balance is now " << balance << endl;
    fout.close();
}

/*      Purpose: Allows the user to withdraw money from their balance file
*       Pre: user must be logged in and have selected the withdraw option, also needs the balance from the balance file and the acount number
*       Post: withdraws money from the user's balacne file based on what the user asked for
*
*************************************************************************/
void withdraw(float balance, int accountNum)
{
    const int DECIMAL_POINTS = 2;
    float withdrawAmount;
    string accountName = "data\\" + to_string(accountNum) + ".dat";

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
        fout << setprecision(DECIMAL_POINTS) << fixed << balance << endl;
        cout << "Your balance is now " << balance << endl;
    }
    fout.close();
}

/*      Purpose: Lets the user change their info in the accounts.dat file
*       Pre: User must be logged in and have selected this option, also the account num is needed
*       Post: Whether or not the teller is allowed to login into the system
*
*************************************************************************/
void updateInfo(int accountNum)
{
    int option;
    const int OPTIONS_WIDTH = 40;

    cout << "What info do you want to change?" << endl;
    cout << endl;

    cout << left << setw(OPTIONS_WIDTH) << "1: Social Security Number" << endl;
    cout << left << setw(OPTIONS_WIDTH) << "2: Name" << endl;
    cout << left << setw(OPTIONS_WIDTH) << "3: Address" << endl;
    cout << left << setw(OPTIONS_WIDTH) << "4: Phone Number" << endl;
    cout << left << setw(OPTIONS_WIDTH) << "5: Quit" << endl;
    cout << endl;

    cin >> option;

    switch (option)
    {
    case 1:
        moveInfo(option, accountNum);
        break;
    
    case 2: 
        moveInfo(option, accountNum);
        break;

    case 3:
        moveInfo(option, accountNum);
        break;
    
    case 4:
        moveInfo(option, accountNum);
        break;

    case 5:
        moveInfo(option, accountNum);
        break;
    }
}

/*      Purpose: Moves the user's updated data to a new file the renames that file to accounts.dat
*       Pre: needs the account num and the what data the user chose to change as well as input on what to change it to
*       Post: Creates a new accounts.dat file with the updated info in it
*
*************************************************************************/
void moveInfo(int option, int accountNum) 
{
    string accountName = "accounts.dat";
    string newInfo;
    string accountInfo[10];
    cout << endl;
    cout << "What do you wish to change it to?" << endl;
    cin.ignore();
    getline(cin, newInfo);

    ofstream fout;
    fout.open("Temp.txt");
    ifstream fin;
    fin.open(accountName);

    while (!fin.eof())
    {
        for (int i = 0; i < 6; i++)
        {
            getline(fin, accountInfo[i]);
        }
        fin.ignore();

        if (convertStrToInt(accountInfo[0]) == accountNum)
        {
            accountInfo[option] = newInfo;
        }

        for (int i = 0; i < 6; i++)
        {
            fout << accountInfo[i] << endl;
        }
    }

    fout.close();
    fin.close();

    int success = remove(accountName.c_str());
    int successRe = rename("Temp.txt", accountName.c_str());
}

/*      Purpose: Lets the user search for info in the accounts.dat file
*       Pre: User must be logged in and have selected this option, also the account num is needed. Input on what info to display is also needed
*       Post: shows the user the data they asked to veiw 
*
*************************************************************************/
void searchInfo(int accountNum)
{
    const int OPTIONS_WIDTH = 40;
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

/*      Purpose: Lets the user check their balance from their balance file
*       Pre: User must be logged in and have selected this option, also the account num is needed
*       Post: displays the user's balance and stores it in the balance variable
*
*************************************************************************/
float checkBalance(int accountNum)
{
    float balance = 0;
    string accountName = "data\\" + to_string(accountNum) + ".dat";
    const int CHECK_WIDTH = 40;

    ifstream fin;
    fin.open(accountName);

    if (!fin.is_open())
    {
        cout << setw(CHECK_WIDTH) << "Failed to find deposit file: " << accountName << endl;
    }

    fin >> balance;
    
    cout << "Your balance is " << setw(CHECK_WIDTH) << setprecision(2) << fixed << balance << endl;
    return balance;
    fin.close();
}

/*      Purpose: Lets the user delete their info from the accounts.dat file and remove their balance file
*       Pre: User must be logged in and have selected this option, also the account num is needed
*       Post: deletes the user's info from accounts.dat and removes the balance file
*
*************************************************************************/
void deleteAccount(int accountNum)
{
    string option;
    const int DELETE_WIDTH = 30;
   
    cout << setw(DELETE_WIDTH) << "Are you sure you wish to delete your account? y for yes n for no." << endl;
    cin >> option;
    
    if (option == "y" || option == "Y")
    {
        string accountName = "accounts.dat";
        string line;
        bool accountFound = false;
        string accountInfo[10];
        string saveInfo[10];
        string junk;
        int ignore;

        ofstream fout;
        fout.open("Temp.txt");
        

        ifstream fin;
        fin.open(accountName);

        for (int i = 0; i < numberOfLines(accountName); i++)
        {
            getline(fin, line);
 
            if (line != "")
            {
                if (line != to_string(accountNum))
                {
                    fout << line << endl;

                    for (int p = 0; p < 5; p++)
                    {
                        getline(fin, line);
                        fout << line << endl;

                    }

                }
                else
                {
                    for (int j = 0; j < 5; j++)
                    {
                        getline(fin, junk);
                    }
                }
            }
        }

        fout.close();
        fin.close();

        remove("accounts.dat");
        ignore = rename("Temp.txt", "accounts.dat");

        string balanceFile = "data\\" + to_string(accountNum) + ".dat";

        int success = remove(balanceFile.c_str());

        cout << endl;
        cout << setw(DELETE_WIDTH) << "Account Deleted" << endl;
        cout << endl;
        return;
        
    }
    else if (option == "n" || option == "N")
    {
        cout << setw(DELETE_WIDTH) << "Returning to menu" << endl;
    }
    else
    {
        cout << setw(DELETE_WIDTH) << "Invalid input" << endl;
    }
}

/*      Purpose: exits the program
*       Pre: User must be logged in and have selected this option, 
*       Post: exits the program, returns nothing
*
*************************************************************************/
void quit()
{
    const int QUIT_WIDTH = 30;
    cout << endl;
    cout << setw(QUIT_WIDTH) <<  "Exiting Program" << endl;
}

/////////////////////////
//////// Utility ////////
/////////////////////////

/*** Purpose: convert a string to double
* Pre: the string to be converted in stored in stringValue
* Post: The numeric value for the given string in doubleValue and
* true if the string can be converted into double and false if
* the string cannot be converted into double
 *************************************************************************/
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

/*      Purpose: checks how many lines are in a particular file
*       Pre: needs the name of the file
*       Post: returns the number of lines in the file
*
*************************************************************************/
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