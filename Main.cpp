#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

// Print the main menu
void printMenu() {
    cout << "\n==============================" << endl;
    cout << "   Library Management System  " << endl;
    cout << "==============================" << endl;
    cout << "1. View All Books" << endl;
    cout << "2. View Available Books" << endl;
    cout << "3. View Checked Out Books" << endl;
    cout << "4. Add a Book" << endl;
    cout << "5. Remove a Book" << endl;
    cout << "6. Search by Title" << endl;
    cout << "7. Search by Author" << endl;
    cout << "8. Check Out a Book" << endl;
    cout << "9. Check In a Book" << endl;
    cout << "0. Exit" << endl;
    cout << "==============================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;

    cout << "Welcome to the Library Management System!" << endl;

    // Keep showing the menu until the user chooses to exit
    do {
        printMenu();
        cin >> choice;
        cin.ignore(); // clear the newline left in the input buffer

        if (choice == 1) {
            // Show all books
            library.displayAll();

        } else if (choice == 2) {
            // Show only available books
            library.displayAvailable();

        } else if (choice == 3) {
            // Show only checked out books
            library.displayCheckedOut();

        } else if (choice == 4) {
            // Add a new book
            string title, author, genre;
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter genre: ";
            getline(cin, genre);
            library.addBook(title, author, genre);

        } else if (choice == 5) {
            // Remove a book by ID
            int id;
            library.displayAll();
            cout << "Enter the ID of the book to remove: ";
            cin >> id;
            cin.ignore();
            library.removeBook(id);

        } else if (choice == 6) {
            // Search by title
            string title;
            cout << "Enter title to search: ";
            getline(cin, title);
            library.searchByTitle(title);

        } else if (choice == 7) {
            // Search by author
            string author;
            cout << "Enter author to search: ";
            getline(cin, author);
            library.searchByAuthor(author);

        } else if (choice == 8) {
            // Check out a book
            int id;
            string name;
            library.displayAvailable();
            cout << "Enter the ID of the book to check out: ";
            cin >> id;
            cin.ignore();
            cout << "Enter your name: ";
            getline(cin, name);
            library.checkOutBook(id, name);

        } else if (choice == 9) {
            // Check in a book
            int id;
            library.displayCheckedOut();
            cout << "Enter the ID of the book to check in: ";
            cin >> id;
            cin.ignore();
            library.checkInBook(id);

        } else if (choice == 0) {
            cout << "Goodbye!" << endl;

        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}