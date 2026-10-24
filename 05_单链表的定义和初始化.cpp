#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct {
    ElemType data;   //每个节点存放一个数据
    struct LNode *next;    //指针指向下一个节点
}LNode,*LinkList;     //用LNode来强调这个是一个节点 用LinkList来强调这个是一个单链表

//初始化一个单链表（不带头节点）
bool InitList(LinkList &L){
    L = NULL;      //空表 暂时没有任何的节点
    return true;
}

//判断是否为空（不带头节点）
bool empty(LinkList L){
    return (L == NULL);
}

//带头节点初始化
bool InitList2(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));  //分配一个头节点
    if(L == NULL)
        return false;  //内存空间不足
    L->next = NULL;  //头节点之后暂时还没有分配节点
    return true;
}
//带头节点指针的判空
bool empty2(LinkList L){
    return(L->next ==NULL);
}
int main(){
    LinkList L;  //这个时候只是开辟了空间 还没有去创建一个节点
    InitList(L);
}