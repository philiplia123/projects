// Qihong Liang Final Project, COMSCi 201, 4/26/2026 

// header guards 
#ifndef LIBRARY_H
#define LIBRARY_H
 
#include "Book.h"
 
// Maximum number of books the library can hold
const int MAX_BOOKS = 100;
 
// Library class manages an array of books
class Library {
private:
    Book books[MAX_BOOKS]; // Array to store books
    int bookCount;         // How many books are currently stored
    int nextId;            // ID to assign to the next added book
 
public:
    // Constructor
    Library();
 
    // Book management
    void addBook(string title, string author, string genre);
    void removeBook(int id);
 
    // Checkout / check-in
    void checkOutBook(int id, string borrower);
    void checkInBook(int id);
 
    // Search
    void searchByTitle(string title);
    void searchByAuthor(string author);
 
    // Display
    void displayAll();
    void displayAvailable();
    void displayCheckedOut();
 
    // File save and load
    void saveToFile();
    void loadFromFile();
};
 
#endif // end of header guard