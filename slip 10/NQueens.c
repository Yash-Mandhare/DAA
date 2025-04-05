// Write a program to solve 4 Queens Problem using Backtracking

#include <stdio.h>
#include <math.h>

int board[20], count = 0;

int isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution(int n) {
    printf("\nSolution %d:\n", ++count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void solveNQueens(int row, int n) {
    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            if (row == n)
                printSolution(n);
            else
                solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    solveNQueens(1, n);

    if (count == 0)
        printf("No solution found for %d queens.\n", n);

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
