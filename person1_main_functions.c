#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void printList(Node* head) {
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);

    printf("Initial Linked List:\n");
    printList(head);

    searchList(head, 15);

    printf("Deleting node with value 15...\n");
    deleteNode(&head, 15);
    printList(head);

    return 0;
}
