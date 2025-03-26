//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Matt Tadeo> on <25March2025>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototypes
double getPayment(int, double, int);

int main()
{
    int Carprice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> Carprice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment (Carprice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment (Carprice, dealerRate / 12, term * 12);
    //display payments in dollars (two decimal places)
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;

    return 0;
}//end of main function   
//*****function definitions*****
double getPayment(int prin, double monthRate, int months)
{
    //calculate and return monthly payment
    double monthPay = 0.0;
    monthPay = prin * monthRate / (1 - pow(monthRate + 1, -months));
    return monthPay;
} //end of getPayment function
