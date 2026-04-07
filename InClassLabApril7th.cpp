#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <ctime>

using namespace std; 

// generate 5 unique numbers from 1 to 70 
vector<int> getMain() {
    vector<int> nums; 

    while (nums.size() < 5) {
        int n = rand() % 70 + 1;
        
        bool duplicate = false; 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == n) {
                duplicate = true; 
            }
        }
        if (!duplicate) {
            nums.push_back(n); 
        }
    }
    return nums; 
}

// generate mega ball from 1 to 25
int getMega() {
    return rand() % 25 + 1; 
}

// count matching main numbers 
int countMatches(vector<int> a, vector<int> b) {
    int count = 0; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i] == b[j]) {
                count++;
                break; // avoid double checking
            }
        }
    }
    return count; 
}

// prize logic (FIXED NAME)
int getPrize(int mainMatch, bool megaMatch) { 
    if (mainMatch == 5 && megaMatch) return 200000000; 
    if (mainMatch == 5) return 1000000; 
    if (mainMatch == 4 && megaMatch) return 10000; 
    if (mainMatch == 4) return 500; 
    if (mainMatch == 3 && megaMatch) return 200;    
    if (mainMatch == 3) return 10;
    if (mainMatch == 2 && megaMatch) return 10;
    if (mainMatch == 1 && megaMatch) return 4;
    if (megaMatch) return 2;
    return 0; 
}

int main() {
    srand(time(0)); 

    vector<int> winningMain = getMain(); 
    int winningMega = getMega(); 

    int choice; 
    cout << "1. Find how many tickets to reach X dollars\n"; 
    cout << "2. Enter number of tickets\n"; 
    cout << "Choice: "; 
    cin >> choice; 
    
    int balance = 0; 
    int tickets = 0; 

    if (choice == 1) {
        int target; 
        cout << "Enter target amount: "; 
        cin >> target; 

        balance = 0; 

        while (balance < target) {
            vector<int> ticketMain = getMain(); 
            int ticketMega = getMega(); 

            int mainMatch = countMatches(ticketMain, winningMain); 
            bool megaMatch = (ticketMega == winningMega); 

            int prize = getPrize(mainMatch, megaMatch); 

            balance -= 2;   // consistent cost handling
            balance += prize; 
            tickets++; 

            // prevent infinite loop
            if (tickets > 1000000) {
                cout << "Stopped early (too many tickets)\n";
                break;
            }
        }

        cout << "Tickets needed: " << tickets << endl; 
        cout << "Final balance: $" << balance << endl;
    }

    else if (choice == 2) {
        int numTickets; 
        cout << "Enter number of tickets: "; 
        cin >> numTickets; 

        balance = 0;
        tickets = numTickets;

        for (int i = 0; i < numTickets; i++) {
            vector<int> ticketMain = getMain(); 
            int ticketMega = getMega(); 

            int mainMatch = countMatches(ticketMain, winningMain); 
            bool megaMatch = (ticketMega == winningMega); 

            int prize = getPrize(mainMatch, megaMatch); 

            balance -= 2;   // consistent cost handling
            balance += prize; 
        }

        cout << "Total tickets: " << tickets << endl;
        cout << "Final balance: $" << balance << endl;
    }
    
    // show winning numbers
    cout << "\nWinning Numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << winningMain[i] << " ";
    }
    cout << "Mega Ball: " << winningMega << endl;

    return 0;
}