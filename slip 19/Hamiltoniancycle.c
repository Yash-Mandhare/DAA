// Write a program to determine if a given graph is a Hamiltonian cycle or not.

#include <stdio.h>
#include <stdbool.h>

#define V 4
int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};
int path[V];

bool isSafe(int v, int pos) {
    if (graph[path[pos-1]][v] == 0) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}

bool solve(int pos) {
    if (pos == V) return graph[path[pos-1]][path[0]] == 1;
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (solve(pos + 1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < V; i++) path[i] = -1;
    path[0] = 0;

    if (solve(1)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < V; i++) printf("%d ", path[i]);
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle\n");
    }
    return 0;
}


// Hamiltonian Cycle: 0 1 2 3 0