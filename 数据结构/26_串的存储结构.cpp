#include<stdio.h>
#include<stdlib.h>
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

/*
在串的顺序存储中 有三种方案 其中写的是方案1 单独设置一个变量是 length 来进行记录当前的长度

方案2 是把 ch[0] 当做成为 length 优点是字符的位序和数组下标相同 缺点是一个字节是一个比特位是八个字节 那么它最大的值就是255 不可以超过255

方案3 是把字符串结束的最后加了一个判断字符 \0 （ASCII码的值也是0）每次想要知道现在有几个元素的话就需要从头开始遍历 如果要经常访问现在有多少个元素那么这个方案是不可取的

方案4（最优） 给ch[0]废弃不用 然后在末尾添加一个 length 变量来记录现在串的长度
*/

// 静态串的求子串操作
bool SubString(SString &Sub, SString S, int pos,int len){
    // 子串是否越界
    if(pos+len > S.length) return false;
    for(int i = pos; i<pos + len;i++)
        Sub.ch[i-pos] == S.ch[i];
    Sub.length = len;
}

// 两个字符串的比较
int StrCompare(SString S, SString T){
    for(int i =1;i<S.length && i<T.length;i++){
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

// 子串的定位操作
int Index(SString S,SString T){
    int i =1, n = S.length, m = T.length;
    SString Sub;  //用于暂存子串
    while(i < n-m +1){
        SubString(Sub,S,i,m);
        if(StrCompare(Sub,T) != 0) ++i;
        else return i;  //返回子串在主串中的位置
    }
    return 0;  //S和T不想等
}

int main(){
    HSting S;
    S.ch = (char *)malloc(MaxSize * sizeof(char));
    //malloc 申请的被存放在堆区 所以用完需要手动 malloc 回收 系统不会自动进行回收
    //静态存储是由系统进行自动回收的
    S.length = 0;
}

typedef struct StringNode{
    char ch; //每个节点一个字符  //1B
    struct StringNode * next;  //4B
    // 存储密度低 用了5个字节 存储了1个字节的元素 
    // 可以让 char ch; 变成 char ch[4]等来让一个节点存储多个字符使得存储密度升高
}StringNode, * String;


