#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
//队列的静态定义
typedef struct {
    ElemType data[MaxSize];  //队列的数据域
    int front,rear;   //队头指针和队尾指针
}SqQueue;

//队列的初始化
void InitQueue(SqQueue &S){
    //初始化时，把队头队尾的指针都指向0
    S.front = S.rear=0;
}

//队列的判空操作
bool Empty(SqQueue S){
    if(S.front == S.rear) return true;
    else return false;
}

//队列的判满
bool Full(SqQueue S){
    //因为判空操作就是他们两个相等 避免重复 所以需要 舍弃一个存储单元 也就是浪费了一个存储单元
    //所以虽然定义上 队列已经满了 但是实际上 队列其实还有一个存储单元是空闲的
    if(S.rear +1 == S.front) return true;
    else return false;
}

//队列的入队
bool EnQueue(SqQueue &S,ElemType e){
    if(Full(S)){
        return false;
    }
    S.data[S.rear] = e;
    S.rear = (S.rear + 1)%MaxSize;  //用膜运算讲将存储空间逻辑上变成了环状
    return true;
}

//队列的出队
bool DeQueue(SqQueue &S,ElemType &e){
    if(Empty(S)){
        return false;
    }
    e = S.data[S.front];
    S.front = (S.front - 1)%MaxSize;//队头指针后移
    return true;
}

//队列的取元素操作
bool GetHead(SqQueue S,ElemType &e){
    if(Empty(S)){
        return false;
    }
    e = S.data[S.front];
    return true;
}

//拒绝牺牲那一个存储空间的方法：
    //1，查找队列中元素的个数 更改判满条件 用返回的元素e和MaxSize比较
    int Size(SqQueue S){
        int e;
        e = (S.front + MaxSize - S.rear)%MaxSize;
        return e;
    }

    //2，在初始化定义队列的时候 在最后加入一个int变量 size 
    //当有元素进入的时候size++ 当有元素出队的时候 size--
    //再用size和MaxSize比较

    //3，在初始化定义列队的时候，在最后加入一个int变量type
    //当上一次进行的操作是1的时候代表有元素进入
    //当上一次进行的操作是0的时候代表有元素被删除
    //只有有元素进入的时候 列队才可能满
    //只有有元素出队的时候 列队才可能空
