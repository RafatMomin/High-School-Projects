#include <stdio.h>

#define ROWS 5
#define COLS 5

//@ author Rafat Momin

// Directions for moving up, down, left, and right
int rowDirections[] = {-1, 1, 0, 0};
int colDirections[] = {0, 0, -1, 1};

// Function to print the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Recursive function to solve the maze using DFS
int solveMaze(char maze[ROWS][COLS], int x, int y) {
    // Check if the current position is out of bounds or a wall or already visited
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == '#' || maze[x][y] == '+') {
        return 0;
    }

    // Check if the current position is the end of the maze
    if (maze[x][y] == 'E') {
        return 1;
    }

    // Mark the current position as part of the path
    maze[x][y] = '+';

    // Recursively explore the neighboring positions
    for (int i = 0; i < 4; i++) {
        int newX = x + rowDirections[i];
        int newY = y + colDirections[i];

        if (solveMaze(maze, newX, newY)) {
            return 1;
        }
    }

    // Unmark the current position (backtrack)
    maze[x][y] = ' ';

    return 0;
}

int main() {
    // Define the maze (S: Start, E: End, #: Wall, ' ': Path)
    char maze[ROWS][COLS] = {
            {'S', ' ', '#', ' ', ' '},
            {'#', ' ', '#', ' ', '#'},
            {'#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' '},
            {'#', '#', '#', '#', 'E'}
    };

    printf("Original Maze:\n");
    printMaze(maze);

    if (solveMaze(maze, 0, 0)) {
        printf("Maze Solved:\n");
        printMaze(maze);
    } else {
        printf("No solution found for the maze.\n");
    }

    return 0;
}
