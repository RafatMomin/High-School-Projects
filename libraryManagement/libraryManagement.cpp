#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//@ author Rafat Momin
//date: 03/07/2022
#define MAX_BOOKS 100

// Structure to represent a book

typedef struct {
    int bookID;
    char title[100];
    char author[100];
    int isBorrowed;
} Book;

Book library[MAX_BOOKS]; // Array to store all books
int totalBooks = 0; // Counter to keep track of the total number of books

// Function to add a new book to the library
void addBook() {
    if (totalBooks >= MAX_BOOKS) {
        printf("Cannot add more books. Maximum limit reached.\n");
        return;
    }

    Book newBook;
    newBook.bookID = totalBooks + 1;

    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Enter book author: ");
    scanf(" %[^\n]", newBook.author);

    newBook.isBorrowed = 0; // Initially, the book is not borrowed
    library[totalBooks] = newBook;
    totalBooks++;

    printf("Book added successfully. Book ID: %d\n", newBook.bookID);
}

// Function to borrow a book from the library
void borrowBook() {
    int bookID;

    printf("Enter book ID to borrow: ");
    scanf("%d", &bookID);

    if (bookID <= 0 || bookID > totalBooks) {
        printf("Invalid book ID.\n");
        return;
    }

    if (library[bookID - 1].isBorrowed) {
        printf("Sorry, the book is already borrowed.\n");
        return;
    }

    library[bookID - 1].isBorrowed = 1;
    printf("Book borrowed successfully.\n");
}

// Function to return a book to the library
void returnBook() {
    int bookID;

    printf("Enter book ID to return: ");
    scanf("%d", &bookID);

    if (bookID <= 0 || bookID > totalBooks) {
        printf("Invalid book ID.\n");
        return;
    }

    if (!library[bookID - 1].isBorrowed) {
        printf("This book was not borrowed.\n");
        return;
    }

    library[bookID - 1].isBorrowed = 0;
    printf("Book returned successfully.\n");
}

// Function to display all books in the library
void displayBooks() {
    if (totalBooks == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nBooks in Library:\n");
    for (int i = 0; i < totalBooks; i++) {
        printf("Book ID: %d\n", library[i].bookID);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Status: %s\n\n", library[i].isBorrowed ? "Borrowed" : "Available");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Borrow Book\n");
        printf("3. Return Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                borrowBook();
                break;
            case 3:
                returnBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
