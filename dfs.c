#include <stdio.h>

void dfs(int a[][5], int n); // Changed the parameter declaration

int main()
{
    int i, n = 5;

    int a[5][5] = {0, 1, 0, 1, 1,
                   1, 0, 1, 0, 0,
                   0, 1, 0, 1, 1,
                   1, 0, 1, 0, 0,
                   1, 0, 1, 0, 0};

    dfs(a, n);

    return 0;
}

void dfs(int a[][5], int n)
{

    int stack[5], visited[5] = {0};
    int top = 0, st, count = 0, f;

    printf("Enter the vertex to start: ");
    scanf("%d", &st);
    stack[top] = st;
    visited[st] = 1;
    printf("DFS Traversal is : %d\t", st);

    while (top != -1)
    {
        f = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[st][i] == 1 && !visited[i])
            {
                printf("%d\t", i);
                top++;
                stack[top] = i;
                st = i;
                f = 1;
                visited[i] = 1;
                break;
            }
        }
        if (f == 0)
        {
            {
                st = stack[top];
                top--;
            }
        }
        count++;
    }
}
