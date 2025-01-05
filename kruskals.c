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
    int vertices[num_vertex], cost[num_vertex][num_vertex], mst[num_vertex][num_vertex];
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
            mst[i][j] = 0;
        }
    }
    int e = 0;
    int min = 999;
    while (e < num_vertex - 1)
    {
        for (int i = 0; i < num_vertex; i++)
        {
            for (int j = 0; j < num_vertex; j++)
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
            mst[v1][v2] = mst[v2][v1] = min;
            cost[v1][v2] = cost[v2][v1] = 999;
            uni(v1, v2);
            min = 999;
        }
    }
    printf("MST Contains:\n");
    for (int i = 0; i < num_vertex; i++)
    {
        for (int j = i; j < num_vertex; j++)
        {
            if(mst[i][j]!=0){
            printf("%d -%d ,COST=%d\n", i,j,mst[i][j]);
            }
        }
    }
    
    printf("The MST adj matrix");
    for (int i = 0; i < num_vertex; i++)
    {
        printf("\n");
        for (int j = 0; j < num_vertex; j++)
        {
            printf("%d ", mst[i][j]);
        }
    }
}