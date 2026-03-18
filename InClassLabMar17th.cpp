// Qihong Liang, 3/17/2026, COMSCI 201, In-class Lab 
#include <iostream>
#include <string>
using namespace std; 

// functions 
void displayMenu(); 
void checkEvenOdd(); 
void computeSum(); 
void findTarget(); 

int main() {
    int choice; 
    bool running = true; 

    cout << "==================================" << endl;
    cout << "   Number Operations Program" << endl; 
    cout << "==================================" << endl;

    // loop to keep showing menu until user exits the program 
    while (running) {
        displayMenu(); 
        cout << "Enter your choice: "; 
        cin >> choice; 
        cout << endl; 

        // recognize menu choices using if/else statements 
        if (choice == 1) { 
            checkEvenOdd(); 
        } else if (choice == 2) {
            computeSum(); 
        } else if (choice == 3) {
            findTarget(); 
        } else if (choice == 4) {
            cout << "Exiting the program. Bye!" << endl; 
            running = false; 
        } else {
            // handling the invalid input 
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
        cout << endl; 
    }
    return 0;
}

// function to display the menu 
void displayMenu() {
    cout << "=============== MENU ===============" << endl;
    cout << "1. Check if a number is even or odd" << endl; 
    cout << "2. Compute the sum of two numbers" << endl;
    cout << "3. Find a largest number in an array" << endl;
    cout << "4. Exit" << endl;
    cout << "==================================" << endl;
}

// function to check if a number is even or odd
void checkEvenOdd() {
    int number; 
    cout << "Enter a number: "; 
    cin >> number; 
    if (number % 2 == 0) {
        cout << "\n" << number << " is even." << endl; 
    } else {
        cout << "\n" << number << " is odd." << endl; 
    }
}

// function to compute the sum of 2 numbers 
void computeSum() {
    int n; 
    int sum = 0; 
    cout << "Enter a positive integer: "; 
    cin >> n; 

    // input validation 
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl; 
        return; 
    }

    // loop to calculate sum from 1 to N 
    for (int i = 1; i <= n; i++) {
        sum += i; 
    }
    cout << "\nThe sum of numbers from 1 to " << n << " is: " << sum << "." << endl; 
}

// function to find the largest number in a user entered list 
void findTarget() {
    int count; 
    int number; 
    int largest; 

    cout << "How many numbers do you want to enter? "; 
    cin >> count; 

    // input validation 
    if (count <= 0) {
        cout << "Please enter a positive integer for the count." << endl; 
        return; 
    }

    // get the first number as initial target 
    cout << "Enter number 1: "; 
    cin >> largest; 

    // loop to get the rest of the numbers and find the target 
    for (int i = 2; i <= count; i++) {
        cout << "Enter number " << i << ": "; 
        cin >> number; 
        if (number > largest) {
            largest = number; 
        }
    }
    cout << "\nThe largest number you entered is: " << largest << "." << endl; 

}
        
    
