#include <iostream>
#include <string>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef char ElemType;

typedef struct StackNode {
    ElemType data;
    struct StackNode* next;
} StackNode, *LinkStack;

// 初始化栈
void initStack(LinkStack& s) {
    s = NULL;
}

// 判断栈是否为空
bool isEmpty(LinkStack s) {
    return s == NULL;
}

// 入栈
int push(LinkStack& s, ElemType data) {
    StackNode* node = new StackNode();
    if (!node) {
        return OVERFLOW;
    }
    node->data = data;
    node->next = s;
    s = node;
    return OK;
}

// 出栈
int pop(LinkStack& s, ElemType& data) {
    if (isEmpty(s)) {
        return ERROR;
    }
    StackNode* temp = s;
    data = temp->data;
    s = s->next;
    delete temp;
    return OK;
}

// 获取栈顶元素
int getTop(LinkStack s, ElemType& data) {
    if (isEmpty(s)) {
        return ERROR;
    }
    data = s->data;
    return OK;
}

// 获取字符串输入
void getInput(string& exp) {
    cout << "请输入要查验的字符串，并以'#'号结尾：" << endl;
    getline(cin, exp);
}

// 括号匹配算法
bool isValid(string s) {
    LinkStack stack;
    initStack(stack);
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        switch (c) {
            case '(':
            case '[':
            case '{':
                if (push(stack, c) == OVERFLOW) {
                    return false;
                }
                break;

            case ')':
                if (isEmpty(stack)) {
                    return false;
                }
                char left1;
                pop(stack, left1);
                if (left1 != '(') {
                    return false;
                }
                break;

            case ']':
                if (isEmpty(stack)) {
                    return false;
                }
                char left2;
                pop(stack, left2);
                if (left2 != '[') {
                    return false;
                }
                break;

            case '}':
                if (isEmpty(stack)) {
                    return false;
                }
                char left3;
                pop(stack, left3);
                if (left3 != '{') {
                    return false;
                }
                break;
        }
    }

    return isEmpty(stack);
}

int main() {
    string exp;
    char cont;
    do {
        getInput(exp);

        if (exp.empty() || exp.back() != '#') {
            cout << "输入格式错误，请重新输入！" << endl;
            continue;
        }

        exp.pop_back();

        bool valid = isValid(exp);
        if (valid) {
            cout << "括号匹配成功！" << endl;
        } else {
            cout << "括号匹配失败！" << endl;
        }

        cout << "是否继续判断？(y/n): ";
        cin >> cont;
        cin.ignore();

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
