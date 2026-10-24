#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
    ElemType data;    //数据域
    struct LinkNode *next;    //指针域
}LiStack;

//初始化栈（S作为不存放元素的头结点）
void InitStack(LiStack &S){
    S.next = nullptr;
}

//判断栈空
bool Empty(LiStack S){
    return S.next == nullptr;
}

//判断栈满（链栈没有固定容量，此处检查当前是否还能分配结点）
bool Full(){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    if(p == nullptr) return true;
    free(p);
    return false;
}

//进栈：新结点插入头结点之后
bool Push(LiStack &S,ElemType x){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    if(p == nullptr) return false;
    p->data = x;
    p->next = S.next;
    S.next = p;
    return true;
}

//出栈：删除栈顶结点
bool Pop(LiStack &S,ElemType &x){
    if(Empty(S)) return false;
    LinkNode *p = S.next;
    x = p->data;
    S.next = p->next;
    free(p);
    return true;
}

//读取栈顶元素
bool GetTop(LiStack S,ElemType &x){
    if(Empty(S)) return false;
    x = S.next->data;
    return true;
}

//按位置读取元素，位置从栈顶开始，栈顶为第1个
bool GetElem(LiStack S,int position,ElemType &x){
    if(position < 1) return false;
    LinkNode *p = S.next;
    for(int i = 1; i < position && p != nullptr; i++){
        p = p->next;
    }
    if(p == nullptr) return false;
    x = p->data;
    return true;
}

//按位置修改元素，位置从栈顶开始，栈顶为第1个
bool Modify(LiStack &S,int position,ElemType x){
    if(position < 1) return false;
    LinkNode *p = S.next;
    for(int i = 1; i < position && p != nullptr; i++){
        p = p->next;
    }
    if(p == nullptr) return false;
    p->data = x;
    return true;
}

//销毁栈中的所有结点
void DestroyStack(LiStack &S){
    LinkNode *p = S.next;
    while(p != nullptr){
        LinkNode *q = p;
        p = p->next;
        free(q);
    }
    S.next = nullptr;
}
