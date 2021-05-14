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
