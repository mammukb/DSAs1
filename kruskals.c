#include <stdio.h>
#define MAX 10
int parent[MAX];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
    }
}
int main()
{
    int n, i, v1, v2, mstcost = 0;
    printf("Enter the Number of Vertex :");
    scanf("%d", &n);
    int vertices[n], cost[n][n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    printf("Enter the Cost Adjacency Matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Vertex[%d][%d] :", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
            mst[i][j] = 0;
        }
    }
    int e = 0;
    int min = 999;
    while (e < n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }
        if (find(v1) != find(v2))
        {
            e++;
            mstcost += min;
            cost[v1][v2] = cost[v2][v1] = 999;
            printf("%d -%d ,COST=%d\n", v1,v2,min);

            uni(v1, v2);
            min = 999;
        }
    }
}