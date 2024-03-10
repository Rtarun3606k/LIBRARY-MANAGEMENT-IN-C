#include <stdio.h>
#include <string.h>
#define MAX_MEMBERS 100
#define MAX_BOOKS 100
#define MAX_TRANSACTIONS 100

// Book Details Module
typedef struct
{
    char ISBN[20];
    char title[100];
    char author[50];
    char genre[50];
    int quantity;
} Book;

void addBook(Book books[], int *bookCount)
{
    if (*bookCount >= MAX_BOOKS)
    {
        printf("Maximum number of books reached.\n");
        return;
    }

    Book newBook;

    // Prompt user to input book details
    printf("Enter ISBN: ");
    scanf("%19s", newBook.ISBN);
    getchar(); // Consume newline character

    printf("Enter Title: ");
    scanf("%99[^\n]", newBook.title);
    getchar(); // Consume newline character

    printf("Enter Author: ");
    scanf("%99[^\n]", newBook.author);
    getchar(); // Consume newline character

    printf("Enter Genre: ");
    scanf("%49[^\n]", newBook.genre);
    getchar(); // Consume newline character

    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);
    getchar(); // Consume newline character

    // Add the new book to the array
    books[*bookCount] = newBook;
    (*bookCount)++;

    printf("Book added successfully.\n");
}

// Function to update book details
void updateBook(Book books[], int bookCount)
{
    char ISBNToUpdate[20];
    printf("Enter ISBN of the book to update: ");
    scanf("%19s", ISBNToUpdate);
    getchar(); // Consume newline character

    int found = 0;
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].ISBN, ISBNToUpdate) == 0)
        {
            found = 1;
            // Display current book details
            printf("Current Book Details:\n");
            printf("ISBN: %s\n", books[i].ISBN);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Genre: %s\n", books[i].genre);
            printf("Quantity: %d\n", books[i].quantity);

            // Prompt user to update book details
            printf("Enter New Title: ");
            scanf("%99[^\n]", books[i].title);
            getchar(); // Consume newline character

            printf("Enter New Author: ");
            scanf("%99[^\n]", books[i].author);
            getchar(); // Consume newline character

            printf("Enter New Genre: ");
            scanf("%49[^\n]", books[i].genre);
            getchar(); // Consume newline character

            printf("Enter New Quantity: ");
            scanf("%d", &books[i].quantity);
            getchar(); // Consume newline character

            printf("Book details updated successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Book with ISBN %s not found.\n", ISBNToUpdate);
    }
}

