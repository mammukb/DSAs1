#include <stdio.h>

void dfs(int a[][5], int n); // Changed the parameter declaration

int main()
{
    int i, n;
    printf("Enter the number of vertices :");
    scanf("%d", &n);

    int a[5][5] = {0, 1, 0, 1, 1,
                   1, 0, 1, 0, 0,
                   0, 1, 0, 1, 1,
                   1, 0, 1, 0, 0,
                   1, 0, 1, 0, 0};
    // printf("Enter the adjacency matrix:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("Enter the Vertex[%d][%d]: ", i, j);
    //         scanf("%d", &a[i][j]);
    //     }
    // }

    dfs(a, n);

    return 0;
}

void dfs(int a[][5], int n)
{
    int stack[5], visited[5] = {0};
    int top = -1, st;

    printf("Enter the vertex to start: ");
    scanf("%d", &st);
    stack[++top] = st;
    visited[st] = 1;

    printf("DFS Traversal is: ");

    while (top != -1)
    {
        st = stack[top--];
        printf("%d ", st);

        for (int j = 0; j < n; j++)
        {
            if (a[st][j] == 1 && !visited[j])
            {
                stack[++top] = j;
                visited[j] = 1;
                break;
            }
        }
    }
}
