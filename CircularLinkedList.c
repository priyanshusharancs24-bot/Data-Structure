#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(HEAD)\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;

    if(head == NULL) {
        new->next = new;   // circular link
        return new;
    }

    struct Node* temp = head;

    // move to last node
    while(temp->next != head)
        temp = temp->next;

    temp->next = new;  // last node points to new
    new->next = head;  // new node points to old head

    return new;        // new becomes head
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;

    if(head == NULL) {
        new->next = new;
        return new;
    }

    struct Node* temp = head;

    // go to last node
    while(temp->next != head)
        temp = temp->next;

    temp->next = new;
    new->next = head;

    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if(head == NULL) return NULL;

    if(head->next == head) { // only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;

    // go to last node
    while(temp->next != head)
        temp = temp->next;

    struct Node* del = head;
    temp->next = head->next;
    head = head->next;

    free(del);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if(head == NULL) return NULL;

    if(head->next == head) { // only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // reach last node
    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    return head;
}

int search(struct Node* head, int key) {
    if(head == NULL) return -1;

    struct Node* temp = head;
    int index = 0;

    do {
        if(temp->data == key)
            return index;

        temp = temp->next;
        index++;

    } while(temp != head);

    return -1;  // not found
}


int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("Circular List after insert at beginning:\n");
    traverse(head);

    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);
    printf("\nAfter inserting at end:\n");
    traverse(head);

    head = deleteAtBeginning(head);
    printf("\nAfter deleting at beginning:\n");
    traverse(head);

    head = deleteAtEnd(head);
    printf("\nAfter deleting at end:\n");
    traverse(head);

    printf("\nSearching for 30... Index: %d\n", search(head, 30));
    printf("Searching for 100... Index: %d\n", search(head, 100));

    return 0;
}
