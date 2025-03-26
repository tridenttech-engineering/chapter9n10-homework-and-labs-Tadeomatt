//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Matt Tadeo> on <25March2025>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
void getPayment(int, double, int, double&);  // Modified to use a reference parameter for output

int main()
{
    //declare variables
    int carPrice = 16000;  // Updated car price
    int rebate = 3000;     // Updated rebate
    double creditRate = 0.08;  // Updated credit union rate
    double dealerRate = 0.03;  // Updated dealer rate
    int term = 4;          // Updated term in years
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    // Displaying input values (optional for clarity)
    cout << "Car price (after any trade-in): " << carPrice << endl;
    cout << "Rebate: " << rebate << endl;
    cout << "Credit union rate: " << creditRate << endl;
    cout << "Dealer rate: " << dealerRate << endl;
    cout << "Term in years: " << term << endl;

    //call function to calculate payments
    getPayment(carPrice - rebate, creditRate / 12, term * 12, creditPayment);
    getPayment(carPrice, dealerRate / 12, term * 12, dealerPayment); // Pass payment as reference

    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" 
        << creditPayment << endl;
    cout << "Dealer payment: $"
        << dealerPayment << endl;

    return 0;
}//end of main function    

    //*****function definitions*****
void getPayment(int prin, double monthRate, int months, double& monthPay)
{
    //calculates and assigns a monthly payment to monthPay
    monthPay = prin * monthRate / 
        (1 - pow(monthRate + 1, -months));
} //end of getPayment function

