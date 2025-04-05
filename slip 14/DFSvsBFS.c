// Write a program to implement DFS and BFS. Compare the time complexity

#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0, i;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
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

    printf("\nDFS traversal: ");
    for (i = 0; i < n; i++)
        visited[i] = 0;
    DFS(start);

    printf("\nBFS traversal: ");
    BFS(start);

    printf("\n\nTime Complexity:\n");
    printf("DFS: O(V + E)\n");
    printf("BFS: O(V + E)\n");

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
// BFS traversal: 0 1 2 3

// Time Complexity:
// DFS: O(V + E)
// BFS: O(V + E)
