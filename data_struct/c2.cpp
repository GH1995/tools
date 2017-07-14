// 第2章 线性表

//顺序表

#define LiST_INIT_SIZE 100
#define LISTINCREMENT 10

struct Sqlist {
  ElemType *elem;
  int length;
  int listsize;
};

// 总结了该表的所有特征，位置，已用长度，表长
// 第一部分已然结束，顺序表并没有什么好说的

// 单链表
// 逻辑描述

typedef struct LNode {
  ElemType data; // 数据data与指针next（背）
  struct LNode *next;
} LNode, *LinkList;

// 记住LNode就可以了，还有data和next

//以下是运算

//（1）求表长
// L是带头结点的单链表（默认）

int LengthList1(LinkList L) {
  LNode *p = L; // p指向头结点
  int j = 0;

  /*
  *   重要
  */
  while (p->next) // 探路先锋告诉我下一步是安全的，我就在后面计数++（背）
  {
    p = p->next;
    j++;
  }

  return j;
}

// L是不带头结点的单链表

int LengthList2(LinkList L) {
  LNode *p = L;
  int j = 1;

  if (p == NULL) // 需要这一句，以防出门就死
    return 0;

  /*
  *   重要
  */
  while (p->next) {
    p = p->next;
    j++;
  }

  return j;
}

//（2）建立带头结点的单链表

// 头插法

void CreateListF(LinkList &L, ElemType a[],
                 int n) // 需要背下这个高大上的名字CreateListF（背）
{
  LNode *s; // 该指针要作为注射器
  int i;
  L = (LinkList)malloc(sizeof(
      LNode)); // 创建头结点 第一步：要创建第一个冰激凌，该冰激凌要照顾其他孩子
  L->next = NULL;

  for (i = 0; i < n; i++) // （背）
  {
    s = (LNode *)malloc(
        sizeof(LNode)); // 创建新结点 第二步：生产一个薄饼，并让注射器指向它
    s->data = a[i]; //                  第三步：注入冰激凌

    /*
    *   重要
    */
    s->next = L->next; //                  第四步：代替L照顾其他孩子
    L->next = s;       //                  第五步：L照顾s
  }
}

// 讲述了一个故事
// 故事的主角为s,L
// 配角为i，a[i]

// 尾插法

void CreateListR(LinkList &L, ElemType a[],
                 int n) // 需要背下这个高大上的名字CreateListR（背）
{
  LNode *s, *r;
  int i;
  L = (LinkList)malloc(sizeof(LNode)); // 创建头结点 第一步：要创建第一个冰激凌

  L->next = NULL;
  r = L; // r始终指向链表的尾结点，开始时指向头结点
         // 第二步：设r作为监视器，始终注视着尾结点

  for (i = 0; i < n; i++) {
    s = (LinkList)malloc(
        sizeof(LNode)); // 创建新结点    第三步：生产一个薄饼，并让注射器指向它
    s->data = a[i]; //              第四步：注入冰激凌

    /*
    *   重要
    */
    r->next = s; //              第五步：监视器的的下一结点指向s
    r = s;       //              第六步：监视器定位s为新的尾结点
  }

  r->next = NULL;
}

// 讲述了一个故事
// 故事的主角为s,r,L
// 配角为i，a[i]

//（3）查找
// 按序号查找
LNode *GetList(LinkList L, int i) // GetList名字要（背）
{
  LNode *p = L;
  int j = 0;

  /*
  *   重要
  */
  while (p->next != NULL && j < i) // j不能翻过墙寻找，只能在n-1查看n的情况
  {
    p = p->next; // n-1已经自动移位
    j++;
  }

  if (j == i)
    return p;
  else
    return NULL;
}
// 和LengthList1差不多

// 按值查找
LNode *LocateList(LinkList L, ElemType x) // 名字LocateList要（背）
{
  LNode *p = L->next;

  /*
  *   重要
  */
  while (p != NULL && p->data != x) // 背
    p = p->next;

  return p;
}

//（4）插入

// 后插结点
s->next = p->next;
p->next = s;

// 前插结点
q = L;
while (q->next != p) // 此时q->next已经是p，谨记此条件
  q = q->next;

s->next = q->next;
q->next = s;

//（5）删除
q = L;
while (q->next != p) // 此时q->next已经是p，谨记此条件
  q = q->next;
/*
*   位置很重要
*/

q->next = p->next;
free(p);

// 双向链表
//（1）插入
s->prior = p->prior;
p->prior->next = s;
s->next = p;
p->prior = s;

//（2）删除
p->prior->next = p->next;
p->next->prior = p->prior;
free(p);
