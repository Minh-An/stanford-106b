/*
 * CS 106B/X Maze Solver
 *
 * This file contains our escapeMaze function for finding a path
 * out of a maze using recursive backtracking.
 */

#include "Maze.h"

/*
 * Tries to find a way to escape from the given maze, starting
 * from the given row/column location.
 * Returns true if it finds a way out, or false if not.
 */
bool escapeMaze(Maze& maze, int row, int col) {
    if (!maze.inBounds(row, col)) {
        // base case 1: escaped the maze
        return true;
    } else if (!maze.isOpen(row, col)) {
        // base case 2: wall/stuck
        return false;
    } else {
        // choose
        maze.mark(row, col);

        // explore each of 4 choices
        bool result = escapeMaze(maze, row - 1, col)   // up
                || escapeMaze(maze, row + 1, col)      // down
                || escapeMaze(maze, row, col - 1)      // left
                || escapeMaze(maze, row, col + 1);     // right

        // un-choose
        if (!result) {
            maze.taint(row, col);
        }

        return result;
    }
}
