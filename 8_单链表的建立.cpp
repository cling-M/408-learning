#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode * next;
}LNode,*LinkList;

bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL) return false;
    L->next == NULL;
    return true;
}

//尾插法建立单链表
bool List_TailInsert(LinkList &L){
    int x;     //设置插入的值的类型
    L = (LNode *)malloc(sizeof(LNode));    //创建一个头节点
    LNode * s,* r =L;   //r为表尾指针
    scanf("%d",&x);
    while(x != 9999){
        s = (LNode *)malloc(sizeof(LNode));
        if(s == NULL) return false;
        s->data = x;
        r->next = s;     //给节点连接起来
        r = s;             //等待下一次连接
        scanf("%d",&x);
    }
    r->next = NULL;
    return true;
}


//头插法建立单链表。可以用于单链表的逆置
bool List_HeadInsert(LinkList &L){
    InitList(L);
    int x;

    scanf("%d",&x);
    while(x != 99999){
        LNode * s = (LNode*)malloc(sizeof(LNode));
        if(s == NULL) return false;
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return true;
}