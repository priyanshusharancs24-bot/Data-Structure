#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void create(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("First element deleted.\n");
}
void deleteLast()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last element deleted.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    printf("Last element deleted.\n");
}
void deleteSpecific(int key)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (head->data == key)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Element %d deleted.\n", key);
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;
    if (temp->next == NULL)
    {
        printf("Element not found!\n");
        return;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Element %d deleted.\n", key);
}
void display()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create (Insert at end)\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Last Element\n");
        printf("4. Delete Specific Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            create(value);
            break;
        case 2:
            deleteFirst();
            break;
        case 3:
            deleteLast();
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteSpecific(value);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}