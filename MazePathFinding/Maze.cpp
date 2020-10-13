#ifndef MAZE_CPP
#define MAZE_CPP

#include "Maze.h"

Status MazePath(MazeType maze[][N], PosType start, PosType end) {
    SqStack S;
    int curstep;
    PosType curpos;
    curstep = 1;
    curpos = start;
    InitStack(S);
    SElemType e;
    do {
        if ( Pass(maze, curpos) ) {
            FootPrint(maze, curpos);
            ShowMaze(maze);
            SetSElemType(e, curstep, curpos, East);
            Push(S, e);
            if ( equalPos(curpos, end) )
                return TRUE;
            curpos = NextPos(curpos, East);
            curstep ++;
        }
        else {
            if ( !StackEmpty(S) ) {
                Pop(S, e);
                while ( e.di==North && !StackEmpty(S) ) {
                    MarkPrint(maze, e.seat);
                    ShowMaze(maze);
                    Pop(S, e);
                }
                if ( e.di<North ) {
                    maze[e.seat.x][e.seat.y] = ++e.di;
                    ShowMaze(maze);
                    Push(S, e);
                    curpos = NextPos(e.seat, e.di);
                }
            }
        }

    }while(!StackEmpty(S));

    return FALSE;
    
}

void InitMaze(MazeType maze[][N], PosType &start, PosType &end) {
    int i, j, r;
    srand((unsigned)time(NULL));

    for ( i=0; i<N; i++ ) {
        for ( j=0; j<N; j++ ) {
            if ( i==0||j==0||i==N-1||j==N-1 )
                maze[i][j] = Wall;
            else {
                r = rand()%X;
                if ( r==0 )
                    maze[i][j]=Obstacle;
                else 
                    maze[i][j]=Way;
            }
        }
    }
    start.x = 1;
    start.y = 0;
    end.x = N-2;
    end.y = N-1;

    maze[1][0] = maze[N-2][N-1] = Way;
    maze[1][1] = maze[N-2][N-2] = Way;
}

void PrintMaze(MazeType maze[][N]) {
    int i, j;
    for ( i=0; i<N; i++ ) {
        for ( j=0; j<N; j++ ) {
            if ( maze[i][j]==Wall ) 
                printf("▇");//▇
            else if ( maze[i][j]==Obstacle ) 
                printf("▇");
            else if ( maze[i][j]==DeadLock ) 
                printf("★");
            else if ( maze[i][j]==Way )
                printf("　");
            else if ( maze[i][j]==East ) 
                printf("→");//→
            else if ( maze[i][j]==West )
                printf("←");
            else if ( maze[i][j]==South )
                printf("↓");
            else if ( maze[i][j]==North )
                printf("↑");
        }
        printf("\n");
    }
}

void ShowMaze(MazeType maze[][N]) {
    Sleep(500);
    system("cls");
    PrintMaze(maze);
}

Status Pass(MazeType maze[][N], PosType seat) {
    if ( !IsCross(seat)&&maze[seat.x][seat.y]==Way )
        return TRUE;
    else 
        return FALSE;
}

PosType NextPos(PosType seat, int di) {
    PosType p = seat;
    switch(di) {
        case East: 
            p.y++;
            break;
        case South:
            p.x++;
            break;
        case West:
            p.y--;
            break;
        case North:
            p.x--;
            break;
    }
    return p;
}

void FootPrint(MazeType maze[][N], PosType seat) {
    maze[seat.x][seat.y] = East;
}

void MarkPrint(MazeType maze[][N], PosType seat ) {
    maze[seat.x][seat.y] = DeadLock;
}

void SetSElemType(SElemType &S, int ord, PosType seat, int di) {
    S.ord = ord;
    S.seat = seat;
    S.di = di;
}

Status equalPos(PosType seat1, PosType seat2) {
    if ( seat1.x==seat2.x && seat1.y==seat2.y )
        return TRUE;
    else 
        return FALSE;
}

Status IsCross(PosType seat) {
    if ( seat.x<0||seat.y<0||seat.x>N-1||seat.y>N-1 )
        return TRUE;
    else 
        return FALSE;
}

#endif