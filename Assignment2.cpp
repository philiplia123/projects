// Qihong Liang Assignment 2, COMSCi 201, 3/29/2026   

#include <iostream> 
#include <string> 
#include <iomanip> 
#include <cmath> 
using namespace std; 

// constant numbers for the ramp 
const double rampAngle = 25.0; // degrees
const double rampLength = 4.0; // feet
const double gravity = 32.2; // ft/s^2
const double PI = 3.14159265; 

// function structures - Problem 1 (Skee-Ball)
void displayWelcome(); 
void displayLandingZones(); 
double calculateDistance(double velocity); 
int calculatePoints(double distance); 
void displayResults(int throwNumber, double distance, int points); 
void displayFinalScore(int totalScore);
void runSkeeBall();

// function structures - Problem 2 (Roman Numerals)
string numericToRoman(int number);
int romanToNumeric(string roman);
void runRomanConverter();

// main menu function
void displayMainMenu();

int main() {
    int choice;
    bool running = true;

    cout << "\n=====================================" << endl;
    cout << "   ASSIGNMENT 2 - MAIN PROGRAM" << endl;
    cout << "=====================================" << endl;

    // main program loop
    while (running) {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            runSkeeBall();
        }
        else if (choice == 2) {
            runRomanConverter();
        }
        else if (choice == 3) {
            cout << "Thank you for using the program. Goodbye!" << endl;
            running = false;
        }
        else {
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }
        cout << endl;
    }

    return 0; 
}

// display main menu
void displayMainMenu() {
    cout << "\n========== MAIN MENU ==========" << endl;
    cout << "1. Play Skee-Ball Game (Problem 1)" << endl;
    cout << "2. Roman Numeral Converter (Problem 2)" << endl;
    cout << "3. Exit Program" << endl;
    cout << "===============================" << endl;
}

// ========== PROBLEM 1: SKEE-BALL GAME ==========

void runSkeeBall() {
    double velocity;
    double distance; 
    int points; 
    int totalScore = 0; 

    // display the welcome message and game information 
    displayWelcome(); 
    displayLandingZones(); 

    // the user will throw 5 balls 
    for (int throwNumber = 1; throwNumber <= 5; throwNumber++) {
        cout << "\n============ Throw #" << throwNumber << " ============" << endl; 
        cout << "Enter ball velocity (ft/s): ";
        cin >> velocity; 

        // calculating how far the ball travels 
        distance = calculateDistance(velocity); 
        // determine points based on the landing zones 
        points = calculatePoints(distance); 
        // displaying the results 
        displayResults(throwNumber, distance, points); 

        // add to total score 
        totalScore += points; 

        cout << "Current total score: " << totalScore << endl; 
    }

    // display the final score after all the throws 
    displayFinalScore(totalScore); 
}

// displaying the welcome message 
void displayWelcome() { 
    cout << "\n=====================================" << endl;
    cout << "   WELCOME TO SKEE-BALL CHALLENGE!   " << endl;
    cout << "=====================================" << endl;
    cout << "Ramp angle: " << rampAngle << " degrees" << endl; 
    cout << "Ramp length: " << rampLength << " feet" << endl; 
    cout << "\nYou will throw 5 balls and try to score as many points as possible!" << endl; 
    cout << "Enter the velocity of each throw in feet per second (ft/s)." << endl; 
}

// display the landing zones and their point values 
void displayLandingZones() {
    cout << "\n============ Landing Zones ============" << endl;
    cout << "0-3 feet:  -1 points (Gutter!)" << endl; 
    cout << "3-6 feet:  5 points" << endl;
    cout << "6-9 feet:  25 points" << endl;
    cout << "9-12 feet: 100 points (JACKPOT!)" << endl;
    cout << "12-15 feet: 15 points" << endl;
    cout << "15+ feet: 0 points (Out of bounds!)" << endl;
    cout << "=====================================" << endl; 
}

// calculate the distance the ball travels based on the velocity and the ramp angle 
// using projectile motion physics  
double calculateDistance(double velocity) {
    double angleRad = rampAngle * PI / 180.0; // convert angle to radians

    // calculating the velocity components 
    double vx = velocity * cos(angleRad); // horizontal velocity 
    double vy = velocity * sin(angleRad); // vertical velocity 
    // calculating the time in air 
    double timeInAir = (2.0 * vy) / gravity; 
    // calculating horizontal distance traveled 
    double distance = vx * timeInAir; 
    return distance; 
}

