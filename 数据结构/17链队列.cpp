#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//链队列的定义
typedef struct LinkNode {
    ElemType data; //数据域
    struct LinkNode *next; //
}LinkNode;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

//链队列的初始化
bool InitQueue(LinkQueue &Q){
    //初始时，头指针和尾指针都是指向头节点的
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    if(Q.front == NULL) return false;
    Q.front->next = NULL;
    return true;
}

//链队列的初始化 不带头节点版本
void InitQueue_NoHead(LinkQueue &Q){
    Q.front = Q.rear = NULL;
}

//链队列的判空
bool Empty(LinkQueue Q){
    if(Q.front == Q.rear) 
        return true;
    else
        return false;
}

//链队列的判空 不带头节点的版本
bool Empty_NoHead(LinkQueue Q){
    return (Q.front == NULL);
}

//链队列的入队，带头节点版本
bool EnQueue(LinkQueue &Q,ElemType e){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

//链队列的入队，不带头节点的版本
bool EnQueue_NoHead(LinkQueue &Q,ElemType e){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if(s == NULL) return false;
    s->data = e;
    s->next = NULL;
    if(Q.front == NULL){  //在空队列中插入第一个节点
        Q.front = s;
        Q.rear = s;
        return true;
    }
    else {
        Q.rear->next = s;
        Q.rear = s;
        return true;
    }  
}

//链队列的出队，带头节点的版本
bool DeQueue(LinkQueue &Q,ElemType &e){
    if(Q.front == Q.rear) return false;
    LinkNode *s = Q.front->next;
    e = s->data;
    Q.front->next = s->next;
    if(s == Q.rear){    //如果这个节点是这个队列的最后一个节点 需要特殊处理
        Q.front = Q.rear;
    }
    free(s);
    return true;
}

//链队列的出队，不带头节点的版本
bool DeQueue_NoHead(LinkQueue &Q,ElemType &e){
    if(Q.front == NULL) return false;
    LinkNode *s = Q.front;
    e = s->data;
    Q.front = s->next;
    if(Q.rear == s){
        Q.rear = NULL;
        Q.front = NULL;
    }
    free(s);
    return true;
}