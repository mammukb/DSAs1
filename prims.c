#include <stdio.h>
void prims(int adj[10][10], int n);

int main()
{
    int n;
    printf("Enter the Number Vertices");
    scanf("%d", &n);
    int adj[n][n], vist[n], min = 999, u, v, cost = 0;
    printf("Enter the Cost Adjecency Matrix :");
    for (int i = 0; i < n; i++)
    {
        vist[i] = 0;
        for (int j = 0; j < n; j++)
        {
            printf("Weight[%d][%d] : ", i, j);

            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
                adj[i][j] = 999;
            if (adj[i][j] < min)
            {
                min = adj[i][j];
                u = i;
                v = j;
            }
        }
    }
    cost += min;
    vist[u] = 1;
    vist[u] = 1;
    printf("SPANNING TREE : EDGES ARE \n");
    printf("{%d,%d} = %d", u, v, min);
    int e = 0;
    while (e < n - 1)
    {
        min = 999;

        for (int i = 0; i < n; i++)
        {
            if (vist[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {

                    if (adj[i][j] < min && vist[j] == 0)
                    {
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
            cost += min;
            vist[v] = 1;
            printf("{%d,%d} = %d", u, v, min);
        }
        e++;
    }
    printf("Total Cost = %d", cost);
}
