//Eric Lin
//Homework #3
//October 15th, 2024

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    double iniMoney;    // Initial Money
    double bal;         // Current Balance
    int trans;          // Number of Transactions

    ifstream inFile;
    ofstream outFile; 

    //Opening required files
    inFile.open("inputValues.txt");
    outFile.open("outputValues.txt");

    //START HERE

    inFile >> iniMoney;
    bal = iniMoney;
    int i = 7;

    while (i > trans) {
        cout << "Transaction " << (i + 1) << endl;
        char t;
        double amount;

    // Clear instruction for user to select type of transaction
    cout << "Enter transaction type (d for deposit, w for withdraw): ";
    cin >> t;

    //Following is for debit
        if (t == 'w') 
    {
        cout << "Enter withdraw amount: ";
        cin >> amount;
    //Subtract for debit
        bal = bal - amount; 
        cout << "Balance after transaction " << (i + 1) << ": $" << bal << endl;
        i = i + 1;  
    } 
    //Following is for credit
        else if (t == 'd') 
    {
        cout << "Enter deposit amount: ";
        cin >> amount;
    //Add for credit
        bal = bal + amount;  
        cout << "Balance after transaction: " << (i + 1) << ": $" << bal << endl;
        i = i + 1;  
    } else 
    {
        cout << "Invalid! Please enter 'w' or 'd'." << endl;
    }
}
    //The Summary for the Required Extra Credit...
    cout << "End of Day Balance Summary:";
    cout << "Final balance: $" << bal << endl;

    outFile.close();
    inFile.close();

    return 0;
}
