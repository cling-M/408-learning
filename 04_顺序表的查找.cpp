#include<stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;


//按位查找
ElemType GetElem(SqList L, int i){
    if(i<1 || i>L.length){
        return false;
    }
    return L.data[i-1];
}


//按值查找
int LocateElem(SqList L,ElemType e){
    // if (L.length == 0) return 0;  //不需要
    for(int i=0;i<L.length;i++){
        if(L.data[i] == e){ 
            return i+1;
        }
    }
    return 0;
}