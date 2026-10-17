#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];  //静态数组存放栈中元素
    int top;    //栈顶指针
} SqStack;

//栈的初始化
void InitStack(SqStack &S){
    S.top = -1;    //初始化栈顶指针
}

//判断栈空
bool Empty(SqStack S){
    if(S.top == -1) return true;
    else return false;
}

//进栈操作
bool Push(SqStack &S,ElemType x){
    if(S.top == MaxSize -1) return false; //判断是否已经栈满
    S.top = S.top + 1;   //指针先加一
    S.data[S.top] = x;   //新元素入栈   // 可以写成 S.data[++S.top] = x
    return true;
}

//出栈操作
bool Pop(SqStack &S,ElemType &x){
    if(S.top == -1) return false;   //判断是否是栈空
    x = S.data[S.top];
    S.top = S.top - 1;   //也可以写成x = S.data[S.top--];
    return true;
}

//读取栈顶元素的操作
bool GetTop(SqStack S,ElemType &e){
    if(S.top == -1) return false;
    e = S.data[S.top];
    return true;
}