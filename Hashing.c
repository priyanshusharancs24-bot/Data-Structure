#include <stdio.h>
#define MAX 100
int main()
{
    int hashTable[MAX];
    int m, n, key, index, i;
    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        hashTable[i] = -1;
    }
    printf("Enter number of employee records: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);
        index = key % m; // Hash function
        while (hashTable[index] != -1)
        {
            index = (index + 1) % m;
        }
        hashTable[index] = key;
    }
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\n");
    for (i = 0; i < m; i++)
    {
        if (hashTable[i] != -1)
            printf("%d\t%d\n", i, hashTable[i]);
        else
            printf("%d\t--\n", i);
    }
    return 0;
}