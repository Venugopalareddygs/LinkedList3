#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


void searchList(Node* head, int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found in the list.\n", key);
}
