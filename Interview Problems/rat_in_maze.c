#include <stdio.h>
#include <conio.h>

#define N 4

// Function to print the final path matrix
void printSolution(int sol[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

// Function to check if x, y is valid and not a wall
int isSafe(int maze[N][N], int x, int y) {
    // Return 1 if x, y are within array bounds and cell is open (1)
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        return 1;
    }
    return 0;
}

// Recursive backtracking function for the rat
int solveMaze(int maze[N][N], int x, int y, int sol[N][N]) {
    // Base case: Rat reached the destination (bottom-right)
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return 1;
    }

    // Check if rat can step on this cell
    if (isSafe(maze, x, y) == 1) {
        // Mark as part of the path
        sol[x][y] = 1;

        // 1. Try moving Right
        if (solveMaze(maze, x, y + 1, sol) == 1) {
            return 1;
        }

        // 2. Try moving Down
        if (solveMaze(maze, x + 1, y, sol) == 1) {
            return 1;
        }

        // 3. BACKTRACK: If both directions are dead ends, unmark and go back
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

int main() {
    // 1 = safe path, 0 = blocked wall
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    // Solution matrix initially filled with 0
    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    clrscr();

    printf("Rat in a Maze (1 = open, 0 = wall):\n");
    printSolution(maze);

    // Start from top-left (0,0)
    if (solveMaze(maze, 0, 0, sol) == 0) {
        printf("\nThe Rat cannot reach the destination!\n");
    } else {
        printf("\nSolution Path (1 = rat's path):\n");
        printSolution(sol);
    }

    getch();
    return 0;
}
