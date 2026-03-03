// Qihong Liang, 3/3/2026, COMSCI 201, In-class Lab 

#include <iostream> 
#include <string>
using namespace std; 

// functions 
int minutesToSeconds(int minutes); 
int hoursToSeconds(int hours); 
int calculatePoints(int wins, int losses, int otLosses); 
void displayMenu(); 

int main(){ 
    int choice; 
    bool running = true; 

    // loop until the user picks quit option 
    while (running) {
        // display the menu
        displayMenu(); 

        // get the user's selection 
        cout << "Enter your choice: "; 
        cin >> choice; 
        cout << endl; 

        // process the user's choice 
        if (choice == 1) {
            int minutes; 
            cout << "Enter the number of minutes: "; 
            cin >> minutes; 
            int seconds = minutesToSeconds(minutes); 
            cout << "\n" << minutes << " minutes = " << seconds << " seconds." << endl; 

        } else if (choice == 2) {
            int hours;
            cout << "Enter the number of hours: "; 
            cin >> hours; 
            int seconds = hoursToSeconds(hours); 
            cout << "\n" <<hours << " hours = " << seconds << " seconds." << endl; 

        } else if (choice == 3) {
            // calculate the team points
            int wins, losses, otLosses; 
            cout << "Enter the number of wins: "; 
            cin >> wins; 
            cout << "Enter the number of losses: "; 
            cin >> losses; 
            cout << "Enter the number of overtime losses: "; 
            cin >> otLosses; 
            int points = calculatePoints(wins, losses, otLosses); 
            cout << "\nThe total points for the team is: " << points << endl << endl; 

        } else if (choice == 4) {
            // quit the program
            cout << "Exiting program, goodbye!" << endl; 
            running = false; 
            
        } else {
        cout << "Invalid choice, please try again." << endl << endl; 
    }
    } 
    return 0; 
}

// function 1: converting minutes to seconds 
int minutesToSeconds(int minutes) {
    return minutes * 60; 
}

// function 2: converting hours to seconds 
int hoursToSeconds(int hours) {
    int minutes = hours * 60; 
    return minutesToSeconds(minutes); 
}

// function 3: calculating points based on the team record 
int calculatePoints(int wins, int losses, int otLosses) {
    return (wins * 2) + (losses * 0) + (otLosses * 1); 
}

// function 4: displaying the menu and in-menu options 
void displayMenu() {
    cout << "======== Menu =======" << endl;
    cout << "1. Convert minutes to seconds" << endl;
    cout << "2. Convert hours to seconds" << endl;
    cout << "3. Calculate team points" << endl;
    cout << "4. Quit" << endl;
    cout << "====================" << endl;
}
