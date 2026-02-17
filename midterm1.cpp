#include <iostream>
#include <string> 
using namespace std; 

int main() {
    string input1, input2; 

    // get the input from both players 
    cout << "Player 1, please enter rock, paper, or scissors: " << endl; 
    cin >> input1; 

    cout << "Player 2, please enter rock, paper or scissors: " << endl; 
    cin >> input2; 

    // check for tie 
    if (input1 == input2) {
        cout << "It's a tie!" << endl; 
    } else if ((input1 == "rock" && input2 == "scissors" 
        || input1 == "scissors" && input2 == "paper" 
        || input1 == "paper" && input2 == "rock")) {
            cout << "Player 1 wins!" << endl; 
    } else {
        cout << "Player 2 wins!" << endl; 
    }

    return 0; 
}