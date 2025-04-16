// Write a program for finding Topological sorting for Directed Acyclic Graph (DAG)

#include <stdio.h>
#define MAX 100

int main() {
    int n, i, j, u, v, indegree[MAX] = {0}, graph[MAX][MAX] = {0}, queue[MAX], front = 0, rear = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j])
                indegree[j]++;
        }

    // Enqueue nodes with 0 indegree
    for (i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[++rear] = i;

    printf("Topological Order:\n");
    while (front <= rear) {
        u = queue[front++];
        printf("%d ", u);

        for (v = 0; v < n; v++) {
            if (graph[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[++rear] = v;
            }
        }
    }

    return 0;
}


// Enter number of vertices: 6
// Enter adjacency matrix:
// 0 1 1 0 0 0
// 0 0 0 1 1 0
// 0 0 0 0 1 0
// 0 0 0 0 0 1
// 0 0 0 0 0 1
// 0 0 0 0 0 0

// Topological Order:
// 0 1 2 3 4 5