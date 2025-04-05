// Write a program for the Implementation of Dijkstra’s algorithm to find shortest path to
// other vertices

#include <stdio.h>
#define INF 9999
#define MAX 10

int main() {
    int graph[MAX][MAX], dist[MAX], visited[MAX];
    int n, i, j, count, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(count = 0; count < n - 1; count++) {
        min = INF;
        for(i = 0; i < n; i++)
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for(i = 0; i < n; i++)
            if(!visited[i] && graph[u][i] && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }

    printf("Vertex\tDistance from Source\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);

    return 0;
}


// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 4 0
// 0 0 4 2
// 0 0 0 3
// 0 0 0 0
// Enter source vertex: 0

// Vertex  Distance from Source
// 0       0
// 1       1
// 2       4
// 3       3

