#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //Declare variables
    float initialInv, monthlyDep, annualInt, months, years;
    float totalAmount, intAmount, yearEndInt;


    //Display screen to user
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: " << endl;
    cout << "Monthly Deposit: " << endl;
    cout << "Annual Interest: " <<endl;
    cout << "Number of years: " << endl;
    system("PAUSE");

    //Get user input
    cout << "********************************" << endl;
    cout << "********** Data Input **********" << endl;
    cout << "Initial Investment Amount: $";
    cin >> initialInv;
    cout << "Monthly Deposit: $";
    cin >> monthlyDep;
    cout << "Annual Interest: %";
    cin >> annualInt;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12;
    system("PAUSE");

    totalAmount = initialInv;

    //Display without monthly deposits to user
    cout << "\n   Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==============================================================" << endl;
    cout << "Year\t\tYear End Balance      Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------" << endl;

    //Calculate and print year end balance and interest without monthly deposits
    for (int i = 0; i < years; i++) {
        intAmount = (totalAmount) * ((annualInt / 100));
        totalAmount = totalAmount + intAmount;
        cout << setw(4) << (i + 1) << setw(24) << "$" << fixed << setprecision(2) << totalAmount << setw(26) << "$" << intAmount << endl;
    }

    totalAmount = initialInv;

    //Display with monthly deposits to user
    cout << "\n\n   Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "==============================================================" << endl;
    cout << "Year\t\tYear End Balance      Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------" << endl;

    //Calculate and print year end balance and interest with monthly deposits
    for (int i = 0; i < years; i++) {
        yearEndInt = 0;
        for (int j = 0; j < 12; j++) {
            intAmount = (totalAmount + monthlyDep) * ((annualInt / 100) / 12);
            yearEndInt = yearEndInt + intAmount;
            totalAmount = totalAmount + monthlyDep + intAmount;
        }
        cout << setw(4) << (i + 1) << setw(21) << "$" << fixed << setprecision(2) << totalAmount << setw(26) << "$" << yearEndInt << endl;
    }

    return 0;
}