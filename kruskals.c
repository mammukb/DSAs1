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
    int num_vertex, i, v1, v2, mstcost = 0;
    printf("Enter the Number of Vertex :");
    scanf("%d", &num_vertex);
    int vertices[num_vertex], cost[num_vertex][num_vertex], edge1[num_vertex], edge2[num_vertex];
    // printf("Enter the Vertices :\n");
    for (int i = 0; i < num_vertex; i++)
    {
        parent[i] = i;
    }
    printf("Enter the Cost Adjacency Matrix :\n");
    for (int i = 0; i < num_vertex; i++)
    {
        for (int j = 0; j < num_vertex; j++)
        {
            printf("Vertex[%d][%d] :", i, j);
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    for (int i = 0, min = 999, e = 0; i < num_vertex; i++)
    {
        for (int j = 0; j < num_vertex; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                mstcost += min;
                v1 = i;
                v2 = j;
                if (find(v1) != find(v2))
                {
                    edge1[e] = v1;
                    edge2[e] = v2;
                    e++;
                    uni(v1, v2);
                }
            }
        }
    }

    printf("The MST contains Edges");
    for (int i = 0; i < num_vertex; i++)
    {
        printf("%d -- %d\n", edge1[i], edge2[i]);
    }
}