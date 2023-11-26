#include <iostream>
using namespace std;

typedef int QelemType;

const int MAX_SIZE = 5;

typedef struct
{
    QelemType *base;
    int front;
    int rear;
} SqQueue;

// 初始化循环队列
// 初始化循环队列
void InitQueue(SqQueue &Q)
{
    Q.base = new QelemType[MAX_SIZE];
    Q.front = Q.rear = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}

// 判断队列是否已满
bool QueueFull(SqQueue Q)
{
    return (Q.rear + 1) % MAX_SIZE == Q.front;
}

// 入队操作
void EnQueue(SqQueue &Q, QelemType x)
{
    if (QueueFull(Q))
    {
        cout << "队列已满，无法入队！" << endl;
        return;
    }

    Q.base[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    cout << x << " 入队成功，队头下标为：" << Q.front << "，队尾下标为：" << Q.rear << endl;
}

// 出队操作
void DeQueue(SqQueue &Q, QelemType &x)
{
    if (QueueEmpty(Q))
    {
        cout << "队列已空，无法出队！" << endl;
        return;
    }

    x = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    cout << x << " 出队成功，队头下标为：" << Q.front << "，队尾下标为：" << Q.rear << endl;
}

int main()
{
    SqQueue Q;
    QelemType x;

    cout << "①初始化循环队列成功\n";
    // 初始化循环队列
    InitQueue(Q);
    cout << "初始化成功,队头下标为：" << Q.front << "，队尾下标为：" << Q.rear << endl;

    cout << "②依次入队1-5完成" << endl;
    for (int i = 1; i <= 5; i++)
    {
        EnQueue(Q, i);
    }

    EnQueue(Q, 6);
    cout << "③出队直至队空完成" << endl;
    while (!QueueEmpty(Q))
    {
        DeQueue(Q, x);
    }
    cout << "④依次入队6、7完成" << endl;
    EnQueue(Q, 6);
    EnQueue(Q, 7);

    delete[] Q.base;
    return 0;
}
