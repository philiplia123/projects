#include "Library.h"
#include <iostream> 
#include <fstream>

using namespace std; 

// constructor - set up empty library and load any saved data 
Library::Library() {
    bookCount = 0; 
    nextId = 1; 
    loadFromFile(); 
}

// add a new book to the library
void Library::addBook(string title, string author, string genre) {
    // check if there is room for another book 
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full. Cannot add more books." << endl;
        return; 
    }

    // create the new book and add it to the array 
    Book newBook(nextId, title, author, genre); 
    books[bookCount] = newBook;
    bookCount++; 
    nextId++; 

    cout << "Book added! (ID: " << (nextId - 1) << ")" << endl;
    saveToFile(); 
}

// remove a book from the library by ID
void Library::removeBook(int id) {
    // search the book with the given ID
    int index = -1; 
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getId() == id) {
            index = i; 
        }
    }

    // if not found, tell the user
    if (index == -1) {
        cout << "No book found with ID " << id << "." << endl;
        return; 
    }

    // cannot remove a book that's checked out 
    if (books[index].isCheckedOut()) {
        cout << "Cannot remove a book that is currently checked out." << endl;
        return;
    }

    // shifts all book after this one left by one spot 
    cout << "   Removed: " << books[index].getTitle() << endl; 
    for (int i = index; i < bookCount -1; i++) {
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

// check in a book by ID
void Library::checkInBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getId() == id) {
            if (!books[i].isCheckedOut()) {
                cout << "   That book is not currently checked out." << endl; 
            }   else {
                    books[i].checkIn(); 
                    cout << "   \"" << books[i].getTitle() << "\" has been returned. Thank you!" << endl;   
                    saveToFile();
            }
            return; 
        }
    }
    cout << "   No book found with ID " << id << "." << endl;
}

// search for books whose title contains the search term (case insensitive)
void Library::searchByTitle(string title) {
    cout << "\n Search results for title \"" << title << "\":" << endl;
    bool found = false; 
    for (int i = 0; i < bookCount; i++) {
        // check if the title contains the search term (case insensitive)
        if (books[i].getTitle().find(title) != string::npos) {
            books[i].display(); 
            found = true; 
        }
    }
    if (!found) {
        cout << "   No books found with that title." << endl;
    }
}

// Search for books by a specific author
void Library::searchByAuthor(string author) {
    cout << "\n  Search results for author \"" << author << "\":" << endl;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getAuthor().find(author) != string::npos) {
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "  No books found." << endl;
    }
}

// display all books in the library
void Library::displayAll() {
        if (bookCount == 0) {
            cout << " The library has no books yet." << endl; 
            return;     
        }
        cout << "\n --- All books (" << bookCount << " total) ---" << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].display(); 
        }
}

// display only available books
void Library::displayAvailable() {
    cout << "\n --- Available books ---" << endl; 
    bool found = false; 
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isCheckedOut()) {
            books[i].display(); 
            found = true; 
        }
    }
    if (!found) {
        cout << "   No available books at the moment." << endl;
    }
}

// display only checked out books
void Library::displayCheckedOut() {
    cout << "\n --- Checked out books ---" << endl; 
    bool found = false; 
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isCheckedOut()) {
            books[i].display(); 
            found = true; 
        }
    }
    if (!found) {
        cout << "   No books are currently checked out." << endl;
    }
}

// save all book data to a text file so it can load faster 
void Library::saveToFile() {
    ofstream outFile("Library_data.txt"); 

    if (!outFile) {
        cout << "   Warning: could not open file for saving." << endl;
        return; 
    }

    // First line: save the next ID and book count 
    outFile << nextId << " " << bookCount << endl; 

    // save each book on its own line 
    for (int i = 0; i < bookCount; i++) {
        outFile << books[i].getId() << ",";
        outFile << books[i].getTitle() << ","; 
        outFile << books[i].getAuthor() << ",";
        outFile << books[i].getGenre() << ","; 
        outFile << books[i].isCheckedOut() << ","; 
        outFile << books[i].getBorrower() << endl;
    }
    outFile.close();
}

// load book data from the text file 
void Library::loadFromFile() {
    ifstream inFile("Library_data.txt"); 

    // if the file doesn't exist, just return 
    if (inFile) {
        return; 
    }

    // read the next ID and book count from the first line 
    inFile >> nextId >> bookCount; 
    inFile.ignore(); // ignore the newline after the first line

    // read each book's data
    for (int i = 0; i < bookCount; i++) {
        int id; 
        string title, author, genre, borrower; 
        bool checkedOut; 

        inFile >> id; 
        inFile.ignore(); 
        getline(inFile, title); 
        getline(inFile, author); 
        getline(inFile, genre); 
        inFile >> checkedOut; 
        inFile.ignore();
        getline(inFile, borrower); 

        books[i] = Book(id, title, author, genre); 
        if (checkedOut) {
            books[i].checkOut(borrower); --> // checkedOut is a private variable, not a function. It should be calling the checkOut method instead. --> fixed 
        }
    }

    inFile.close(); 
}

