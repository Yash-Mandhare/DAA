// Write a program to find Minimum Cost Spanning Tree of a given undirected graph using
// Prims algorithm


#include <stdio.h>
#define INF 9999
#define V 5  // Number of vertices

int main() {
    int G[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[V] = {0};
    int edge_count = 0;
    int i, j;
    int min, x = 0, y = 0;

    selected[0] = 1; // Start from vertex 0

    printf("Edges in Minimum Spanning Tree:\n");

    while (edge_count < V - 1) {
        min = INF;

        for (i = 0; i < V; i++) {
            if (selected[i]) {
                for (j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = 1;
        edge_count++;
    }

    return 0;
}


// Edges in Minimum Spanning Tree:
// 0 - 1 : 2
// 1 - 2 : 3
// 1 - 4 : 5
// 0 - 3 : 6