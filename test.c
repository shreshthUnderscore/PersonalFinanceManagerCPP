#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dnode {
    char name[30];
    char number[50];
    struct dnode *prev, *next;
};

struct dnode *head = NULL;

// Function to accept a new contact
void accept() {
    char number[50];
    char name[30];
    char ans;

    do {
        struct dnode *temp = (struct dnode *)malloc(sizeof(struct dnode));
        if (temp == NULL) {
            printf("Memory allocation failed. Exiting.\n");
            exit(1);
        }

        printf("ENTER NAME: ");
        scanf("%29s", name); // Safely read up to 29 characters to avoid buffer overflow
        printf("ENTER NUMBER: ");
        scanf("%49s", number); // Safely read up to 49 characters

        while (strlen(number) != 10) {
            printf("ENTER VALID NUMBER: ");
            scanf("%49s", number);
        }

        strcpy(temp->name, name);
        strcpy(temp->number, number);
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            struct dnode *ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }

        printf("DO YOU WANT TO CONTINUE? (y/n): ");
        scanf(" %c", &ans);
    } while (ans == 'y');
}

// Function to display the phone book
void display() {
    struct dnode *ptr = head;
    printf("\nPhone Book Entries:\n");
    while (ptr != NULL) {
        printf("Name: %s\n", ptr->name);
        printf("Number: %s\n\n", ptr->number);
        ptr = ptr->next;
    }
}

// Function to update details of an existing contact
void update(char name[30]) {
    char ans;
    int c;
    struct dnode *ptr = head;

    while (ptr != NULL) {
        if (strcmp(name, ptr->name) == 0) {
            do {
                printf("\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n");
                scanf("%d", &c);

                switch (c) {
                    case 1:
                        printf("ENTER NEW NAME: ");
                        scanf("%29s", ptr->name);
                        break;
                    case 2:
                        printf("ENTER NEW PHONE NUMBER: ");
                        scanf("%49s", ptr->number);
                        while (strlen(ptr->number) != 10) {
                            printf("ENTER VALID NUMBER: ");
                            scanf("%49s", ptr->number);
                        }
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }

                printf("DO YOU WANT TO CONTINUE UPDATING? (y/n): ");
                scanf(" %c", &ans);
            } while (ans == 'y');
        }
        ptr = ptr->next;
    }
}

// Function to delete a contact by name
void deletecontact(char name[30]) {
    struct dnode *ptr = head;

    while (ptr != NULL) {
        if (strcmp(name, ptr->name) == 0) {
            if (ptr->prev != NULL) {
                ptr->prev->next = ptr->next;
            } else {
                head = ptr->next;
            }

            if (ptr->next != NULL) {
                ptr->next->prev = ptr->prev;
            }

            free(ptr);
            printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
            return;
        }
        ptr = ptr->next;
    }

    printf("YOUR ENTERED NAME IS NOT IN THE LIST...\n");
}

// Function to delete contacts with the same name
void deletesamename() {
    struct dnode *ptr1 = head;

    while (ptr1 != NULL) {
        struct dnode *ptr2 = ptr1;

        while (ptr2->next != NULL) {
            if (strcmp(ptr1->name, ptr2->next->name) == 0) {
                struct dnode *dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                if (ptr2->next != NULL) {
                    ptr2->next->prev = ptr2;
                }
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

// Function to delete contacts with the same number
void deletesamenumber() {
    struct dnode *ptr1 = head;

    while (ptr1 != NULL) {
        struct dnode *ptr2 = ptr1;

        while (ptr2->next != NULL) {
            if (strcmp(ptr1->number, ptr2->next->number) == 0) {
                struct dnode *dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                if (ptr2->next != NULL) {
                    ptr2->next->prev = ptr2;
                }
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

int main() {
    char ans;
    int ch, a;
    char name[30]; // Used for user input

    printf("**************   PHONE BOOK   ********************\n");

    do {
        printf("1. Insert new contact\n");
        printf("2. Display your phone book\n");
        printf("3. Update details on an existing contact\n");
        printf("4. Delete contact\n");
        printf("5. Delete contacts with the same name\n");
        printf("6. Delete contacts with the same number\n");
        printf("7. Search\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                accept();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter the name of the person whose details you want to update: ");
                scanf("%29s", name);
                update(name);
                break;

            case 4:
                printf("Enter the name you want to delete from the phone book: ");
                scanf("%29s", name);
                deletecontact(name);
                break;

            case 5:
                deletesamename();
                break;

            case 6:
                deletesamenumber();
                break;

            case 7:
                do {
                    printf("1. SEARCH BY NAME\n");
                    printf("2. SEARCH BY NUMBER\n");
                    printf("Enter your choice: ");
                    scanf("%d", &a);

                    switch (a) {
                        case 1:
                            printf("ENTER THE NAME TO BE SEARCHED: ");
                            scanf("%29s", name);
                            // Functionality for searching by name
                            struct dnode *ptr = head;
                            int found = 0;
                            while (ptr != NULL) {
                                if (strcmp(name, ptr->name) == 0) {
                                    found = 1;
                                    printf("\nContact Found:\n");
                                    printf("Name: %s\n", ptr->name);
                                    printf("Number: %s\n\n");
                                }
                                ptr = ptr->next;
                            }
                            if (!found) {
                                printf("Contact not found with the name: %s\n", name);
                            }
                            break;

                        case 2:
                            printf("ENTER THE NUMBER TO BE SEARCHED: ");
                            scanf("%49s", name);
                            // Functionality for searching by number
                            struct dnode *ptr_num = head;
                            int found_num = 0;
                            while (ptr_num != NULL) {
                                if (strcmp(name, ptr_num->number) == 0) {
                                    found_num = 1;
                                    printf("\nContact Found:\n");
                                    printf("Name: %s\n", ptr_num->name);
                                    printf("Number: %s\n\n");
                                }
                                ptr_num = ptr_num->next;
                            }
                            if (!found_num) {
                                printf("Contact not found with the number: %s\n", name);
                            }
                            break;

                        default:
                            printf("NO PROPER INPUT GIVEN...\n");
                    }

                    printf("DO YOU WANT TO CONTINUE SEARCHING? (y/n): ");
                    scanf(" %c", &ans);
                } while (ans == 'y');
                break;

            case 8:
                printf("Exiting the program. Goodbye!\n");
                // Implement memory cleanup logic by freeing all allocated memory
                while (head != NULL) {
                    struct dnode *temp = head;
                    head = head->next;
                    free(temp);
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("DO YOU WANT TO CONTINUE OPERATIONS? (y/n): ");
        scanf(" %c", &ans);
    } while (ans == 'y');

    return 0;
}
