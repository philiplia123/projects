// Qihong Liang Final Project, COMSCi 201, 4/26/2026 

#include "Library.h"
#include <iostream>
#include <fstream>
using namespace std;

// Constructor - set up an empty library and load any saved data
Library::Library() {
    bookCount = 0;
    nextId = 1;
    loadFromFile();
}

// Add a new book to the library
void Library::addBook(string title, string author, string genre) {    // used a plain array with a counter variable to store the books 
    // Check if there is room for another book
    if (bookCount >= MAX_BOOKS) {
        cout << "  Sorry, the library is full." << endl;
        return;
    }

    // Create the new book and add it to the array
    Book newBook(nextId, title, author, genre);
    books[bookCount] = newBook;
    bookCount++;
    nextId++;

    cout << "  Book added! (ID: " << (nextId - 1) << ")" << endl;
    saveToFile();
}

// Remove a book from the library by ID
void Library::removeBook(int id) {
    // Search for the book with the given ID
    int index = -1;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getId() == id) {
            index = i;
        }
    }

    // If not found, tell the user
    if (index == -1) {
        cout << "  No book found with ID " << id << "." << endl;
        return;
    }

    // Cannot remove a book that is checked out
    if (books[index].isCheckedOut()) {
        cout << "  Cannot remove a book that is currently checked out." << endl;
        return;
    }

    // Shift all books after this one left by one spot
    cout << "  Removed: " << books[index].getTitle() << endl;
    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }
    bookCount--;
    saveToFile();
}

// Check out a book to a borrower
void Library::checkOutBook(int id, string borrower) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getId() == id) {
            if (books[i].isCheckedOut()) {
                cout << "  That book is already checked out to " << books[i].getBorrower() << "." << endl;
            } else {
                books[i].checkOut(borrower);
                cout << "  \"" << books[i].getTitle() << "\" checked out to " << borrower << "." << endl;
                saveToFile();
            }
            return;
        }
    }
    cout << "  No book found with ID " << id << "." << endl;
}

// Check in a book by ID
void Library::checkInBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getId() == id) {
            if (!books[i].isCheckedOut()) {
                cout << "  That book is not currently checked out." << endl;
            } else {
                books[i].checkIn();
                cout << "  \"" << books[i].getTitle() << "\" has been returned. Thank you!" << endl;
                saveToFile();
            }
            return;
        }
    }
    cout << "  No book found with ID " << id << "." << endl;
}

// Search for books whose title contains the search string
void Library::searchByTitle(string title) {
    cout << "\n  Search results for title \"" << title << "\":" << endl;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        // .find() searches for the query inside the title string
        // string::npos is a special value that means "not found"
        // so this condition is true when the title contains the search word
        if (books[i].getTitle().find(title) != string::npos) {
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "  No books found." << endl;
    }
}

// Search for books by a specific author
void Library::searchByAuthor(string author) {
    cout << "\n  Search results for author \"" << author << "\":" << endl;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        // same as above - checks if the author name contains the search word
        if (books[i].getAuthor().find(author) != string::npos) {
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "  No books found." << endl;
    }
}

// Display all books in the library
void Library::displayAll() {
    if (bookCount == 0) {
        cout << "  The library has no books yet." << endl;
        return;
    }
    cout << "\n  --- All Books (" << bookCount << " total) ---" << endl;
    for (int i = 0; i < bookCount; i++) {
        books[i].display();
    }
}

// Display only books that are available
void Library::displayAvailable() {
    cout << "\n  --- Available Books ---" << endl;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isCheckedOut()) {
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "  No books are currently available." << endl;
    }
}

// Display only books that are checked out
void Library::displayCheckedOut() {
    cout << "\n  --- Checked Out Books ---" << endl;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isCheckedOut()) {
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "  No books are currently checked out." << endl;
    }
}

// Save all book data to a text file
void Library::saveToFile() {   // file I/O --> everytime a change is made, it writes to a text file, and when the program starts it reads the file back in  
    ofstream outFile("library_data.txt");

    if (!outFile) {
        cout << "  Warning: Could not open file for saving." << endl;
        return;
    }

    // First line: save the next ID and book count
    outFile << nextId << " " << bookCount << endl;

    // Save each book on its own line
    for (int i = 0; i < bookCount; i++) {
        outFile << books[i].getId() << endl;
        outFile << books[i].getTitle() << endl;
        outFile << books[i].getAuthor() << endl;
        outFile << books[i].getGenre() << endl;
        outFile << books[i].isCheckedOut() << endl;
        outFile << books[i].getBorrower() << endl;
    }

    outFile.close();
}

// Load book data from the text file
void Library::loadFromFile() {
    ifstream inFile("library_data.txt");

    // If file doesn't exist yet, just return
    if (!inFile) {
        return;
    }

    // Read the next ID and book count from the first line
    inFile >> nextId >> bookCount;
    inFile.ignore(); // after using >>, a newline is left in the buffer - ignore() discards it so getline() works correctly below

    // Read each book's data
    for (int i = 0; i < bookCount; i++) {
        int id;
        string title, author, genre, borrower;
        bool checkedOut;

        inFile >> id;
        inFile.ignore(); // discard the leftover newline after reading the id number
        getline(inFile, title);
        getline(inFile, author);
        getline(inFile, genre);
        inFile >> checkedOut;
        inFile.ignore(); // discard the leftover newline after reading the checkedOut value
        getline(inFile, borrower);

        books[i] = Book(id, title, author, genre);
        if (checkedOut) {
            books[i].checkOut(borrower);
        }
    }

    inFile.close();
}