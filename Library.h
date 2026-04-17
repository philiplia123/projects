#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

// max number of books in the library 
const int MAX_BOOKS = 100; 

// library class manages an array of books 
class Library {
    private: 
        Book books[MAX_BOOKS]; // Array to store books 
        int bookCount; // how many books are currently stored 
        int nextId; // ID to assign to the next added book 

    public: 
        // constructor 
        Library(); 

        // book management 
        void addBook(string title, string author, string genre);
        void removeBook(int id); 

        // checkout and checkin
        void checkOutBook(int id, string borrower); 
        void checkInBook(int id);

        // search
        void searchByTitle(string title);
        void searchByAuthor(string author); 

        // display
        void displayAll(); 
        void displayAvailable();
        void displayCheckedOut();

        // file save and load 
        void saveToFile(); 
        void loadFromFile(); 
}; 

#endif