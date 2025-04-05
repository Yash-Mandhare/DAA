// Write a program to implement Graph Coloring Algorithm


#include <stdio.h>
#define V 4

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int color[V];

int isSafe(int v, int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return 0;
    return 1;
}

int solve(int v, int m) {
    if (v == V) return 1;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (solve(v + 1, m)) return 1;
            color[v] = 0;
        }
    }
    return 0;
}

int main() {
    int m = 3;
    if (solve(0, m)) {
        for (int i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    } else {
        printf("No solution.\n");
    }
    return 0;
}


// Vertex 0 -> Color 1
// Vertex 1 -> Color 2
// Vertex 2 -> Color 3
// Vertex 3 -> Color 2