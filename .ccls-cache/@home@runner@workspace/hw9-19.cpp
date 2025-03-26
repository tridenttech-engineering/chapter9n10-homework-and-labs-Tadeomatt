//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Matt Tadeo> on <25March2025>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes
double getPayment(int, double, int);
double getTotal(double, int); // Declare the getTotal function

int main()
{
    // Declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double creditTotal = 0.0;
    double dealerTotal = 0.0;

    // Input details
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Check if either of the payments is -1 (invalid calculation)
    if (creditPayment == -1 || dealerPayment == -1)
    {
        cout << "Error: Invalid input. The denominator in the payment formula is 0." << endl;
        return -1;
    }

    // Call function to calculate total payments
    creditTotal = getTotal(creditPayment, term * 12);
    dealerTotal = getTotal(dealerPayment, term * 12);

    // Display payments and totals in dollars (two decimal places)
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union monthly payment: $" << creditPayment << endl;
    cout << "Credit union total payment: $" << creditTotal << endl;
    cout << "Dealer monthly payment: $" << dealerPayment << endl;
    cout << "Dealer total payment: $" << dealerTotal << endl;

    return 0;
} // End of main function    

// Function to calculate the monthly payment
double getPayment(int prin, double monthRate, int months)
{
    double monthPay = 0.0;
    
    monthPay = prin * monthRate / (1 - pow(monthRate + 1, -months));
    return monthPay;
} // End of getPayment function

// Function to calculate the total payment
double getTotal(double monthPay, int months)
{
    double total = 0.0;
    // Round the monthly payment to two decimal places
    double roundedPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
    total = roundedPay * months;
    return total;
} // End of getTotal function