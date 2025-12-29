#include <stdio.h>
#define MAX 10
int n;
int graph[MAX][MAX];
int visited[MAX];
void dfs(int vertex)
{
    int i;
    visited[vertex] = 1;
    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    int i, j;
    int connected = 1;
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
    {
        visited[i] = 0;
    }
    dfs(0);
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT CONNECTED.\n");
    return 0;
}