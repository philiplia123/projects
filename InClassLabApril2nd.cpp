#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <ctime>

using namespace std; 

// generate 5 unique numbers from 1 to 70 
vector<int> getMain() {
    vector <int> nums; 

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
    for (int i = 0;i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i] == b[j]) {
                count++; 
            }
        }
    }
    return count; 
}

// prize logics 
int getPrice(int mainMatch, bool megaMatch) { 
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

    int balance = -2000; 
    int winning = 0; 

    for (int i = 0; i < 1000; i++) {
        vector<int> ticketMain = getMain(); 
        int ticketMega = getMega(); 

        int mainMatch = countMatches(ticketMain, winningMain); 
        bool megaMatch = (ticketMega == winningMega); 

        int prize = getPrice(mainMatch, megaMatch); 

        winning += prize; 
        balance += prize; 
    }
    // output 
    cout << "Winning Numbers: "; 
    for (int i = 0; i < 5; i++) {
        cout << winningMain[i] << " ";
    }
    cout << "Mega Ball: " << winningMega << endl; 
    cout << "Total winnings: $" << winning << endl; 
    cout << "Final balance: $" << balance << endl; 
    
    return 0; 
}