#include<stdio.h>
#include<stdlib.h>
#include<tool.h>
typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    LNode * next;
}LNode,*LinkList;

//按位查找 带回第i个元素. 平均时间复杂度是O(n)
LNode * GetElem(LinkList L,int e){
    if(e<1) return NULL;
    int j = 0;
    LNode * p = L;
    while(p != NULL && j < e){
        p = p->next;
        j++;
    }
    return p;
}

//按值查找。 时间复杂度是O(n)
LNode *locateElem(LinkList L,ElemType e){
    LNode *p = L->next;

    //从第一个节点查数据为e的结点
    while(p != NULL && p->data != e){
        p=p->next;
    }
    return p;
}

//求表长。时间复杂度=O(n)
int length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}