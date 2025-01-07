#include <stdio.h>
int bfs(int a[][5], int n);

int main()
{
    int i, n = 5;

    int a[5][5] = {0, 1, 0, 1, 1,
                   1, 0, 1, 0, 0,
                   0, 1, 0, 1, 1,
                   1, 0, 1, 0, 0,
                   1, 0, 1, 0, 0};
    bfs(a, n);
}

int bfs(int a[][5], int n)
{
    int q[n], front = -1, rear = -1, v[5] = {0}, st;
    printf("Enter the Starting Vertex :");
    scanf("%d", &st);
    q[++rear] = st;
    v[st] = 1;

    printf("BFS Traversal is :");
    while (front < rear)
    {
        st = q[++front];
        printf("%d", st);

        for (int j = 0; j < n; j++)
        {
            if (a[st][j] == 1 && v[j] == 0)
            {
                v[j] = 1;
                q[++rear] = j;
            }
        }
    }
}
