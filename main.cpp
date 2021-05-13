#include <iostream>
#include <stdio.h>
/*malloc����ͷ�ļ�*/
#include "stdlib.h"
#include "Stack.h"

using namespace std;

int main()
{
    Stack s;
    printf("����һ��ʮ��������");
    void conversion(Stack &s);
    conversion(s);
    return 0;
}

// ����һ����ջ
void InitStack(Stack &s)
{
    s.elem = (int *)malloc(initsize * sizeof(int)); // ��ʼ�����ַ
    s.base = 0; // baseָ��ָ��ջ��
    s.top = 0;// ��ʼ��topָ��ָ��ջ��Ԫ�ص���һ��λ��
    s.stacksize = 10;
}


// ����nΪ�µ�ջ��Ԫ��
void push(Stack &s, int n)
{
    if(s.top - s.base <= initsize) // ����
    {
        /*����������s.top����top*/
        s.elem[s.top] = n; // ����n
        s.top += 1 ; // topָ��+1
    }
    else
    {
        s.elem = (int *)realloc(s.elem, (initsize + increasesize) * sizeof(int)); // ջ����׷�ӿռ�
        s.stacksize += increasesize; // �޸�initsize��ֵ
    }


}

// �յ�ʱ�򷵻�1���ǿշ���0
bool StackEmpty(Stack &s)
{
    if(s.top == s.base) return true; // ��
    else return false;
}

// ���ջ��Ԫ�ط��ظ�e
void pop(Stack &s, int &e)
{
    if(!StackEmpty(s)) // �ǿ�
    {
         s.top --; // ��λ��ջ��Ԫ��
         e = s.elem[s.top]; // ȡ��ջ��Ԫ�ط��ظ�e
    }
    else
        /*����ַ������*/
        printf("error");
}


// ��������һ������ķǸ�ʮ������������ӡ��������ֵ�İ˽�����
void conversion(Stack &s)
{
    InitStack(s); // �����ջ
    int n; // �ڵ�
    /*scanf������n��ֵnҪ��������ʽ*/
    scanf("%d",&n); // ����ʮ��������

    while(n) // ������Ϊ0
    {
        push(s, n % 8); // ����������ջ
        n = n / 8;
    }

    printf("��Ӧ�İ˽�������");
    while(!StackEmpty(s))
    {
        int e;
        pop(s,e); // ��λ���ջ��Ԫ�ظ�ֵ��e
        printf("%d", e); // ���
    }
}
