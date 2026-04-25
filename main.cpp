#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool availability;
    string dateAdd;

public:
    // Assign values to the book attributes
    void setBookDetails(string t, string a, string i, bool av, string d) {
        title = t;
        author = a;
        isbn = i;
        availability = av;
        dateAdd = d;
    }

    // Display the book information
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "-----------------------------" << endl;
    }

    // Borrow the book if it is available
    bool borrowBook() {
        if (availability) {
            availability = false;
            return true;
        }
        return false;
    }

    // Return the book
    void returnBook() {
        availability = true;
    }

    // Return ISBN for searching and sorting
    string getISBN() {
        return isbn;
    }

    // Sort books by ISBN using bubble sort
    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].getISBN() > books[j + 1].getISBN()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    Book library[5];

    //prueba de cambios//

    // Initialise 5 books
    library[0].setBookDetails("C++ Basics", "John Smith", "102", true, "12/01/2024");
    library[1].setBookDetails("Data Structures", "Jane Doe", "101", true, "05/03/2023");
    library[2].setBookDetails("Algorithms", "Mark Lee", "105", true, "18/07/2022");
    library[3].setBookDetails("OOP Concepts", "Anna White", "103", true, "21/09/2024");
    library[4].setBookDetails("Programming Logic", "David Brown", "104", true, "10/11/2021");

    // Sort books by ISBN
    Book::sortBookData(library, 5);

    string inputISBN;

    while (true) {
        cout << endl;
        cout << "Library Book List" << endl;
        cout << "=============================" << endl;

        for (int i = 0; i < 5; i++) {
            library[i].displayBookDetails();
        }

        cout << "Enter ISBN to borrow a book (0 to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Program terminated." << endl;
            break;
        }

        bool found = false;

        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;

                if (library[i].borrowBook()) {
                    cout << "Book borrowed successfully." << endl;
                    cout << "Updated book details:" << endl;
                    library[i].displayBookDetails();
                }
                else {
                    cout << "Error: This book is already borrowed." << endl;
                }

                break;
            }
        }

        if (!found) {
            cout << "Error: ISBN not found." << endl;
        }
    }

    return 0;
}// Final version of library book management system
