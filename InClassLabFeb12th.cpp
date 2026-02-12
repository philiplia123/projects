// Qihong Liang, 2/12/2026, COMSCI 201, In-class Lab 

#include <iostream>
#include <string>
#include <iomanip>  

using namespace std; 

// new functions
double calculateAverage(int numOfGrades); 
string getLetterGrade(double averageGrade);
void passOrFail(double averageGrade); 

int main() {
    int numOfGrades; 
    double averageGrade; 
    string letterGrade; 

    // asks the user to enter their grade in numbers 
    cout << "How many grades do you want to enter? "; 
    cin >> numOfGrades; 

    // calculating the grade average 
    averageGrade = calculateAverage(numOfGrades); 
    cout << "\nYour average grade is: " << averageGrade << endl; 

    // get letter grade 
    letterGrade = getLetterGrade(averageGrade); 
    cout << "Your letter grade is: " << letterGrade << endl; 

    // check if the student passed or failed 
    passOrFail(averageGrade); 
    return 0; 
}

// code that inputs scores and calculates the average 
// INPUT PARAMETER(S): The number of the scores to enter
// OUTPUT (cout): N/A
// RETURN VALUE: Average of the scores
double calculateAverage(int numOfGrades) {
    double grade, totalGrade = 0; 

    // loop for entering grade and calculating the total
    for (int i = 1; i <= numOfGrades; i++) {
        cout << "Enter grade " << i << ": ";
        cin >> grade; 
        totalGrade += grade;  
    }
    // return the average 
    return totalGrade / numOfGrades; 
}


// code that determines the letter grade based on the average score 
// INPUT PARAMETER(S): The average of the scores
// OUTPUT (cout): N/A
// RETURN VALUE: Letter grade
string getLetterGrade(double averageGrade) {
    string letterGrade; 

    // if statements to determine letter grade 
    if (averageGrade >= 93 && averageGrade <= 100) {
        letterGrade = "A"; 

    }
    else if (averageGrade >= 90 && averageGrade < 93) {
        letterGrade = "A-"; 

    }
    else if (averageGrade >= 87 && averageGrade < 90) {
        letterGrade = "B+"; 

    }
    else if (averageGrade >= 83 && averageGrade < 87) {
        letterGrade = "B"; 

    }
    else if (averageGrade >= 80 && averageGrade < 83) {
        letterGrade = "B-"; 

    }
    else if (averageGrade >= 76 && averageGrade < 80) {
        letterGrade = "C+"; 

    }
    else if (averageGrade >= 70 && averageGrade < 76) {
        letterGrade = "C"; 

    }
    else if (averageGrade >= 60 && averageGrade < 70) {
        letterGrade = "D"; 

    }
    else {
        letterGrade = "F"; 
    }

    return letterGrade;
}

// code that checks if the student passed or failed, C or better will pass 
// INPUT PARAMETER(S): The average of the scores
// OUTPUT (cout): Whether you passed of failed
// RETURN VALUE: N/A

void passOrFail(double averageGrade) {
    if (averageGrade >= 70) {
        cout << "You passed!" << endl; 
    } else {
        cout << "You failed." << endl; 
    }
}