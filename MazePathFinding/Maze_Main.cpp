#include "Maze.cpp"

int main() {
    MazeType maze[N][N];
    PosType start, end;
    InitMaze(maze, start, end);
    PrintMaze(maze);
    MazePath(maze, start, end);
    system("pause");
    return 0;
}