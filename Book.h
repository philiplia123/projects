// Qihong Liang Final Project, COMSCi 201, 4/26/2026 

// header guards 
#ifndef BOOK_H
#define BOOK_H
 
#include <string>
using namespace std;
 
// Book class stores information about a single book
class Book {
private: // private variables 
    int id;
    string title;
    string author;
    string genre;
    bool checkedOut;
    string borrower;
 
public: // public functions to access and change the variables 
    // Constructor
    Book();
    Book(int id, string title, string author, string genre);
 
    // Getters
    int getId();
    string getTitle();
    string getAuthor();
    string getGenre();
    bool isCheckedOut();
    string getBorrower();
 
    // Check out and check in
    void checkOut(string borrowerName);
    void checkIn();
 
    // Print book info to screen
    void display();
};
 
#endif // end of header guard
 