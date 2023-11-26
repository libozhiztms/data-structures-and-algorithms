#include <iostream>
using namespace std;

typedef int QElemType;

// 链队列结点定义
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

// 链队列定义
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

// 初始化链队列
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    cout << "①初始化链队列成功\n";
    cout << "初始化成功，队头指针为：" << Q.front << "，队尾指针为：" << Q.rear << endl;
}

// 判断链队列是否为空
bool QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}

// 入队操作
void EnQueue(LinkQueue &Q, QElemType x)
{
    QueuePtr p = new QNode;
    p->data = x;
    p->next = NULL;

    if (QueueEmpty(Q))
    {
        Q.front->next = p;
        Q.rear = p;
    }
    else
    {
        Q.rear->next = p;
        Q.rear = p;
    }

    cout << x << " 入队成功，队头指针为：" << Q.front << "，队尾指针为：" << Q.rear << endl;
}

// 出队操作
void DeQueue(LinkQueue &Q, QElemType &x)
{
    if (QueueEmpty(Q))
    {
        cout << "队列已空，无法出队！" << endl;
        return;
    }

    QueuePtr p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
    {
        Q.rear = Q.front;
    }
    delete p;
    cout << x << " 出队成功，队头指针为：" << Q.front->next << "，队尾指针为：" << Q.rear << endl;
}


int main()
{
    LinkQueue Q;
    QElemType x;
    InitQueue(Q);
    cout << "②依次入队1-5" << endl;
    for (int i = 1; i <= 5; i++)
    {
        EnQueue(Q, i);
    }

    cout << "③出队直至队空" << endl;
    while (!QueueEmpty(Q))
    {
        DeQueue(Q, x);
    }

    delete Q.front;
    return 0;
}
