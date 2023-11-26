#include <iostream>
using namespace std;

const int MVNum = 100; // 最大顶点数

typedef char VertexType; // 顶点类型
typedef int EdgeType; // 边的权值类型

typedef struct {
    VertexType vexs[MVNum]; // 顶点数组
    EdgeType arcs[MVNum][MVNum]; // 邻接矩阵
    int vexNum, arcNum; // 顶点数和边数
} MGraph;

int LocateVex(MGraph G, VertexType v) {
    for (int i = 0; i < G.vexNum; i++) {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

void CreateUDG_M(MGraph &G) {
    cout << "请输入无向图的顶点数和边数：" << endl;
    cin >> G.vexNum >> G.arcNum;

    cout << "请输入每个顶点的值：" << endl;
    for (int i = 0; i < G.vexNum; i++) {
        cout << "请输入第" << i << "个顶点的值：";
        cin >> G.vexs[i];
    }

    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            G.arcs[i][j] = 0;
        }
    }

    cout << "请输入每条边的顶点1和顶点2：" << endl;
    for (int k = 0; k < G.arcNum; k++) {
        cout << "请输入第" << k << "条边的顶点1和顶点2（以空格作为间隔）：";
        VertexType v1, v2;
        cin >> v1 >> v2;

        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        if (i != -1 && j != -1) {
            G.arcs[i][j] = 1;
            G.arcs[j][i] = 1; 
        } else {
            cout << "顶点不存在！" << endl;
            k--; 
        }
    }
}


bool visited[MVNum]; // 访问标志数组

int FirstAdjVex(MGraph G, VertexType v) {
    int i = LocateVex(G, v);
    for (int j = 0; j < G.vexNum; j++) {
        if (G.arcs[i][j] == 1)
            return j;
    }
    return -1; 
}
int NextAdjVex(MGraph G, VertexType v, VertexType w) {
    int i = LocateVex(G, v);
    int j = LocateVex(G, w);
    for (int k = j + 1; k < G.vexNum; k++) {
        if (G.arcs[i][k] == 1)
            return k;
    }
    return -1; 
}

void DFS(MGraph G, VertexType v) {
    visited[LocateVex(G, v)] = true;
    cout << v << " ";

    for (int w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, G.vexs[w])) {
        if (!visited[w]) {
            DFS(G, G.vexs[w]);
        }
    }
}

void PrintMatrix(MGraph G) {
    cout << "邻接矩阵：" << endl;
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            cout << G.arcs[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    MGraph G;
    CreateUDG_M(G);

    for (int i = 0; i < G.vexNum; i++) {
        visited[i] = false;
    }

    cout << "深度优先搜索该无向图的结果：" << endl;
    for (int i = 0; i < G.vexNum; i++) {
        if (!visited[i]) {
            DFS(G, G.vexs[i]);
        }
    }

    cout << endl;
    PrintMatrix(G);

    return 0;
}
