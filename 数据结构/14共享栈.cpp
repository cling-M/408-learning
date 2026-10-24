#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top0;   //0号栈的栈顶指针
    int top1;   //一号栈的栈顶指针
}ShStack;

//初始化共享栈
void InitShStack(ShStack &S){
    S.top0 = -1;        //初始化栈顶指针
    S.top1 = MaxSize;
}

//判断栈是不是满了
bool FULL(ShStack S){
    if(S.top0+1 == S.top1) return true;
    else return false; 
}