#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Insert at end */
struct node* insert(struct node *head, int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
        return temp;

    struct node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

/* Display list */
void display(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Sort list */
void sort(struct node *head) {
    struct node *i, *j;
    int t;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}

/* Concatenate two lists */
struct node* concat(struct node *h1, struct node *h2) {
    if (h1 == NULL)
        return h2;

    struct node *p = h1;
    while (p->next != NULL)
        p = p->next;

    p->next = h2;
    return h1;
}

/* Reverse list */
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *cur = head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

/* Main function */
int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int n, x, i;

    printf("Enter number of elements in List1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        list1 = insert(list1, x);
    }

    printf("Enter number of elements in List2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        list2 = insert(list2, x);
    }

    printf("\nList1: ");
    display(list1);

    sort(list1);
    printf("Sorted List1: ");
    display(list1);

    list1 = reverse(list1);
    printf("Reversed List1: ");
    display(list1);

    list1 = concat(list1, list2);
    printf("After Concatenation: ");
    display(list1);

    return 0;
}
