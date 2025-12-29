#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void create()
{
    int n, i, x;
    struct node *temp, *newnode;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &x);
        newnode->data = x;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}
void insert_left()
{
    int key, x;
    struct node *temp, *newnode;
    printf("Enter value to insert left of: ");
    scanf("%d", &key);
    printf("Enter new value: ");
    scanf("%d", &x);
    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = temp->prev;
    newnode->next = temp;
    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;
    temp->prev = newnode;
}
void delete_value()
{
    int key;
    struct node *temp;
    printf("Enter value to delete: ");
    scanf("%d", &key);
    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value not found\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int ch;
    while (1)
    {
        printf("1.Create 2.InsertLeft 3.Delete 4.Display 5.Exit\n");
        scanf("%d", &ch);
        if (ch == 1)
            create();
        else if (ch == 2)
            insert_left();
        else if (ch == 3)
            delete_value();
        else if (ch == 4)
            display();
        else if (ch == 5)
            break;
    }
    return 0;
}