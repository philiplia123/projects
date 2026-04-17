#include "Book.h"
#include <iostream> 
using namespace std; 

// default constructor 
Book::Book() {
    id = 0; 
    title = ""; 
    author = ""; 
    genre = ""; 
    checkedOut = false; 
    borrower = ""; 
}

// constructors and parameters 
Book::Book(int id, string title, string author, string genre) {
    this->id = id; 
    this->title = title; 
    this->author = author; 
    this->genre = genre; 
    this->checkedOut = false; 
    this->borrower = ""; 
}

// getters 
int Book::getId() {
    return id; 
}

string Book::getTitle() {
    return title; 
}

string Book::getAuthor() {
    return author; 
}
string Book::getGenre() {
    return genre; 
}

bool Book::isCheckedOut() {
    return checkedOut; 
}

string Book::getBorrower() {
    return borrower; 
}

// check out and check in
// mark the book as checked out by a borrower 
void Book::checkOut(string borrowerName) {
    checkedOut = true; 
    borrower = borrowerName; 
}

// mark book as returned 
void Book::checkIn() {
    checkedOut = false; 
    borrower = ""; 
}

// print book info to screen
void Book::display() {
    cout << "   [ID: " << id << "] " << title << " by " << author << " (" << genre << ") - ";
    if (checkedOut) {
        cout << "Checked out to " << borrower << endl;
    } else {
        cout << "Available" << endl;
    }
}