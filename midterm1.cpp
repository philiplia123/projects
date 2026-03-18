#include <iostream>
#include <string>
using namespace std;

// Function prototype
string first_word(string text);

int main() {
    // Test cases
    cout << "first_word(\"Hello world\") => \"" << first_word("Hello world") << "\"" << endl;
    cout << "first_word(\"greetings, friends\") => \"" << first_word("greetings, friends") << "\"" << endl;
    cout << "first_word(\"  spaces at start\") => \"" << first_word("  spaces at start") << "\"" << endl;
    cout << "first_word(\".dot at start\") => \"" << first_word(".dot at start") << "\"" << endl;
    cout << "first_word(\"OneWord\") => \"" << first_word("OneWord") << "\"" << endl;
    
    return 0;
}

// Function that returns the first word in a sentence
// INPUT PARAMETER(S): A string
// RETURN (cout): Nothing is outputted
// RETURN VALUE(S): A string (the first word)
string first_word(string text) {
    string firstWord = "";
    int startIndex = 0;
    
    // Skip leading spaces, dots, and commas
    while (startIndex < text.length() && 
           (text[startIndex] == ' ' || text[startIndex] == '.' || text[startIndex] == ',')) {
        startIndex++;
    }
    
    // Extract characters until we hit a space, comma, dot, or end of string
    for (int i = startIndex; i < text.length(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.') {
            break;  // Stop when we hit a delimiter
        }
        firstWord += text[i];
    }
    
    return firstWord;
}