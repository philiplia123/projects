// Qihong Liang, 2/20/2025, COMSCI 201, Assignment 1 - Spring 2025

#include <iostream> 
#include <string> 
#include <iomanip> 
#include <cstdlib> 

using namespace std; 

int main() {
    srand(time(NULL));

    // first problem 
    cout << "----------------------------------------" << endl;
    cout << "Problem 1: " << endl; 
    cout << "----------------------------------------" << endl;
    
    int radius = 39; //birthday Math + Day = 11 + 28 
    int randomPoints = 500000; //sets the max hit points to 500,000 
    int pointsInsideCircle = 0; //defaults the starting point as 0 


    // bounds from circle in the picture: from -1 to 1 
    double lower_bound = -1.0; 
    double upper_bound = 1.0; 
    
    // for loop for generating random points and checking if the points are in the circle 
    for (int i = 0; i < randomPoints; i++) {
        // generate random coordinates (x,y) that are doubles and are between -1 to 1 
        double x = lower_bound + static_cast <float>(rand()) / (static_cast <float>(RAND_MAX / (upper_bound - lower_bound)));   
        double y = lower_bound + static_cast <float>(rand()) / (static_cast <float>(RAND_MAX / (upper_bound - lower_bound)));       

        // if statement for checking if the points are inside the circle 
        // r^2 has to be larger than x^2+y^2 for the point to be inside the circle 
        double distanceSquared = (x * radius) * (x * radius) + (y * radius) * (y * radius);
        if (distanceSquared <= radius * radius) {
            pointsInsideCircle++; 
    }
}

    // finalize and display the results
cout << "Number of hits inside the circle from the simulation: " << pointsInsideCircle << endl;

// percentage of hits calculation for only 2 decimal places 
double hitPercentage = (pointsInsideCircle / (double)randomPoints) * 100.0; 
cout << fixed << setprecision(2) << hitPercentage << "%" << endl;
cout << "The percentage of hits inside the circle is: " << hitPercentage << "%" << endl; 


// second problem 
cout << "----------------------------------------" << endl;
cout << "Second Problem: " << endl; 
cout << "----------------------------------------" << endl;

  int numOfSimulations = 100000; // Number of simulations to run
    int doubleCounts = 0; // counts the number of times the dice rolls doubles 

    // for loop for running the simulation 
    for (int i = 0; i < numOfSimulations; i++) {
        // roll the dice twice 
        int dice1 = rand() % 6 + 1; // first dice roll
        int dice2 = rand() % 6 + 1; // second dice roll 

        // if statement that checks if the rolls are doubles 
        if (dice1 == dice2) {
            doubleCounts++; 
        }
    }

    //display the results 
    cout << "Number of times doubles were rolled from the simulation: " << doubleCounts << endl; 

    // code for calculating the of doubles rolled in 2 decimal places 
    double doublePercentage = (static_cast<double>(doubleCounts) / numOfSimulations) * 100.0; 
    cout << fixed << setprecision(2); 
    cout << "The count in a percentage of doubles rolled is: " << doublePercentage << "%" << endl; 

    return 0; 
}


