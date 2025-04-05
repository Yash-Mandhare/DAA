// Write a program to implement BFS (Breadth First Search) and determine the time
// complexity for the same.

#include <stdio.h>

int graph[10][10], visited[10], n;

void bfs(int start) {
    int queue[10], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);
    return 0;
}


// Enter number of vertices: 4
// Enter adjacency matrix:
// 0 1 1 0
// 1 0 0 1
// 1 0 0 1
// 0 1 1 0
// Enter starting vertex: 0

// BFS Traversal: 0 1 2 3
