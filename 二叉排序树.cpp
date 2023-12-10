#include <iostream>
using namespace std;

typedef int KeyType;
typedef struct {
    KeyType key;
    int otherinfo;
} ElemType;

typedef struct BSTNode {
    ElemType data;
    struct BSTNode* lchild, * rchild;
} BSTNode, * BSTree;

// 插入数据
void InsertBST(BSTree& T, ElemType e) {
    if (T == NULL) {
        T = new BSTNode;
        T->data.key = e.key;
        T->data.otherinfo = e.otherinfo;
        T->lchild = T->rchild = NULL;
        return;
    }
    else if (e.key == T->data.key)
        return;
    else if (e.key < T->data.key)
        InsertBST(T->lchild, e);
    else
        InsertBST(T->rchild, e);
}

// 创建二叉排序树
void CreateBST(BSTree& T) {
    T = NULL;
    cout << "请一次输入关键字，输入-1时创建结束！" << endl;
    KeyType key;
    cin >> key;
    while (key != -1) {
        ElemType elem;
        elem.key = key;
        elem.otherinfo = 0;
        InsertBST(T, elem);
        cin >> key;
    }
}

// 查找数据
BSTree searchBST(BSTree T, KeyType key) {
    if (T == NULL || T->data.key == key)
        return T;
    else if (key < T->data.key)
        return searchBST(T->lchild, key);
    else
        return searchBST(T->rchild, key);
}

// 中序遍历
void inorderBST(BSTree T) {
    if (T != NULL) {
        inorderBST(T->lchild);
        cout << T->data.key << " ";
        inorderBST(T->rchild);
    }
}

int main() {
    BSTree T = NULL;
    int choice;

    cout << "-------------二叉排序树的定义和基本操作-------------------" << endl;
    cout << "1、创建二叉排序树" << endl;
    cout << "2、查找数据" << endl;
    cout << "3、插入数据" << endl;
    cout << "4、中序遍历" << endl;
    cout << "0、退出" << endl;

    while (true) {
        cout << "请输入菜单对应的数字：";
        cin >> choice;

        switch (choice) {
        case 1:
            CreateBST(T);
            break;
        case 2:
            KeyType search_key;
            cout << "请输入要查找的关键字：";
            cin >> search_key;
            if (searchBST(T, search_key) != NULL)
                cout << "关键字存在，节点指针为：" << searchBST(T, search_key) << endl;
            else
                cout << "关键字不存在！" << endl;
            break;
        case 3:
            KeyType insert_key;
            cout << "请输入要插入的关键字：";
            cin >> insert_key;
            {
                ElemType elem;
                elem.key = insert_key;
                elem.otherinfo = 0;
                InsertBST(T, elem);
            }
            cout << "插入成功！" << endl;
            break;
        case 4:
            cout << "当前二叉排序树的中序遍历结果为：";
            inorderBST(T);
            cout << endl;
            break;
        case 0:
            cout << "退出成功！" << endl;
            return 0;
        default:
            cout << "无效的输入，请重新输入！" << endl;
            break;
        }
    }
}
