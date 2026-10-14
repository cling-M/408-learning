#include<stdio.h>
#define MaxSize 10
typedef int Elemtype;
// 定义一个静态数组
typedef struct {
    Elemtype data[MaxSize];
    int length;
}SqList;

//静态数组的初始化
void InitList(SqList &L){
    for(int i =0;i<=MaxSize;i++){
        L.data[i] = 0;
    }
    L.length = 0;
}

//静态数组的插入
bool ListInsert(SqList &L,int i,Elemtype e){
    if(i<1 || i>L.length+1){//判断i的取值是否是有效的
        return false;
    }
    if(L.length >= MaxSize){  //判断这个表是不是满了
        return false;
    }
    for(int l = L.length;l >= i;l--){
        L.data[l] = L.data[l-1];   //把第i个元素和之后的元素向后移
    }
    L.data[i-1] = e;    //在第i个位置插入e
    L.length++;       //表长加1
    return true; 
}  

//静态数组的删除
bool ListDelete(SqList &L,int i,Elemtype &e){
    if(i>L.length || i < 1){
        return false;
    }
    e = L.data[i-1];   //把第i哥元素传送给e
    for (int j = i;j < L.length;j++){
        L.data[i-1] = L.data[i];      //给第i个位置后的元素往前移
    }
    L.length--;     //长度减少1
    return true;
}
int main(){
    SqList L;
    InitList(L);
    ListInsert(L,1,1);
    return 0;
}