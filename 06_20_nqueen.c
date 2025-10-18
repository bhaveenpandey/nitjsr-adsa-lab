#include <stdio.h>
#include <stdlib.h>
#define N 8

int board[N];
int solutionFound = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    return 1;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%s ", (board[i] == j) ? "Q" : ".");
        printf("\n");
    }
}

void solveNQueens(int row) {
    if (solutionFound) return;  // Stop after first solution
    if (row == N) {
        printSolution();
        solutionFound = 1;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1);
        }
    }
}

int main() {
    solveNQueens(0);
    return 0;
}
