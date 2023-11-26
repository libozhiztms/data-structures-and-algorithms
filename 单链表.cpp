#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0

typedef int Status;
typedef char ElemType;

// 定义单链表结点结构体
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化链表
Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}

// 销毁链表
Status DestoryList(LinkList &L)
{
    LNode *p;
    while (L)
    {
        p = L;
        L = L->next;
        delete p;
    }
    return OK;
}

// 判断链表是否为空
bool IsEmpty(LinkList L)
{
    return (L == NULL);
}

// 获取链表长度
int GetLength(LinkList L)
{
    int length = 0;
    LNode *p = L;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 头插法建立单链表
void CreatList_H(LinkList &L, int n)
{
    LNode *p = NULL;
    L = new LNode;
    L->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

// 尾插法建立单链表
void CreatList_R(LinkList &L, int n)
{
    LNode *p = NULL;
    LNode *r = NULL; // 尾指针

    L = new LNode;
    L->next = NULL;
    r = L;

    for (int i = 0; i < n; ++i)
    {
        p = new LNode;
        cin >> p->data;

        p->next = NULL;
        r->next = p;
        r = p;
    }
}

// 输出单链表内容
void TraveseList(LinkList L)
{
    cout << "链表内容: ";
    LinkList p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 按位置取值
Status GetElem(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j = 1;

    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    e = p->data;
    return OK;
}

// 插入数据元素
Status ListInsert(LinkList &L, int i, ElemType e)
{
    LinkList p, s;
    int j = 0;
    p = L;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1)
        return ERROR;
    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除数据元素
Status ListDelete(LinkList &L, int i)
{
    LinkList p = L;
    int j = 0;
    while ((p->next) && (j < (i - 1)))
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j != i - 1))  
        return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    delete q;  
    return OK;
}

// 菜单函数
void menu(LinkList &L)
{
    int choice;

    int position;   // 用于指定插入/删除的位置
    ElemType value; // 用于插入的数据元素
    ElemType e;     // 用于按位置取值的结果

    while (true)
    {
        cout << "\n----- 菜单 -----" << endl;
        cout << "1. 初始化链表" << endl;
        cout << "2. 销毁链表" << endl;
        cout << "3. 头插法建立单链表（4个结点）" << endl;
        cout << "4. 尾插法建立单链表（4个结点）" << endl;
        cout << "5. 输出单链表内容" << endl;
        cout << "6. 按位置取值" << endl;
        cout << "7. 插入数据元素" << endl;
        cout << "8. 删除数据元素" << endl;
        cout << "9. 退出" << endl;

        cout << "请输入选项号: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            InitList(L);
            cout << "链表已初始化。" << endl;
            break;
        }
        case 2:
        {
            DestoryList(L);
            cout << "链表已销毁。" << endl;
            break;
        }
        case 3:
        {
            CreatList_H(L, 4);
            cout << "已使用头插法建立单链表（4个结点）。" << endl;
            break;
        }
        case 4:
        {
            CreatList_R(L, 4);
            cout << "已使用尾插法建立单链表（4个结点）。" << endl;
            break;
        }
        case 5:
        {
            TraveseList(L);
            break;
        }
        case 6:
        {
            cout << "请输入要获取的位置: ";
            cin >> position;
            if (GetElem(L, position, e) == OK)
            {
                cout << "位置 " << position << " 的元素为: " << e << endl;
            }
            break;
        }
        case 7:
        {
            cout << "请输入要插入的位置: ";
            cin >> position;
            cout << "请输入要插入的元素: ";
            cin >> value;
            if (ListInsert(L, position, value) == OK)
            {
                cout << "元素已插入到位置 " << position << "。" << endl;
            }
            break;
        }
        case 8:
        {
            cout << "请输入要删除的位置: ";
            cin >> position;
            if (ListDelete(L, position) == OK)
            {
                cout << "位置 " << position << " 的元素已删除。" << endl;
            }
            break;
        }
        case 9:
        {
            return;
        }
        default:
            cout << "无效的选项！" << endl;
        }
    }
}

// 主函数
int main()
{
    LinkList L = nullptr;
    menu(L);
    return 0;
}
