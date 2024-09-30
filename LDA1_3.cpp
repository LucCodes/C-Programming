#include <iostream>
#include <iomanip>  // setprecision, fixed, setw
#include <cmath>    // for pow

using namespace std;

int main() {
    double loanAmount;
    double annualInterestRate; // Annual interest rate in decimal (e.g., 0.12 for 12%)
    int numberOfPayments;

    // User inputs
    cout << "Loan amount: $";
    cin >> loanAmount;
    cout << "Annual interest rate (in the format .12 for 12%): ";
    cin >> annualInterestRate;
    cout << "Number of monthly payments to be made: ";
    cin >> numberOfPayments;

    // Calculate monthly interest
    double monthlyInterestRate = annualInterestRate / 12;

    // Calculate monthly payment w/ formula
    double monthlyPayment = (monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfPayments)) /
                            (pow(1 + monthlyInterestRate, numberOfPayments) - 1) * loanAmount;

    // Calculate total amount paid back
    double totalAmountPaid = monthlyPayment * numberOfPayments;

    // Calculate interest paid
    double interestPaid = totalAmountPaid - loanAmount;

    // Display the results formatted to two decimal places
    cout << fixed << setprecision(2);
    cout << "\n- Loan Report -\n";
    cout << setw(20) << "Loan Amount: $" << loanAmount << endl;
    cout << setw(20) << "Monthly Interest Rate: " << (monthlyInterestRate * 100) << "%" << endl;
    cout << setw(20) << "Number of Payments: " << numberOfPayments << endl;
    cout << setw(20) << "Monthly Payment: $" << monthlyPayment << endl;
    cout << setw(20) << "Amount Paid Back: $" << totalAmountPaid << endl;
    cout << setw(20) << "Interest Paid: $" << interestPaid << endl;

    return 0;
}

