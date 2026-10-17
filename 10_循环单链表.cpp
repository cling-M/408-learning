#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode * next;
}LNode,*LinkList;

//初始化一个单链表
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL) return false;
    L->next = L;
    return true;
}

//判断循环单链表是不是空
bool Empty(LinkList L){
    if(L->next == L) return true;
    return false;
}

//判断该节点是不是列表的最后一个节点 
bool isTail(LinkList L,LNode *p){
    if(p->next == L) return true;
    return false;
}

//循环双链表大同小异 再次不再进行展开