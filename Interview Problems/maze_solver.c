#include <stdio.h>
#include <conio.h>

#define N 4

// Function to print the solution path matrix
void printSolution(int sol[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

// Check if x, y is a valid move inside the maze and not blocked
int isSafe(int maze[N][N], int x, int y) {
    // If x and y are within bounds and the cell is open (1)
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// A recursive utility function to solve Maze problem
int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // Base case: If (x, y) is the destination, we are done
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return 1;
    }

    // Check if current cell is a valid move
    if (isSafe(maze, x, y) == 1) {
        // Mark current cell as part of solution path
        sol[x][y] = 1;

        // 1. Move Forward (Right)
        if (solveMazeUtil(maze, x, y + 1, sol))
            return 1;

        // 2. If moving right doesn't work, Move Down
        if (solveMazeUtil(maze, x + 1, y, sol))
            return 1;

        // 3. If neither works, BACKTRACK: unmark this cell
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

int main() {
    // 1 represents open paths, 0 represents walls
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int sol[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    clrscr();

    printf("Initial Maze (1 = path, 0 = wall):\n");
    printSolution(maze);

    if (solveMazeUtil(maze, 0, 0, sol) == 0) {
        printf("\nSolution doesn't exist!\n");
    } else {
        printf("\nSolution Path (1 = correct path):\n");
        printSolution(sol);
    }

    getch();
    return 0;
}
