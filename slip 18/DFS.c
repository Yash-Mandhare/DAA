// Write a program to find out live node, E node and dead node from a given graph.

#include <stdio.h>
#define MAX 10

int graph[MAX][MAX], visited[MAX];
int n; // Number of nodes

void DFS(int node) {
    printf("E-Node: %d\n", node); // Currently exploring this node
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            printf("Live Node: %d\n", i);
            DFS(i);
        }
    }

    printf("Dead Node: %d\n", node); // Finished exploring
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("\nStarting DFS from node 0...\n");
    DFS(0);

    return 0;
}


// Enter number of nodes: 4
// Enter adjacency matrix:
// 0 1 1 0
// 1 0 0 1
// 1 0 0 1
// 0 1 1 0


// Starting DFS from node 0...
// E-Node: 0
// Live Node: 1
// E-Node: 1
// Live Node: 3
// E-Node: 3
// Live Node: 2
// E-Node: 2
// Dead Node: 2
// Dead Node: 3
// Dead Node: 1
// Dead Node: 0