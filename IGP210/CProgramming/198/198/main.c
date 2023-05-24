//
//  main.c
//  198
//
//  Created by Chang on 2023-05-04.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each node in the linked list
struct node {
    char data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct node** head, char data) {
    struct node* newNode = createNode(data);
    struct node* current = *head;
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the contents of the linked list
void printList(struct node* head) {
    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }
}

int main() {
    char input[] = "He hass doena fanthactik jobb.";
    int length = strlen(input);
    struct node* head = NULL;
    struct node* current = NULL;
    for (int i = 0; i < length; i++) {
        if (input[i] == ' ') {
            // Space character found, print the current word and add a space to the linked list
            printList(head);
            printf(" ");
            insertNode(&head, ' ');
            current = NULL;
        }
        else {
            // Add the current character to the linked list
            if (current == NULL) {
                current = createNode(input[i]);
                head = current;
            }
            else {
                current->next = createNode(input[i]);
                current = current->next;
            }
        }
    }
    // Print the final word
    printList(head);
    printf("\n");
    // Free the memory allocated for the linked list
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
    return 0;
}
