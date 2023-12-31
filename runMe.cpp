#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "doublyLinkedList.h"

using namespace std;

void login();
void registration();
void forgot();
void addExpense();
void addIncome();
void viewTransactions();
void viewBalance();
doublyLinkedList<int> userTransactions;

int main()
{
    int choice;
    cout << "________________________________________________________________\n\n";
    cout << "                      Welcome to Login Page                     \n\n";
    cout << "______________________________MENU______________________________\n\n";
    cout << "|  Press 1 to LOGIN                       |\n";
    cout << "|  Press 2 to REGISTER                    |\n";
    cout << "|  Press 3 IF YOU FORGOT YOUR PASSWORD    |\n";
    cout << "|  Press 4 to EXIT                        |\n";
    cout << "\nPlease enter your choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "Thank you.\n";
        break;
    default:
        system("clear");
        cout << "Please select from the options given above.\n" << endl;
        main();
    }
}

void mainScreen()
{
    int userChoice;

    cout << "________________________________________________________________\n\n";
    cout << "                   Welcome to Finance Manager                   \n\n";
    cout << "_____________________________Menu_______________________________\n\n";
    cout << "|  Press 1 to Add Expense                 |\n";
    cout << "|  Press 2 to Add Income                  |\n";
    cout << "|  Press 3 to View All Transactions       |\n";
    cout << "|  Press 4 to Show Balance                |\n";
    cout << "|  Press 5 to EXIT                        |\n";
    cout << "\nPlease enter your choice: ";

    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        addExpense();
        break;
    case 2:
        addIncome();
        break;
    case 3:
        viewTransactions();
        break;
    case 4:
        viewBalance();
        break;
    case 5:
        system("clear");
        main();
        break;    
    default:
        system("clear");
        cout << "Please select from the options given above.\n" << endl;
        main();
    }
}

void login()
{
    int flag;
    string userID, userPassword, fileUserID, fileUserPassword;
    system("clear");

    cout << "Please enter username and password:\n";
    cout << "USERNAME: ";
    cin >> userID;
    cout << "PASSWORD: ";
    cin >> userPassword;

    ifstream readObject("record.txt");

    while (readObject >> fileUserID >> fileUserPassword)
    {
        if (fileUserID == userID && fileUserPassword == userPassword)
        {
            flag = 1;
            system("clear");
        }
    }

    readObject.close();

    if (flag == 1)
    {
        cout << " \nYour login is successful.\nThanks for logging in!\n";
        mainScreen();
    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password.\n";
        login();
    }
}

void registration()
{
    string userID, userPassword, rpass;
    system("clear");

    cout << "Enter the username: ";
    cin >> userID;
    cout << "Enter the password: ";
    cin >> userPassword;

    ofstream writeObject("record.txt", ios::app);

    writeObject << userID << ' ' << userPassword << endl;

    system("clear");

    cout << "\nRegistration is successful.\n";

    writeObject.close();
    main();
}

void forgot()
{
    int userChoice;

    system("clear");

    cout << "Forgot password? No worries.\n";
    cout << "Press 1 to search your password by username.\n";
    cout << "Press 2 to go back to the main menu.\n";
    cout << "Enter your choice: ";
    cin >> userChoice;
    switch (userChoice)
    {
    case 1:
    {
        int count = 0;
        string userID, fileUserID, fileUserPassword;
        cout << "Enter the username which you remembered: ";
        cin >> userID;

        ifstream readObject("record.txt");
        while (readObject >> fileUserID >> fileUserPassword)
        {
            if (userID == fileUserID)
            {
                count = 1;
                break;
            }
        }

        if (count == 1)
        {
            cout << "\nYour account is found.\n";
            cout << "Your password is: " << fileUserPassword << "\n";
            main();
        }
        else
        {
            cout << "\nSorry! Your account is not found!\n";
            main();
        }
        break;
        readObject.close();
    }

    case 2:
    {
        main();
        break;
    }

    default:
        cout << "Wrong choice! Please try again.\n";
        forgot();
        break;
    }
}

void addExpense()
{
    string expenseTitle;
    int expenseAmount;
    system("clear");

    cout << "Enter details of Expense:\n";
    cout << "\nEnter expense title: ";
    cin.ignore();
    getline(cin, expenseTitle);
    cout << "Enter expense amount: ";
    cin >> expenseAmount;

    userTransactions.insertAtEnd(expenseAmount, expenseTitle, "EXPENSE");
    cout << "\nEXPENSE ADDED SUCCESSFULLY.\n\n";

    int userChoice;

    cout << "|  Press 1 to CONTINUE                    |\n";
    cout << "|  Press 2 to EXIT                        |\n";
    cout << "\nPlease enter your choice: ";
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        addExpense();
        break;
    case 2:
        system("clear");
        mainScreen();
        break;
    default:
        system("clear");
        cout << "Invalid option. Exiting...\n" << endl;
        mainScreen();
        break;
    }
}

void addIncome()
{
    string incomeTitle;
    int incomeAmount;
    system("clear");

    cout << "Enter details of Income:\n";
    cout << "\nEnter income title: ";
    cin.ignore();
    getline(cin, incomeTitle);
    cout << "Enter income amount: ";
    cin >> incomeAmount;

    userTransactions.insertAtEnd(incomeAmount, incomeTitle, "INCOME");
    cout << "\nINCOME ADDED SUCCESSFULLY.\n\n";

    int userChoice;

    cout << "|  Press 1 to CONTINUE                    |\n";
    cout << "|  Press 2 to EXIT                        |\n";
    cout << "\nPlease enter your choice: ";
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        addIncome();
        break;
    case 2:
        system("clear");
        mainScreen();
        break;
    default:
        system("clear");
        cout << "Invalid option. Exiting...\n" << endl;
        mainScreen();
    }
}

void viewTransactions()
{
    system("clear");
    userTransactions.printList();
    mainScreen();
}

void viewBalance()
{
    system("clear");
    userTransactions.sum();
    mainScreen();
}

void searchTransaction()
{
    userTransactions.search();
    mainScreen();
}
