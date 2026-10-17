#include <stdio.h>

#define MaxSize 10

typedef int ElemType;

typedef struct Node {
    ElemType data;
    int next;
} Node;

typedef struct Node SLinkList[MaxSize];  // 用SLinkList定义一个MaxSize长的Node型数组
