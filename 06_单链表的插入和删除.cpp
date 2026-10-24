#include<stdio.h>
#include<stdlib.h>
#include<tool.h>
#define MaxSize 10
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*Linklist;

//单链表的插入操作（按照位序插入，带头节点）平均时间复杂度是O(n)
bool ListInsert(Linklist &L,int i,ElemType e){
    if(i<1) return false;
    LNode *p;     //指针p指向的是当前的结点
    int j = 0;    //当前的节点的位置
    p = L;       //p指向头节点，头节点是第0个节点（不存数据）
    while(p != NULL && j < i-1){
        p = p->next;    //让p指针依次进行扫描
        j++;
    }
    if(p==NULL) return false;  //i的值 不合法
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//单链表的插入操作（按位序插入，不带头节点）平均时间复杂度是O(n)
bool ListInsert2(Linklist &L,int i,ElemType e){
    if(i<1) return false;
    if(i==1){  //因为是没有头节点的单链表，所以当i=1时，直接在链表的头部插入
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;     //指针p指向的是当前的结点
    int j = 1;    //当前的节点的位置
    p = L;       //p指向头节点
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    //InsertNextNode(p,e)
    if(p==NULL) return false;  //i的值 不合法
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//单链表的后插操作  时间复杂度是O(1)
bool InsertNextNode(LNode *L,ElemType e){
    if(L == NULL) return false;
    LNode * s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL) return false;  //内存不足
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}

//单链表的前插操作（利用后插操作 然后给数值交换位置）//时间复杂度是O(1)
bool InsertPriorNode(LNode * L,ElemType e){
    if(L == NULL) return false;
    LNode * s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL) return false;
    s->next = L->next;
    L->next = s;
    s->data = L->data;
    L->data = e;
    return true;
}

//单链表的删除操作
bool ListDelete(Linklist &L,int i,ElemType &e){
    if(i < 1) return false;
    LNode *p;
    p = L;
    int j =0;
    while(p != NULL && j < i-1){
        p = p->next;
        j++;
    }
    if(p == NULL) return false;
    if(p->next == NULL) return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//删除指定节点p  时间复杂度是O(1) 有bug 只能当p不是最后一个节点的时候使用 
bool DeleteNode(LNode *p){
    if(p == NULL) return false;
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}