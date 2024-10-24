//
// Created by MANAN on 02/08/24.
//
#include <iostream>
using namespace std;

int main() {
    // Print a greeting message
    cout << "Hello world" << endl;

    // Declare variables for input
    int a, b;
    cout << "Enter the value of the first number: ";
    cin >> a;

    cout << "Enter the value of the second number: ";
    cin >> b;

    // Calculate the sum and average
    int sum = a + b;
    cout << "The sum of the two numbers is: " << sum << endl;

    // To get the exact average as a floating-point number, use float or double
    float avg = static_cast<float>(a + b) / 2;
    cout << "The average of the two numbers is: " << avg << endl;

    // Check if the number is even or odd
    int c;
    cout << "Enter a number: ";
    cin >> c;

    if (c % 2 == 0) {
        cout << "The number is even." << endl;
    } else {
        cout << "The number is odd." << endl;
    }

    // Check if the year is a leap year
    int d;
    cout << "Enter the year you want to check whether it is a leap year or not: ";
    cin >> d;

    if ((d % 400 == 0) || (d % 100 != 0 && d % 4 == 0)) {
        cout << "The year entered is a leap year." << endl;
    } else {
        cout << "The year entered is not a leap year." << endl;
    }

    return 0;
}