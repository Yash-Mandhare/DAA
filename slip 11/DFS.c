// Write a programs to implement DFS (Depth First Search) and determine the time
// complexity for the same.

#include <stdio.h>

int graph[10][10], visited[10], n;

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}


// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 1 0
// 1 0 0 1
// 1 0 0 1
// 0 1 1 0
// Enter starting vertex: 0


// DFS traversal: 0 1 3 2
