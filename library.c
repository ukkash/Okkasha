#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50

// Structure for Book
struct Book {
    int id;
    char title[100];
    char author[100];
};

// Structure for Member
struct Member {
    int id;
    char name[100];
};

// Global arrays to store books and members
struct Book library[MAX_BOOKS];
struct Member members[MAX_MEMBERS];
int bookCount = 0;
int memberCount = 0;

// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    
    struct Book newBook;
    
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);
    getchar(); // Consume newline character
    printf("Enter book title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0; // Remove newline character
    printf("Enter book author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0; // Remove newline character

    library[bookCount++] = newBook;
    printf("Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("\nBooks in the Library:\n");
    printf("ID\tTitle\t\tAuthor\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%s\t%s\n", library[i].id, library[i].title, library[i].author);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Exiting the system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