// Function to delete a book from the library system
void deleteBook(Book books[], int *bookCount, const char *ISBN)
{
    int found = 0;
    for (int i = 0; i < *bookCount; i++)
    {
        if (strcmp(books[i].ISBN, ISBN) == 0)
        {
            // Shift books after the deleted book to the left
            for (int j = i; j < *bookCount - 1; j++)
            {
                books[j] = books[j + 1];
            }
            (*bookCount)--;
            printf("Book with ISBN %s deleted successfully.\n", ISBN);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Book with ISBN %s not found.\n", ISBN);
    }
}

// Function to display all books in the library system
void displayBooks(Book books[], int bookCount)
{
    printf("Book Details:\n");
    for (int i = 0; i < bookCount; i++)
    {
        printf("ISBN: %s\n", books[i].ISBN);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Genre: %s\n", books[i].genre);
        printf("Quantity: %d\n", books[i].quantity);
        printf("\n");
    }
}

// Member Details Module
typedef struct
{
    int memberID;
    char name[100];
    char address[100];
    char phoneNumber[15];
    // Transaction transactions[100]; // Array to store transactions for each member
    int transactionCount; // Number of transactions for the member
} Member;

// Function to add a new member to the library system
void addMember(Member members[], int *memberCount)
{
    if (*memberCount >= MAX_MEMBERS)
    {
        printf("Maximum number of members reached.\n");
        return;
    }

    Member newMember;

    // Prompt user to input member details
    printf("Enter Member ID: ");
    scanf("%d", &newMember.memberID);
    getchar(); // Consume newline character

    printf("Enter Name: ");
    scanf("%99[^\n]", newMember.name);
    getchar(); // Consume newline character

    printf("Enter Address: ");
    scanf("%99[^\n]", newMember.address);
    getchar(); // Consume newline character

    printf("Enter Phone Number: ");
    scanf("%14s", newMember.phoneNumber);
    getchar(); // Consume newline character

    // Add the new member to the array
    members[*memberCount] = newMember;
    (*memberCount)++;

    printf("Member added successfully.\n");
}

// Function to update member details
void updateMember(Member members[], int memberCount)
{
    int memberID;
    printf("Enter Member ID to update: ");
    scanf("%d", &memberID);
    getchar(); // Consume newline character

    int found = 0;
    for (int i = 0; i < memberCount; i++)
    {
        if (members[i].memberID == memberID)
        {
            found = 1;
            // Display current member details
            printf("Current Member Details:\n");
            printf("Member ID: %d\n", members[i].memberID);
            printf("Name: %s\n", members[i].name);
            printf("Address: %s\n", members[i].address);
            printf("Phone Number: %s\n", members[i].phoneNumber);

            // Prompt user to update member details
            printf("Enter New Name: ");
            scanf("%99[^\n]", members[i].name);
            getchar(); // Consume newline character

            printf("Enter New Address: ");
            scanf("%99[^\n]", members[i].address);
            getchar(); // Consume newline character

            printf("Enter New Phone Number: ");
            scanf("%14s", members[i].phoneNumber);
            getchar(); // Consume newline character

            printf("Member details updated successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Member with ID %d not found.\n", memberID);
    }
}

// Function to delete a member from the library system
void deleteMember(Member members[], int *memberCount, int memberID)
{
    int found = 0;
    for (int i = 0; i < *memberCount; i++)
    {
        if (members[i].memberID == memberID)
        {
            // Shift members after the deleted member to the left
            for (int j = i; j < *memberCount - 1; j++)
            {
                members[j] = members[j + 1];
            }
            (*memberCount)--;
            printf("Member with ID %d deleted successfully.\n", memberID);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Member with ID %d not found.\n", memberID);
    }
}

// Function to display all members in the library system
void displayMembers(Member members[], int memberCount)
{
    printf("Member Details:\n");
    for (int i = 0; i < memberCount; i++)
    {
        printf("Member ID: %d\n", members[i].memberID);
        printf("Name: %s\n", members[i].name);
        printf("Address: %s\n", members[i].address);
        printf("Phone Number: %s\n", members[i].phoneNumber);
        printf("\n");
    }
}

// Transaction Module
typedef struct
{
    int transactionID;
    int memberID;
    char ISBN[20];
    char issueDate[11];  // Format: YYYY-MM-DD
    char returnDate[11]; // Format: YYYY-MM-DD
} Transaction;

// Function to issue a book to a member
void issueBook(Transaction transactions[], int *transactionCount, int memberID, const char *ISBN, const char *issueDate)
{
    if (*transactionCount >= MAX_TRANSACTIONS)
    {
        printf("Maximum number of transactions reached.\n");
        return;
    }

    Transaction newTransaction;
    newTransaction.transactionID = *transactionCount + 1; // Incrementing transaction ID
    newTransaction.memberID = memberID;
    strcpy(newTransaction.ISBN, ISBN);
    strcpy(newTransaction.issueDate, issueDate);
    strcpy(newTransaction.returnDate, ""); // Initially set return date as empty string

    // Add the new transaction to the array
    transactions[*transactionCount] = newTransaction;
    (*transactionCount)++;

    printf("Book issued successfully.\n");
}

// Function to return a book
void returnBook(Transaction transactions[], int *transactionCount, int transactionID, const char *returnDate)
{
    int found = 0;
    for (int i = 0; i < *transactionCount; i++)
    {
        if (transactions[i].transactionID == transactionID)
        {
            // Update return date of the transaction
            strcpy(transactions[i].returnDate, returnDate);
            printf("Book returned successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Transaction with ID %d not found.\n", transactionID);
    }
}

// Function to display all transactions
void displayTransactions(Transaction transactions[], int transactionCount)
{
    printf("Transaction Details:\n");
    for (int i = 0; i < transactionCount; i++)
    {
        printf("Transaction ID: %d\n", transactions[i].transactionID);
        printf("Member ID: %d\n", transactions[i].memberID);
        printf("ISBN: %s\n", transactions[i].ISBN);
        printf("Issue Date: %s\n", transactions[i].issueDate);
        printf("Return Date: %s\n", transactions[i].returnDate);
        printf("\n");
    }
}

// Main function
int main()
{
    Book books[100];
    char ISBNToDelete[20];
    int bookCount = 0;
    // Member members[100];
    int memberCount = 0;
    Transaction transactions[100];
    int transactionCount = 0;
    int choice = 0;
    int memberid = 0;
    int transid = 0;
    char ISBM[20];
    char date[20];
    int exit;
    // Menu-driven interface to interact with the library management system
    Member members[MAX_MEMBERS];
    // printf("Adding a new member:\n");
    int memberIDToDelete;
    while (1)
    {
        printf("Welcome to LIBRARY management software \npress the number accoding to the option You want\n1. Add users\n2.Display all Users.\n3.Update User\n4.Delete user.\n5.ADD books.\n6.Display BOOKS.\n7.Delete Books.\n8.Update books.\n9.Display Transctions.\n10.Issue Transctions.\n11.Return Book\n12.Quit.\nYORU CHOICE:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("*************************************\n");
            addMember(members, &memberCount);
            printf("*************************************\n");
            break;
        case 3:
            printf("*************************************\n");
            updateMember(members, memberCount);
            printf("*************************************\n");
            break;

        case 2:
            printf("*************************************\n");
            displayMembers(members, memberCount);
            printf("*************************************\n");
            break;
        case 4:

            printf("Enter Member ID to delete: ");
            scanf("%d", &memberIDToDelete);
            printf("*************************************\n");
            deleteMember(members, &memberCount, memberIDToDelete);
            printf("*************************************\n");
            break;

        case 5:
            printf("*************************************\n");
            printf("Adding books:\n");
            addBook(books, &bookCount);
            printf("*************************************\n");
            break;

        case 6:
            printf("*************************************\n");
            printf("Book Details:\n");
            displayBooks(books, bookCount);
            printf("*************************************\n");
            break;

        case 7:
            printf("*************************************\n");
            printf("Enter ISBN of the book to delete: ");
            scanf("%19s", ISBNToDelete);
            deleteBook(books, &bookCount, ISBNToDelete);
            printf("*************************************\n");
            break;

        case 8:
            printf("*************************************\n");
            updateBook(books, bookCount);
            printf("*************************************\n");
            break;

        case 9:
            printf("*************************************\n");
            displayTransactions(transactions, transactionCount);
            printf("*************************************\n");
            break;

        case 10:
            printf("*************************************\n");
            printf("Enter the member id:");
            scanf("%d", &memberid);
            printf("Enter the ISBM id:");
            scanf("%s", ISBM);
            printf("Enter the DATE:");
            scanf("%s", date);

            issueBook(transactions, &transactionCount, memberid, ISBM, date);
            printf("*************************************\n");
            break;

        case 11:
            printf("*************************************\n");
            printf("Enter the transactions id:");
            scanf("%d", &transid);
            printf("Enter Return DATE:");
            scanf("%s", date);
            returnBook(transactions, &transactionCount, transid, date);
            printf("*************************************\n");
            break;
        case 12:
            printf("*************************************\n");
            printf("ARE YOU SURE U WANT TO  EXIT ALL THE DATYYA WILL  BE ERASED ?.\n1.Exit.\n2.Stay\nChoice: ");
            scanf("%d",&exit);
            if(exit==1){
                printf("THANK YOU FOR USING! SEE YOU SOON ");
                return 0;
            }
            printf("*************************************\n");
            break;

        default:
            printf("SELECET FROM THE OPTION");
            break;
        }
    }

    return 0;
}
