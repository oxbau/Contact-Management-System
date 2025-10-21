#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define the structure for a contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

// Global array to store contacts and a counter
struct Contact contacts[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", contacts[contact_count].name);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]", contacts[contact_count].phone);

    printf("Enter Email: ");
    scanf(" %[^\n]", contacts[contact_count].email);

    contact_count++;
    printf("Contact added successfully!\n");
}

void display_contacts() {
    if (contact_count == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contact_count; i++) {
        printf("Contact #%d\n", i + 1);
        printf("  Name: %s\n", contacts[i].name);
        printf("  Phone: %s\n", contacts[i].phone);
        printf("  Email: %s\n", contacts[i].email);
        printf("--------------------\n");
    }
}

void search_contact() {
    char search_name[50];
    int found = 0;

    if (contact_count == 0) {
        printf("No contacts to search.\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", search_name);

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("\n--- Contact Found ---\n");
            printf("  Name: %s\n", contacts[i].name);
            printf("  Phone: %s\n", contacts[i].phone);
            printf("  Email: %s\n", contacts[i].email);
            printf("---------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
