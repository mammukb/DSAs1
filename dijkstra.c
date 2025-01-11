#include <stdio.h>
#include <limits.h>

int min(int dist[9], int visited[9])
{
    int min = INT_MAX, minindex;
    for (int i = 0; i < 9; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            minindex = i;
        }
    }
    return minindex;
}

void dijikstra(int graph[9][9], int n)
{
    int visited[9] = {0}, dist[9], u;

    for (int i = 0; i < 9; i++)
        dist[i] = INT_MAX;

    dist[n] = 0;

    for (int i = 0; i < 9 - 1; i++)
    {
        u = min(dist, visited);
        visited[u]=1;

        for (int v = 0; v < 9; v++)
        {
            if (!visited[v] && dist[u] !=INT_MAX && graph[u][v] && dist[u] + graph[u][v] <= dist[v])
            {
                dist[v] = dist[u] + graph[u][v];

            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        printf("Distance from %d - %d \n", i, dist[i]);
    }
}

int main()
{
    int n, i, j, k;
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijikstra(graph, 0);
}
