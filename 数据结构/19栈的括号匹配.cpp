#include<stdio.h>
#define MaxSize 10

typedef struct 
{
    char data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S);

bool StackEmpty(SqStack S);

bool Push(SqStack &S,char x);

bool Pop(SqStack &S,char x);

//最后出现的左括号优先被右括号匹配 符合栈的结构
bool bracaketcheck(char str[],int length){
    SqStack S;
    InitStack(S);  //初始化一个栈
    for(int i = 0;i < length;i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){ //判断是不是入栈操作
            Push(S,str[i]); 
        } else {
            if(StackEmpty(S)){  //判断栈是不是空的
                return false;
            }
            char topElem;
            Pop(S,topElem);  //进行出栈操作
            if(str[i] == '(' && topElem != ')')
                return false;
            if(str[i] == '{' && topElem != '}')
                return false;
            if(str[i] == '[' && topElem != ']')
                return false;
        }
    }
    return StackEmpty(S);  //检索完成之后 栈空表示任务完成
}