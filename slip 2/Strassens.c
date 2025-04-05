// Write a program to implement Strassen’s Matrix multiplication

#include<stdio.h>

int main() {
    int z[2][2];
    int i, j;
    int m1, m2, m3, m4, m5, m6, m7;
    
    int x[2][2] = {{12, 34}, {22, 10}};
    int y[2][2] = {{3, 4}, {2, 1}};
    
    printf("The first matrix is:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++)
            printf("%d\t", x[i][j]);
        printf("\n");
    }
    
    printf("\nThe second matrix is:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++)
            printf("%d\t", y[i][j]);
        printf("\n");
    }

    // Strassen’s calculations
    m1 = (x[0][0] + x[1][1]) * (y[0][0] + y[1][1]);
    m2 = (x[1][0] + x[1][1]) * y[0][0];
    m3 = x[0][0] * (y[0][1] - y[1][1]);
    m4 = x[1][1] * (y[1][0] - y[0][0]);
    m5 = (x[0][0] + x[0][1]) * y[1][1];
    m6 = (x[1][0] - x[0][0]) * (y[0][0] + y[0][1]);
    m7 = (x[0][1] - x[1][1]) * (y[1][0] + y[1][1]);

    // Final matrix
    z[0][0] = m1 + m4 - m5 + m7;
    z[0][1] = m3 + m5;
    z[1][0] = m2 + m4;
    z[1][1] = m1 - m2 + m3 + m6;

    printf("\nProduct achieved using Strassen's algorithm:\n");
    for(i = 0; i < 2 ; i++) {
        for(j = 0; j < 2; j++)
            printf("%d\t", z[i][j]);
        printf("\n");
    }

    return 0;
}



// First Matrix:
// 12	34	
// 22	10	

// Second Matrix:
// 3	4	
// 2	1	

// Product using Strassen's Algorithm:
// 102	82	
// 86	98