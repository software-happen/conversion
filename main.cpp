#include <iostream>
#include <stdio.h>
/*malloc函数头文件*/
#include "stdlib.h"
#include "Stack.h"

using namespace std;

int main()
{
    Stack s;
    printf("输入一个十进制数：");
    void conversion(Stack &s);
    conversion(s);
    return 0;
}

// 构造一个空栈
void InitStack(Stack &s)
{
    s.elem = (int *)malloc(initsize * sizeof(int)); // 初始分配地址
    s.base = 0; // base指针指向栈底
    s.top = 0;// 初始化top指针指向栈顶元素的下一个位置
    s.stacksize = 10;
}


// 插入n为新的栈顶元素
void push(Stack &s, int n)
{
    if(s.top - s.base <= initsize) // 不满
    {
        /*方括号内是s.top不是top*/
        s.elem[s.top] = n; // 插入n
        s.top += 1 ; // top指针+1
    }
    else
    {
        s.elem = (int *)realloc(s.elem, (initsize + increasesize) * sizeof(int)); // 栈满，追加空间
        s.stacksize += increasesize; // 修改initsize的值
    }


}

// 空的时候返回1，非空返回0
bool StackEmpty(Stack &s)
{
    if(s.top == s.base) return true; // 空
    else return false;
}

// 输出栈顶元素返回给e
void pop(Stack &s, int &e)
{
    if(!StackEmpty(s)) // 非空
    {
         s.top --; // 定位到栈顶元素
         e = s.elem[s.top]; // 取出栈顶元素返回给e
    }
    else
        /*输出字符串语句*/
        printf("error");
}


// 对于输入一个任意的非负十进制整数，打印输出与其等值的八进制数
void conversion(Stack &s)
{
    InitStack(s); // 构造空栈
    int n; // 节点
    /*scanf函数对n赋值n要用引用形式*/
    scanf("%d",&n); // 输入十进制整数

    while(n) // 整数不为0
    {
        push(s, n % 8); // 输入余数进栈
        n = n / 8;
    }

    printf("对应的八进制数：");
    while(!StackEmpty(s))
    {
        int e;
        pop(s,e); // 按位输出栈内元素赋值给e
        printf("%d", e); // 输出
    }
}
