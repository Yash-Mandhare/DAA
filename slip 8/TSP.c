// Write Program to implement Traveling Salesman Problem using nearest neighbor
// algorithm

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 9999

int main() {
    int graph[MAX][MAX], visited[MAX] = {0};
    int n, i, j, current, nextCity, min, totalCost = 0;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    current = 0;  // start from city 0
    visited[current] = 1;

    printf("Tour: %d ", current);

    for (i = 1; i < n; i++) {
        min = INF;
        nextCity = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[current][j] && graph[current][j] < min) {
                min = graph[current][j];
                nextCity = j;
            }
        }

        if (nextCity != -1) {
            visited[nextCity] = 1;
            totalCost += graph[current][nextCity];
            current = nextCity;
            printf("-> %d ", current);
        }
    }

    // Return to starting city
    totalCost += graph[current][0];
    printf("-> 0\n");
    printf("Total Cost: %d\n", totalCost);

    return 0;
}


// Enter number of cities: 4
// Enter cost matrix:
// 0 10 15 20
// 10 0 35 25
// 15 35 0 30
// 20 25 30 0


// Tour: 0 -> 1 -> 3 -> 2 -> 0
// Total Cost: 80
