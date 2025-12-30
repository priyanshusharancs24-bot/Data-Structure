#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void push(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct node *temp = top;
    printf("Popped: %d\n", top->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    struct node *p = top;
    printf("Stack: ");

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void enqueue(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted: %d\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void displayQueue() {
    struct node *p = front;
    printf("Queue: ");

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1 Push (Stack)\n");
        printf("2 Pop (Stack)\n");
        printf("3 Display Stack\n");
        printf("4 Insert (Queue)\n");
        printf("5 Delete (Queue)\n");
        printf("6 Display Queue\n");
        printf("7 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
