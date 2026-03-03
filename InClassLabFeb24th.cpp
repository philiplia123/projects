// Qihong Liang, 2/24/2026, COMSCI 201, In-class Lab 

#include <iostream> 
#include <string>
#include <cctype> 
using namespace std; 

char checkio(string text) {
    // an array to count the frequencies of each letter from a to z
    int freq[26] = {0}; 
    // convert the text to lowercase and count letter frequencies 
    for (int i = 0; i < text.length(); i++) {
        char ch = tolower(text[i]); 
        // only count letters from a to z
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++; 
        }
    }
    // look for the letter with the highest frequency 
    int maxFreq = 0; 
    char mostFreqChar = 'a'; 

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[1]; 
            mostFreqChar = 'a' + i; 
            
        }
    }
    return mostFreqChar; 
}


int main() {
    // testing the different cases
    cout << "Testing checkio function: " << endl; 
    cout << "checkio(\"Hello World!\") = \"" << checkio("Hello World!") << "\"" << endl; 
    cout << "checkio(\"How do you do?\") = \"" << checkio("How do you do?") << "\"" << endl; 
    cout << "checkio(\"One\") = \"" << checkio("One") << "\"" << endl; 
    cout << "checkio(\"Oops!\") = \"" << checkio("Oops!") << "\"" << endl;

    return 0; 
}