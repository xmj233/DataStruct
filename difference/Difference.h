/* 静态链表的应用， 求(A-B)U(B-A)
1.创建包含集合A的静态链表。
2.遍历集合B。
3.若B中元素不在A中，将其加入静态链表
    否则将其从静态链表中删除。 */

#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include "../static linked list/StaticLinkedList.cpp"

void difference(SLinkList &space);

#endif