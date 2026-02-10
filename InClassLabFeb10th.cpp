// Qihong Liang, 2/10/2026, COMSCI 201, In-class Lab 

#include <iostream>
#include <string>
#include <iomanip>  

using namespace std; 

int main() {
    int numOfGrades; 
    double grade, averageGrade, totalGrade = 0; 
    string letterGrade; 

    // asks the user to enter their grade in numbers 
    cout << "How many grades do you want to enter? "; 
    cin >> numOfGrades; 

    // loop for entering the grade and calculating the total 
    for (int i = 0; i < numOfGrades; i++) {
        cout << "Enter the grade " << i << ": "; 
        cin >> grade; 
        totalGrade += grade; 
    }

    // find the average 
    averageGrade = totalGrade / numOfGrades; 
    cout << "\nYour average grade is: " << averageGrade << endl;

    // if statements to determine letter grade 
    if (grade >= 93 && grade <= 100) {
        letterGrade = "A"; 

    }
    else if (grade >= 90 && grade < 93) {
        letterGrade = "A-"; 

    }
    else if (grade >= 87 && grade < 90) {
        letterGrade = "B+"; 

    }
    else if (grade >= 83 && grade < 87) {
        letterGrade = "B"; 

    }
    else if (grade >= 80 && grade < 83) {
        letterGrade = "B-"; 

    }
    else if (grade >= 76 && grade < 80) {
        letterGrade = "C+"; 

    }
    else if (grade >= 70 && grade < 76) {
        letterGrade = "C"; 

    }
    else if (grade >= 60 && grade < 70) {
        letterGrade = "D"; 

    }
    else {
        letterGrade = "F"; 
    }

    // show the grade 
    cout << "Your letter grade is: " << letterGrade << endl; 

    // check if the student passed or not 
    if (grade >= 70) {
        cout << "You have passed the course." << endl; 
    }
    else {
        cout << "You have not passed the course." << endl; 
    }

    return 0; 
}