#include<stdio.h>
#include<stdlib.h>
#define InitSize 10 //默认的最大长度

typedef struct{
    int *data;   //指示动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int length;  //顺序表的当前长度
}SeqList;

//顺序表的初始化
void InitList(SeqList &L){
    //用malloc函数申请一片连续的存储空间
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length =0;
    L.MaxSize=InitSize;
}

//增加顺序表的长度
void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i=0;i<L.length;i++){
        L.data[i] = p[i];    //将数据复制到新的区域
    }
    L.MaxSize = L.MaxSize + len;    //顺序表最大长度增加len
    free(p);    //释放原来的内存空间
}

