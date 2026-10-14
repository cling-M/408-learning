#pragma once

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *Linklist;

// 函数声明
bool ListInsert(Linklist &L, int i, ElemType e);
bool ListDelete(Linklist &L, int i, ElemType &e);
LNode *GetElem(Linklist L, int i);
bool InsertNextNode(LNode *L, ElemType e);