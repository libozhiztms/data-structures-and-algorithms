#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 10
typedef int Status;
typedef int SElemType;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

// 初始化栈
Status InitStack(SqStack &s)
{
    s.base = new SElemType[MAXSIZE]; // 动态分配栈空间
    if (!s.base)
    {
        cout << "Error:内存非配失败！" << endl;
        return OVERFLOW;
    }
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return OK;
}

// 判断栈是否为空
bool isEmpty(SqStack &s)
{
    return s.top == s.base;
}

// 判断栈是否已满
bool isFull(SqStack &s)
{
    return s.top - s.base == s.stacksize;
}

// 入栈操作
Status push(SqStack &s, SElemType item)
{
    if (isFull(s))
    {
        cout << "Error: 堆栈已满！" << endl;
        return ERROR;
    }
    *(s.top) = item;
    s.top++;
    return OK;
}

// 出栈操作
Status pop(SqStack &s, SElemType &item)
{
    if (isEmpty(s))
    {
        cout << "Error: 堆栈为空！" << endl;
        return ERROR;
    }
    s.top--;
    item = *(s.top);
    return OK;
}

// 获取栈顶元素
Status getTop(SqStack &s, SElemType &item)
{
    if (isEmpty(s))
    {
        cout << "Error: 堆栈为空！" << endl;
        return ERROR;
    }
    item = *(s.top - 1);
    return OK;
}

// 十进制转八进制
void convert(int N)
{
    SqStack s;
    SElemType e;
    InitStack(s);
    while (N != 0)
    {
        push(s, N % 8);
        N /= 8;
    }

    while (!isEmpty(s))
    {

        pop(s, e);
        cout << e;
    }
    cout << "\n";
}

int main()
{
    int N;
    cout << "请输入一个十进制数：";
    cin >> N;
    cout << "八进制为：";
    convert(N);

    return 0;
}
