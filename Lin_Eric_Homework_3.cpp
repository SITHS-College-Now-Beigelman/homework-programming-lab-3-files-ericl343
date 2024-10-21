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
    int trans = 0;      // Number of Transactions

    ifstream inFile;
    ofstream outFile; 

    //Opening required files
    inFile.open("inputValues.txt");
    outFile.open("outputValues.txt");

    //START HERE
    if (!inFile || !outFile) 
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    inFile >> iniMoney;
    bal = iniMoney;
    
    char t;             // Transaction type ('W' or 'D')
    double amount;      // Transaction amount

    // Output starting balance to output file
    outFile << fixed << setprecision(2);
    outFile << "STARTING BALANCE: $" << iniMoney << endl;
    outFile << "Type" << setw(12) << "Amount" << setw(20) << "Balance" << endl;

    // Read transactions until the end of the file
    while (inFile >> t >> amount) 
    {
    // Processing the transaction based on type (withdraw or deposit)
    if (t == 'W') 
    {
        bal -= amount; 
    } else if (t == 'D') 
    {
        bal += amount; 
    } else {
        outFile << "Invalid transaction type encountered: " << t << endl;
        continue;
    }

    // Output the transaction and new balance to the output file
    outFile << t << setw(13) << amount << setw(20) << bal << endl;
        
    // Increment transaction count
    trans++;
    }

// Output the final balance and transaction summary
outFile << "\nEnd of Day Balance Summary:" << endl;
outFile << "Final balance: $" << bal << endl;
outFile << "Number of transactions: " << trans << endl;

// Closing files
outFile.close();
inFile.close();

return 0;
}
