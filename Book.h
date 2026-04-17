#ifndef BOOK_H
#define BOOK_H

#include <string> 
using namespace std; 

// book class stores information about a single book 
class Book {
    private: 
        int id; 
        string title; 
        string author; 
        string genre; 
        bool checkedOut; 
        string borrower; 

    public: 
        // constructors 
        Book(); 
        Book(int id, string title, string author, string genre); 

        // getters
        int getId(); 
        string getTitle(); 
        string getAuthor(); 
        string getGenre(); 
        bool isCheckedOut(); 
        string getBorrower(); 

        // checkout and checkin
        void checkOut(string borrowerName); 
        void checkIn(); 

        // Print book info to screen
        void display();     
}; 

#endif