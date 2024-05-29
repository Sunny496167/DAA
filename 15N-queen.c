#include <stdbool.h>
#include <stdio.h>
#define N 8
int totalSolutions = 0;
bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
void solveNQUtil(int board[N][N], int col) {
    if (col >= N) {
        totalSolutions++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1);
            board[i][col] = 0;
        }
    }
}
int solveNQ() {
    int board[N][N] = {0};
    totalSolutions = 0;
    solveNQUtil(board, 0);
    return totalSolutions;
}
int main() {
    int solutions = solveNQ();
    printf("Total number of solutions: %d\n", solutions);
    return 0;
}
