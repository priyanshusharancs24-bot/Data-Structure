#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];
int n;
int graph[MAX][MAX];
void enqueue(int value)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}
int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}
void bfs(int start)
{
    int i;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front <= rear)
    {
        int current = dequeue();
        printf("%d ", current);
        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    bfs(start);
    return 0;
}