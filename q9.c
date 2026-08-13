#include <stdio.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int totalCopies;
    int availableCopies;
};

int main() {
    struct Book books[100];
    int count = 0;
    int choice, id, i;

    while (1) {
        printf("\n\n===== LIBRARY MENU =====\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter Book ID: ");
            scanf("%d", &books[count].id);

            printf("Enter Book Title: ");
            scanf("%s", books[count].title);

            printf("Enter Author Name: ");
            scanf("%s", books[count].author);

            printf("Enter Total Copies: ");
            scanf("%d", &books[count].totalCopies);

            books[count].availableCopies = books[count].totalCopies;

            count++;

            printf("Book added successfully!\n");
        }

        else if (choice == 2) {
            printf("\nEnter Book ID to search: ");
            scanf("%d", &id);

            int found = 0;

            for (i = 0; i < count; i++) {
                if (books[i].id == id) {
                    printf("\nBook Found!");
                    printf("\nTitle: %s", books[i].title);
                    printf("\nAuthor: %s", books[i].author);
                    printf("\nAvailable Copies: %d\n",
                           books[i].availableCopies);

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found!\n");
        }

        else if (choice == 3) {
            printf("\nEnter Book ID to issue: ");
            scanf("%d", &id);

            int found = 0;

            for (i = 0; i < count; i++) {
                if (books[i].id == id) {
                    found = 1;

                    if (books[i].availableCopies > 0) {
                        books[i].availableCopies--;
                        printf("Book issued successfully!\n");
                    }
                    else {
                        printf("Book is currently unavailable!\n");
                    }

                    break;
                }
            }

            if (!found)
                printf("Book not found!\n");
        }

        else if (choice == 4) {
            printf("\nEnter Book ID to return: ");
            scanf("%d", &id);

            int found = 0;

            for (i = 0; i < count; i++) {
                if (books[i].id == id) {
                    found = 1;

                    if (books[i].availableCopies <
                        books[i].totalCopies) {

                        books[i].availableCopies++;

                        printf("Book returned successfully!\n");
                    }
                    else {
                        printf("All copies are already in library!\n");
                    }

                    break;
                }
            }

            if (!found)
                printf("Book not found!\n");
        }

        else if (choice == 5) {
            printf("\n----- UNAVAILABLE BOOKS -----\n");

            for (i = 0; i < count; i++) {
                if (books[i].availableCopies == 0) {
                    printf("ID: %d\n", books[i].id);
                    printf("Title: %s\n", books[i].title);
                }
            }
        }

        else if (choice == 6) {
            printf("Exiting program...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}