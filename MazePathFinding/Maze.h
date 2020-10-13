#ifndef MAZE_H
#define MAZE_H

#include <time.h>
#include <Windows.h>
#include "../Status.h"

#define N 15
#define X 4

typedef enum {
    Wall,
    Obstacle,
    Way,
    DeadLock,
    East,South,West,North
}MazeNode;

typedef struct {
    int x;
    int y;
}PosType;

typedef struct {
    int ord;
    PosType seat;
    int di;
}SElemType;
#include "../sequence stack/SequenceStack.cpp"

typedef int MazeType;

Status MazePath(MazeType maze[][N], PosType start, PosType end);

void InitMaze(MazeType maze[][N], PosType &start, PosType &end);

void PrintMaze(MazeType maze[][N]);

void ShowMaze(MazeType maze[][N]);

Status Pass(MazeType maze[][N], PosType seat);

PosType NextPos(PosType seat, int di);

void FootPrint(MazeType maze[][N], PosType seat);

void MarkPrint(MazeType maze[][N], PosType seat);

void SetSElemType(SElemType &S, int ord, PosType seat, int di);

Status equalPos(PosType seat1, PosType seat2);

Status IsCross(PosType seat);



#endif