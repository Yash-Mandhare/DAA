// Write a program to solve 4 Queens Problem using Backtracking

#include <stdio.h>
#include <math.h>

int board[20], n, count = 0;

int isSafe(int r, int c) {
    for (int i = 1; i < r; i++)
        if (board[i] == c || abs(board[i] - c) == abs(i - r))
            return 0;
    return 1;
}

void solve(int r) {
    if (r > n) {
        printf("\nSolution %d:\n", ++count);
        for (int i = 1; i <= n; i++, printf("\n"))
            for (int j = 1; j <= n; j++)
                printf(board[i] == j ? " Q " : " . ");
        return;
    }
    for (int c = 1; c <= n; c++)
        if (isSafe(r, c)) {
            board[r] = c;
            solve(r + 1);
        }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);
    solve(1);
    if (!count) printf("No solution found.\n");
    return 0;
}

// Enter the number of queens: 4

// Solution 1:
//  .  Q  .  . 
//  .  .  .  Q 
//  Q  .  .  . 
//  .  .  Q  . 

// Solution 2:
//  .  .  Q  . 
//  Q  .  .  . 
//  .  .  .  Q 
//  .  Q  .  . 
