#include <iostream>
using namespace std;
#define MAXSIZE 10

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char ElemType; // 定义类型ElemType，本例中使用的数据元素类型为char型

/*-------A------
顺序表类型SqList的定义*/
typedef struct
{
	ElemType *elem;
	int length;
} SqList;
/*---------B--------
顺序表的基本操作InitList，DestroyList，ListEmpty，ListLength，TraverseList，
  GetElem，LocateElem，ListInsert，ListDelete的函数定义
  注意：算法（伪码）和代码程序的区别，算法中没有定义的变量在代码实现时要定义，代码要符合C/C++语言语法;
体会输出型参数和输入型参数的区别；
		注意函数的返回值的设定规律和后面主函数的调用关系*/

// 初始化顺序表
Status InitList(SqList &L)
{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
	{
		exit(OVERFLOW);
	}
	L.length = 0;
	return OK;
}
// 销毁顺序表
Status DestoryList(SqList &L)
{
	delete[] L.elem;
	L.elem = NULL;
	L.length = 0;
	return OK;
}
// 判断表是否为空
Status ListEmpty(SqList L)
{
	return L.length == 0 ? true : false;
}
// 求表长
int ListLength(SqList L)
{
	return L.length;
}
// 遍历顺序表
void TraverseList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
}
// 按位置取值
Status GetElem(SqList L, int i, ElemType &e)
{
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}
	e = L.elem[i - 1];
	return OK;
}

// 按值查找
int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

// 插入数据元素
Status ListInsert(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	if (L.length == MAXSIZE)
	{
		return ERROR;
	}
	for (int j = L.length; j >= i; j--)
	{
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}

// 删除数据元素
Status ListDelete(SqList &L, int i, ElemType &e)
{
	if (i < 1 || i > L.length)
	{
		return ERROR;
	}
	e = L.elem[i - 1];
	for (int j = i; j < L.length; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
void menu() // 菜单函数，显示实验中的主菜单
{
	cout << "----------顺序表的定义和基本操作----------\n";
	cout << "-         1  初始化顺序表                -\n";
	cout << "-         2  销毁顺序表                  -\n";
	cout << "-         3  判断表是否为空              -\n";
	cout << "-         4  求表长                      -\n";
	cout << "-         5  输出顺序表内容              -\n";
	cout << "-         6  按位置取值                  -\n";
	cout << "-         7  按值查找                    -\n";
	cout << "-         8  插入数据元素                -\n";
	cout << "-         9  删除数据元素                -\n";
	cout << "-         0  退出                        -\n";
	cout << "请输入菜单对应的数字：";
}
int main()
{
	SqList L;
	int i, k;
	ElemType c;

	for (;;)
	{
		menu(); // 调用菜单函数
		cin >> k;
		switch (k)
		{
		case 1:
			InitList(L);
			cout << "初始化顺序表L：L.elem=" << &L.elem << " L.length=" << L.length << "\n";
			system("pause"); // 系统函数，暂停界面，显示结果，按任意键继续
			system("cls");	 // 系统函数，清除屏幕上的运行结果和上一次输出的菜单
			break;
		case 2:
			DestoryList(L);
			cout << "释放顺序表L：L.elem=" << &L.elem << " L.length=" << L.length << "\n";
			system("pause");
			system("cls");
			break;
		case 3:
			printf("判断顺序表L当前是否为空：");
			if (ListEmpty(L))
				cout << "L is empty.\n";
			else
				cout << "L is not empyt.\n";
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "顺序表L的当前长度为:" << ListLength(L) << "\n";
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "输出顺序表L：";
			TraverseList(L);
			cout << "\n";
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "请输入查找位置1~" << ListLength(L) << "：";
			cin >> i;
			if (GetElem(L, i, c))
				cout << i << "位置上的数据是" << c << "\n。";
			else
				cout << "没有找到，请核实查找位置是否正确。\n";
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "请输入要查找的数据：";
			getchar();
			cin >> c;
			if (i = LocateElem(L, c))
				cout << c << "是顺序表中的第" << i << "个数据。\n";
			else
				cout << c << "不存在此顺序表中。\n";
			system("pause");
			system("cls");
			break;
		case 8:
			printf("请输入要插入的数据：");
			getchar();
			cin >> c;
			;
			cout << "请输入要插入的位置（1-" << ListLength(L) + 1 << "）：";
			cin >> i;
			if (ListInsert(L, i, c))
				cout << "插入成功！\n";
			else
				cout << "插入失败，请核实插入位置。\n";
			system("pause");
			system("cls");
			break;
		case 9:
			cout << "请输入要删除的数据位置（1-" << ListLength(L) << "）：";
			cin >> i;
			if (ListDelete(L, i, c))
				cout << "删除成功！你删除的数据是：" << c << "\n";
			else
				cout << "删除失败，请核实插入位置。\n";
			system("pause");
			system("cls");
			break;
		case 0:
			return 0;
		}
	}
}