#include <iostream>
using namespace std;

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 先序创建二叉树
BiTree CreateBinaryTree()
{
    TElemType val;
    cin >> val;

    if (val == '#')
    {
        return NULL;
    }

    BiTree T = new BiTNode;
    T->data = val;
    T->lchild = CreateBinaryTree();
    T->rchild = CreateBinaryTree();

    return T;
}

// 计算结点个数
int CountNodes(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }

    return CountNodes(T->lchild) + CountNodes(T->rchild) + 1;
}

// 计算树的深度
int GetDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int m = GetDepth(T->lchild);
        int n = GetDepth(T->rchild);
        if (m > n)
            return (m + 1);
        else
            return (n + 1);
    }
}

// 先序遍历输出二叉树
void PreorderTraversal(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";
        PreorderTraversal(T->lchild);
        PreorderTraversal(T->rchild);
    }
}

// 中序遍历输出二叉树
void InorderTraversal(BiTree T)
{
    if (T)
    {
        InorderTraversal(T->lchild);
        cout << T->data << " ";
        InorderTraversal(T->rchild);
    }
}

// 后序遍历输出二叉树
void PostorderTraversal(BiTree T)
{
    if (T)
    {
        PostorderTraversal(T->lchild);
        PostorderTraversal(T->rchild);
        cout << T->data << " ";
    }
}

int main()
{
    cout << "1、请按先序输入结点，空树用#表示：" << endl;

    BiTree T = CreateBinaryTree();

    // 输出结点个数
    int count = CountNodes(T);
    cout << "2、结点个数为：" << count << endl;

    // 输出树的深度
    int depth = GetDepth(T);
    cout << "3、树的深度为：" << depth << endl;

    // 输出先序、中序、后序遍历结果
    cout << "4-1、树的先序遍历结果为：";
    PreorderTraversal(T);
    cout << endl;

    cout << "4-2、树的中序遍历结果为：";
    InorderTraversal(T);
    cout << endl;

    cout << "4-3、树的后序遍历结果为：";
    PostorderTraversal(T);
    cout << endl;

    return 0;
}
