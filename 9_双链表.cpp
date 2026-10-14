#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; 
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next; 
}DNode,*DLinkList;

//双链表的初始化
bool InitDLinkList(DLinkList &L){
    L = (DNode *)malloc(sizeof(DNode));
    if(L == NULL) return false;
    L->next = NULL;
    L->prior = NULL;
    return true; 
}

//双链表的判空
bool Empty(DLinkList L){
    if(L->next == NULL) return true;
    else {
        return false;
    }
}

//在p节点之后插入s节点
bool InsertNextDNode(DNode* p,DNode* s){
    if(p == nullptr || s == nullptr) return false;
    s->next = p->next;
    if(p->next != NULL) s = p->next->prior;  //注意 p 可能没有后继节点
    s->prior = p;
    p->next =s;
    return true;
}
//删除p节点的后继节点
bool DeleteDNode(DNode *p){
    if(p == NULL) return false;
    DNode *s = p->next;
    if(s == NULL) return false;  //p 有没有后继节点
    p->next = s->next;
    if(s->next != NULL) s->next->prior = p;  //看p节点的后继节点还有没有后继节点
    free(s);  //释放节点空间
    return true;
}

//销毁整个链表
bool DestoryDlist(DLinkList &L){
    while(L->next != NULL){
        DeleteDNode(L);
    }
    free(L);  //释放头节点
    L == NULL;  //头指针指向NULL
}