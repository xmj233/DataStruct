/* 离散事件模拟
    银行业务模拟
    2020.2.1
    周六    */
#ifndef BANKSIMULATION_H
#define BANKSIMULATION_H

#include <stdio.h>
#include <time.h>

typedef enum {
    Arrive, Leave_1, Leave_2, Leave_3, Leave_4
}EventType;

typedef struct {
    int OccurTime;
    EventType NType;
}Event, ElemType;
#include "../singly linked table/SinglyLinkedList.cpp"

typedef LinkList EventList;

typedef struct {
    int ArrivalTime;
    int Dukkion;
}QElemType;
#include "../LinkQueue/LinkQueue.cpp"

EventList   ev;     //事件表
Event       en;     //事件
LinkQueue   q[5];   //4个客户队列
QElemType   customer;   //客户信息
int TotalTime, CustomNum;
int CloseTime=480;      //关门时间，银行每天开门8个小时

//银行开门，初始化操作
void OpenForDay();

//处理客户到达事件
void CustomerArrived();

//处理客户离开事件
void CustomerDeParture();

//根据事件a的发生时刻<,=,>事件b的发生时刻分别返回-1或0或1
int cmp(Event a, Event b);

//生成随机数，当前客户办理业务所需时间和下一客户到达时间
void Random(int &durtime, int &intertime);

//将事件插入到事件表的正确位置
Status OrderInsert(EventList ev, Event en, int(cmp)(Event, Event));


#endif