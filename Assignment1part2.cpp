#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std; 

int main() {
    int numOfSimulations = 100000; // Number of simulations to run
    int doubleCounts = 0; // counts the number of times the dice rolls doubles 

    // srand(time(NULL)); random nmumber generator 

    // code for running the simulation 
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