// calculating the points based on where the ball lands 
int calculatePoints(double distance) {
    if (distance >= 0 && distance < 3) {
        return -1; // gutter 
    }
    else if (distance >= 3 && distance < 6) {
        return 5; // 5 points 
    }
    else if (distance >= 6 && distance < 9) {
        return 25; // 25 points 
    }
    else if (distance >= 9 && distance < 12) {
        return 100; // jackpot 
    }
    else if (distance >= 12 && distance < 15) {
        return 15; // 15 points 
    }
    else {
        return 0; // out of bounds 
    }
}

// display the results of a throw 
void displayResults(int throwNumber, double distance, int points) {
    cout << fixed << setprecision(2); // format distance to 2 decimal places 
    cout << "\nDistance Traveled: " << distance << " feet" << endl;
    
    // display the landing zone messages 
    if (points == -1) {
        cout << "Oh no! You landed in the gutter. -1 point." << endl; 
    }
    else if (points == 100) {
        cout << "JACKPOT! You scored 100 points!" << endl; 
    }
    else if (points == 0) {
        cout << "Out of bounds! No points scored." << endl; 
    }
    else {
        cout << "Great throw! You scored " << points << " points." << endl; 
    }
}

// displaying the final score after all the throws 
void displayFinalScore(int totalScore) {
    cout << "\n=====================================" << endl;
    cout << "          GAME OVER! " << endl; 
    cout << "=====================================" << endl; 
    cout << "Your final score is: " << totalScore << " points!" << endl;

    // display a message based on the final score 
    if (totalScore >= 300) {
        cout << "Amazing job! You're a Skee-Ball master!" << endl; 
    }
    else if (totalScore >= 150) {
        cout << "Great work! You have some serious Skee-Ball skills!" << endl; 
    }
    else if (totalScore >= 50) {
        cout << "Not bad! Keep practicing to improve your score!" << endl; 
    }
    else if (totalScore >= 0) {
        cout << "Better luck next time! Don't give up!" << endl; 
    }
    else {
        cout << "Yikes! You ended up with a negative score. Ouch!" << endl;
    }
    cout << "======================================" << endl;
}

// ========== PROBLEM 2: ROMAN NUMERAL CONVERTER ==========

void runRomanConverter() {
    int choice;

    cout << "\n=====================================" << endl;
    cout << "   ROMAN NUMERAL CONVERTER" << endl;
    cout << "=====================================" << endl;
    cout << "1. Convert Numeric to Roman" << endl;
    cout << "2. Convert Roman to Numeric" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int number;
        cout << "\nEnter a number (1-3999): ";
        cin >> number;
        
        if (number < 1 || number > 3999) {
            cout << "Error: Number must be between 1 and 3999." << endl;
        }
        else {
            string roman = numericToRoman(number);
            cout << number << " in Roman numerals is: " << roman << endl;
        }
    }
    else if (choice == 2) {
        string roman;
        cout << "\nEnter a Roman numeral: ";
        cin >> roman;
        
        // Convert to uppercase
        for (int i = 0; i < roman.length(); i++) {
            roman[i] = toupper(roman[i]);
        }
        
        int number = romanToNumeric(roman);
        if (number == -1) {
            cout << "Invalid Roman numeral!" << endl;
        }
        else {
            cout << roman << " in numeric value is: " << number << endl;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
    }
}

// Converts a numeric value to Roman numeral representation
// Example: 10 -> "X", 1994 -> "MCMXCIV"
string numericToRoman(int number) {
    if (number <= 0 || number > 3999) {
        return "Invalid";
    }
    
    // Arrays for values and their Roman numeral symbols
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string result = "";
    
    // Build Roman numeral by subtracting largest values first
    for (int i = 0; i < 13; i++) {
        while (number >= values[i]) {
            result += numerals[i];
            number -= values[i];
        }
    }
    
    return result;
}

// Converts a Roman numeral to its numeric value
// Example: "D" -> 500, "MCMXCIV" -> 1994
int romanToNumeric(string roman) {
    int total = 0;
    int prevValue = 0;
    
    // Process each character from right to left
    for (int i = roman.length() - 1; i >= 0; i--) {
        int currentValue = 0;
        
        // Determine value of current Roman numeral
        if (roman[i] == 'I') currentValue = 1;
        else if (roman[i] == 'V') currentValue = 5;
        else if (roman[i] == 'X') currentValue = 10;
        else if (roman[i] == 'L') currentValue = 50;
        else if (roman[i] == 'C') currentValue = 100;
        else if (roman[i] == 'D') currentValue = 500;
        else if (roman[i] == 'M') currentValue = 1000;
        else {
            return -1;  // Invalid character
        }
        
        // If current value is less than previous, subtract it (e.g., IV = 4)
        // Otherwise, add it
        if (currentValue < prevValue) {
            total -= currentValue;
        } else {
            total += currentValue;
        }
        
        prevValue = currentValue;
    }
    
    return total;
}