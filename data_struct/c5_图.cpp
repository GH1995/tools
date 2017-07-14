// 第5章 图

// 图的存储结构

// 邻接矩阵

#define MAX_VERTEX_NUM 20 // 最大顶点数设为20

typedef char VertexType; // 顶点类型为字符型
typedef int VRType;      // 边的权值设为整型

struct MGragh {
  VertexType vexs[MAX_VERTEX_NUM]; // 顶点表

  VRType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 边表，邻接矩阵

  int vexnum; // 顶点数
  int arcnum; // 边数
};

// ************************************************************************

// 邻接表

#define MAX_VERTEX_NUM 20 // 最大顶点数设为20

struct ArcNode // 边表结点
{
  int adjvex;              // 邻接点域
  struct ArcNode *nextarc; // 指向下一个邻接点的指针域
};

typedef struct VNode // 顶点表结点
{
  VertexType data; // 顶点域

  ArcNode *firstarc; // 边表头指针
} VNode, AdjList[MAX_VERTEX_NUM];

/*
*	AdjList是邻接表
*/

struct ALGraph // ALGraph是以邻接表方式存储的图类型
{
  AdjList adjvex; // 邻接表

  int vexnum; // 顶点数
  int arcnum; // 边数
};

// ************************************************************************

// 图的遍历

// （1）深度优先搜索

// <1>递归算法
void DFSTraverse(Graph G) {
  for (v = 0; v < G.vexnum; v++)
    visited[v] = FALSE;

  for (v = 0; v < G.vexnum; v++)
    if (!visited[v])
      DFS(G, v);
}

void DFS(Graph G, int v) {
  visited[v] = TRUE;
  Visit(v);

  for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
    if (!visited[w])
      DFS(G, w);
}

void DFSTraverseAL(ALGraph G) {
  for (int i = 0; i < G.vex; i++)
    visited[i] = FALSE;
  for (int i = 0; i < G.vexnum; i++)
    if (!visited[i])
      DFSAL(G, i);
}

void DFSAL(ALGraph G, int i) {
  ArcNode *p;

  Visit(G.AdjList[i]);
}

// ************************************************************************

// <2>非递归算法
void DFSTraverse(Graph G) {
  for (v = 0; v < G.vexnum; v++)
    visited[v] = FALSE;

  for (v = 0; v < G.vexnum; v++)
    if (!visited[v])
      DFSn(G, i);
}

void DFSn(Graph G, int v) {
  Stack s;
  Push(s, v);

  while (!StackEmpty(s)) {
    Pop(s, k);
    if (!visited[k]) {
      visited[k] = TRUE;
      Visit(k);

      for (w = FirstAdjVex(G, k); w >= 0; w = NextAdjVex(G, k, w))
        if (!visited[w] && w != GetTop(s))
          Push(s, w);
    }
  }
}

// （2）广度优先搜索

void BFSTraverse(Graph G) {
  for (v = 0; v < G.vexnum; v++)
    visited[v] = FALSE;
  for (v = 0; v < G.vexnum; v++)
    if (!visited[v])
      BFS(G, v);
}

void BFS(Graph G, int v) {
  InitQueue(Q);
  visited[v] = TRUE;
  EnQueue(Q, v);
  while (!QueueEmpty(Q)) {
    DeQueue(Q, u);
    for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
      if (!visited[w]) {
        visited[w] = TRUE;
        Visit(w);
        EnQueue(Q, w);
      }
  }
}

int visited[20];

void DFSTraverse(MGraph G) {
  for (int i = 0; i < G.vexnum; i++)
    visited[i] = false;

  for (int i = 0; i < G.vexnum; i++)
    if (!visited[i])
      DFS(G, i);
}

void DFS(MGraph G, int i) {
  visited[i] = true;
  cout << G.vexs << ' ';

  for (int j = 0; j < G.vexnum; j++)
    if (G.edges[i][j] && !visited[j])
      DFS(G, j);
}

void DFSTraverse(ALGraph G) {
  for (int i = 0; i < G.vexnum; i++)
    visited[i] = false;

  for (int i = 0; i < G.vexnum; i++)
    if (!visited[i])
      DFS(G, i);
}

void DFS(ALGraph G, int i) {
  visited[i] = true;
  cout << G.adjlist[i].data << ' ';

  ArcNode *p = G.adjlist[i].firstarc;
  while (p) {
    if (!visited[p->adjvex])
      DFS(G, p->adjvex);
    p = p->nextarc;
  }
}

void CreateMGraph(MGraph &G) {
  cin >> G.vexnum >> G.arcnum;

  for (int i = 0; i < G.vexnum; i++)
    cin >> G.vexs[i];

  for (int i = 0; i < G.vexnum; i++)
    for (int j = 0; j < G.vexnum; j++)
      G.edges[i][j] = 0;

  for (int i = 0; i < G.arcnum; i++) {
    int m, n;
    cin >> m >> n;
    G.edges[m][n] = G.edges[n][m] = 1;
  }
}

void CreateALGraph(ALGraph &G) {
  cin >> G.vexnum >> G.arcnum;

  for (int i = 0; i < G.vexnum; i++) {
    cin >> G.adjlist[i].data;
    G.adjlist[i].firstarc = NULL;
  }

  for (int k = 0; k < G.arcnum; k++) {
    int i, j;
    cin >> i >> j;

    ArcNode *p = new ArcNode;
    p->adjvex = j;
    p->nextarc = G.adjlist[i].firstarc;
    G.adjlist[i].firstarc = p;

    p = new ArcNode;
    p->adjvex = i;
    p->nextarc = G.adjlist[i].firstarc;
    G.adjlist[j].firstarc = p;
  }
}

void Prim_MiniSpanTree(MGraph G) {
  int adjvex[20];
  int lowcast[20];
  adjvex[0] = 0;
  lowcast[0] = 0;

  for (int i = 1; i < G.vexnum; i++) {
    lowcast[i] = G.edges[0][i];
    adjvex[i] = 0;
  }

  for (int i = 1; i < G.vexnum; i++) {
    int min = INFINITY;

    int j = 1;
    int k = 0;
    while (j < G.vexnum) {
      if (lowcast[j] != 0 && lowcast[j] < min) {
        min = lowcast[j];
        k = j;
      }
      j++;
    }

    cout << '(' << adjvex[k] << ',' << k << ') ';
    lowcast[k] = 0;

    for (int j = 0; j < G.vexnum; j++) {
      lowcast[j] = G.edges[k][j];
      adjvex[j] = k;
    }
  }
}

// 最小生成树
// Minimum Cost Spanning Tree

// 普里姆算法		Prim
// 病毒感染式的寻找非环最小

// 克鲁斯卡尔算法	Kruskal

// 最短路径
// 迪杰斯特拉算法	Dijkstra
// 以起始点为中心向外层层扩展，直到扩展到终点为止

// 弗洛伊德算法		Floyd
// 未完成

// 拓扑排序
//关键路径
