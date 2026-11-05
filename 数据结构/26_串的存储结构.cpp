#include<stdio.h>
#define MaxSize 255
//静态存储
typedef struct {
    char ch[MaxSize]; //每个分量存储一个字符
    int length; //串的实际长度
}SString;

//动态存储
typedef struct {
    char *ch;  //按照串的长度来分配存储区，ch 指向的是串的基地址
    int length;  //串的长度
}HSting;
