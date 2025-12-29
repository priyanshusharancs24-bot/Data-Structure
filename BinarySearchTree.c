#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->left = NULL;
    t->right = NULL;
    return t;
}
struct node *insert(struct node *root, int x)
{
    if (root == NULL)
        return newNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    struct node *root = NULL;
    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values (unsorted):\n");
    while (n--)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("\nInorder Traversal : ");
    inorder(root);
    printf("\nPreorder Traversal : ");
    preorder(root);
    printf("\nPostorder Traversal : ");
    postorder(root);
    return 0;
}