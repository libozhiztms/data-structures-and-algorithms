#include <iostream>
using namespace std;

#define MVNum 100

typedef char VerTexType;
typedef int OtherInfo;

struct ArcNode
{
    int adjvex;
    ArcNode* nextarc;
    OtherInfo info;
};

struct VNode
{
    VerTexType data;
    ArcNode* firstarc;
};

typedef VNode AdjList[MVNum];

struct ALGraph
{
    AdjList vertices;
    int vexnum, arcnum;
};

int LocateVex(ALGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v) {
            return i;
        }
    }
    return -1;
}

void CreateUDG(ALGraph& G)
{
    cout << "请输入图的顶点数，边数：";
    cin >> G.vexnum >> G.arcnum;

    for (int i = 0; i < G.vexnum; i++) {
        cout << "请输入第" << i << "个顶点的值：";
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }

    for (int i = 0; i < G.arcnum; i++) {
        VerTexType v1, v2;
        cout << "请输入第" << i << "条边的顶点1 顶点2（以空格作为间隔）：";
        cin >> v1 >> v2;

        int loc1 = LocateVex(G, v1);
        int loc2 = LocateVex(G, v2);

        ArcNode* p1 = new ArcNode;
        p1->adjvex = loc2;
        p1->nextarc = G.vertices[loc1].firstarc;
        G.vertices[loc1].firstarc = p1;

        ArcNode* p2 = new ArcNode;
        p2->adjvex = loc1;
        p2->nextarc = G.vertices[loc2].firstarc;
        G.vertices[loc2].firstarc = p2;
    }
}

void Display(ALGraph G)
{
    for (int i = 0; i < G.vexnum; i++) {
        cout << i << ":" << G.vertices[i].data << "-->";
        ArcNode* p = G.vertices[i].firstarc;
        while (p != NULL) {
            cout << " " << p->adjvex << "-->";
            p = p->nextarc;
        }
        cout << "^" << endl;
    }
    cout << "邻接表模拟输出：";
    for (int i = 0; i < G.vexnum; i++) {
        cout << G.vertices[i].data << ": ";
        ArcNode* p = G.vertices[i].firstarc;
        while (p != NULL) {
            cout << G.vertices[p->adjvex].data << " ";
            p = p->nextarc;
        }
        cout << endl;
    }
}

int main()
{
    ALGraph G;
    CreateUDG(G);
    Display(G);
    return 0;
}

