// 第4章 树和二叉树

// // 二叉树

/*
*   几个概念
*   *满二叉树
*   *完全二叉树
*/

/*
*   二叉树的性质
*
*   <1>k层最多有2^(k-1)个结点
*   <2>深度为k的二叉树最多有2^k - 1个结点
*   <3>n0(叶子结点数) = n2(度为2的结点数) + 1
*	because: n = n0 + n1 + n2;
*			 n - 1 = n1 + 2* n2;
*/

// 二叉树的顺序存储结构

#define MAX_TREE_SIZE 100 // 二叉树的最大结点数

typedef TElemType SqBiTree[MAX_TREE_SIZE] // 0号单元存放根结点

    /*
    *   不常用
    */

    // 二叉链表形式

    typedef struct BiTNode {
  TElemType data; //数据

  struct BiTNode *lchild; // 左孩子指针
  struct BiTNode *rchild; // 右孩子指针

} BiTNode, *BiTree;

/*
*   一般情况下就使用这种存储结构
*/

// // 遍历二叉树（必背的七个算法）

// （1）前序遍历的递归实现
void PreOrder(BiTree b) {
  if (b != NULL) {
    Visit(b->data);
    // 访问结点的数据域

    PreOrder(b->lchild); // 先序递归遍历b的左子树
    PreOrder(b->rchild); // 先序递归遍历b的右子树
  }
}

// （2）中序遍历的递归实现
void InOrder(BiTree b) {
  if (b != NULL) {
    InOrder(b->lchild);

    Visit(b->data);

    InOrder(b->rchild);
  }
}

// （3）后序遍历的递归实现
void PostOrder(BiTree b) {
  if (b != NULL) {
    PostOrder(b->lchild);
    PostOrder(b->rchild);

    Visit(b->data);
  }
}

// （4）层序遍历的实现

/*
*   一维数组Queue[MAX_TREE_SIZE]用以实现队列，
*   变量front和rear分别表示当前队首元素和队尾元素在数组中的位置。
*/

void LevelOrder(BiTree b) {
  /*
  *   先定义了 存储树系结点队列，队首队尾元素的“指针”
  */
  BiTree Queue[MAX_TREE_SIZE];

  int front;
  int rear;

  /*
  *   如果树为空，掉头就走
  */
  if (b == NULL)
    return;

  /*
  *   初始化，队列的初始化是使我想到数轴，0是一个预留的位置哈
  *   预备存储rear，b根结点
  */
  front = -1;
  rear = 0;
  Queue[rear] = b;

  /*
  *   一个烧煤的炉子
  */

  while (front ！ = rear) // 队列没有穷尽
  {
    Visit(Queue[++front]->data);
    // 访问队头结点数据域

    if (Queue[front]->lchild != NULL)
      Queue[++rear] = Queue[front]->lchild;
    // 将队头结点的左孩子结点入队

    if (Queue[front]->rchild != NULL)
      Queue[++rear] = Queue[front]->rchild;
    // 将队头结点的右孩子结点入队
  }
}

// （5）前序遍历的非递归实现

/*
*   由先序遍历过程可知，先访问根结点，再访问左子树，最后访问右子树。
*   因此，先将根结点进栈，在栈不空时循环，出栈，
*   访问*p结点，将其右孩子进栈，再将左孩子结点进栈。
*
*   这里使用栈而不是队列！
*/

void PreOrder1(BiTree b) {
  BiTree St[MAX_TREE_SIZE];
  BiTree p;
  int top = -1;

  /*
  *   再次让我想起了那个数轴，不过这个数轴只到-1，没有更小的了。
  */

  if (b != NULL) {
    St[++top] = b; // 根结点进栈

    while (top > -1) // 栈不空时循环
    {
      p = St[top--]; // 出栈
      Visit(p->data);

      /*
      *   出栈并访问该结点
      */

      if (p->rchild != NULL)
        St[++top] = p->rchild;
      // 右孩子结点进栈

      if (p->lchild != NULL)
        St[++top] = p->lchild;
      // 左孩子结点进栈
    }
  }
}

// （6）中序遍历的非递归实现

/*
*   由中序遍历过程可知，采用一个栈保存需要返
*   回的结点指针，先扫描（并非访问）根结点的所有左
*   节点并将它们一一进栈。然后出栈一个结点，显然
*   该结点没有左孩子结点或者左孩子结点已访问过，
*   则访问它。然后扫描该结点的右孩子结点，将其进
*   栈，再扫描该右孩子结点的所有左结点并一一进栈，
*   如此重要，直到栈空为止。
*
*/

void InOrder1(BiTree b) {
  BiTree St[MAX_TREE_SIZE];
  BiTree p;

  int top = -1;

  if (b != NULL) {
    p = b;

    while (p != NULL || top > -1) {
      while (p != NULL) // 扫描*p的左孩子并进栈
      {
        St[++top] = p;
        p = p->lchild;
      }
      if (top > -1) {
        p = St[top--];
        // 出栈*p结点并访问

        Visit(b->data);

        p = p->rchild;
        // 扫描*p的右孩子结点
      }
    }
  }
}

// （7）后序遍历的非递归实现

/*
*       由后序遍历过程可知，采用一个栈保存需要返
*   回的结点指针，先扫描根结点的所有左结点并将它
*   们一一进栈，出栈一个结点*b即当前结点，然后扫
*   描该结点的右孩子并进栈。当一个结点的左后孩子
*   结点均被访问后再访问该结点，如此这样，直到栈空
*   为止。
*       如何判断一个结点*b的右孩子结点已访问
*   过，为此用p保存刚刚访问过的结点（初值为
*   NULL），若b->rchild == p成立（在后序遍历中，*b
*   的右孩子结点一定刚好在*b之前访问），说明*b
*   的左右子树均已被访问，现在应访问*b。
*       从上述过程可知，栈中保存的是当前结点*b
*   的所有祖先结点（均未访问过）。
*
*/

void PostOrder1(BiTree b) {
  BiTree St[MAX_TREE_SIZE];
  BiTree b;
  int flag, top = -1;

  if (b != NULL) {
    do {
      while (b != NULL) // 扫描*b的左结点并进栈
      {
        St[++top] = b;
        b = b->lchild;
      }

      p = NULL; // p指向栈顶结点的前一个已访问的结点
      flag = 1; // 设置b的已访问标记为已访问过

      while (top != -1 && flag) {
        b = St[top]; // 取出当前的栈顶元素

        /*
        *   右孩子不存在或右孩子已被访问，则访问*b
        */

        if (b->rchild == p) {
          Visit(b->data); // 访问*b结点
          top--;
          p = b; // p指向被访问的结点
        } else {
          b = b->rchild; // b指向右孩子结点
          flag = 0;      // 设置未被访问的标记
        }
      }
    } while (top != -1);
  }
}

/*
*   建立二叉链表方式存储的二叉树
*   以加入结点的前序序列输入，构造二叉链表
*/
void CreateBiTree(BiTree &b) {
  char ch;

  scanf("%c", &ch);

  if (ch == '#')
    b = NULL; // 读入0时，将相应结点置空
  else {
    /*
    *   生产结点空间，填入数据
    */
    // b = (BiTNode *)malloc(sizeof(BiTNode));
    b = new BiTNode;
    b->data = ch;
    b->lchild = NULL;
    b->rchild = NULL;

    CreateBiTree(b->lchild); // 构造左子树
    CreateBiTree(b->rchild); // 构造右子树
  }
}

// 线索二叉树
/*
    按照某种遍历方式对二叉树进行遍历，可
把二叉树中所有结点排列为一个线性序列，二叉树
中每个结点在这个序列中的直接前驱结点和直接后
继结点是什么，二叉树的存储结构中并没有反映出
来，只能在对二叉树遍历的的动态过程中得到这些信
息。为了保留结点在某种遍历序列中直接前驱和直
接后继的位置信息，可以利用具有n个结点的二叉
树中的叶子结点和一度结点的n+1个空指针域来
指示，这些指向直接前驱结点和指向直接后继结点
的指针被称为线索，加了线索的二叉树称为线索二
叉树。
    在线索二叉树（特别是中序线索二叉树）上遍历
就消除了递归，也不使用栈（其中后序线索二叉树中
查找后继仍需要栈）。
*/

//线索二叉树存储表示
enum PointerTag { Link, Thread };

typedef struct BiThrNode {
  TElemType data;

  struct BiThrNode *lchild;
  struct BiThrNode *rchild;

  PointerTag LTag;
  PointerTag RTag;

} BiThrNode, *BiThrTree;

// 建立一棵中序线索二叉树
/*
*       实质上就是遍历一棵二叉树。在遍历过程中，
*   Visit操作是检查当前结点的左、右指针域是否为
*   空，如果为空，将它们改为指向前驱结点或后继结点
*   的线索。为实现这一过程，设指针pre始终指向刚
*   刚访问过的结点，即若指针p指向当前结点，则，pre
*   指向它的前驱，以便增设线索。
*/

/*
*   中序遍历二叉树T，将其中序线索化，head指向头结点
*/
int InOrderThr(BiThrTree &head, BiThrTree T) {
  if (!(head = (BiThrNode *)malloc(sizeof(BiThrNode))))
    return 0;

  // 建立头结点
  head->LTag = 0;
  head->RTag = 1;

  head->rchild = head; // 右指针回指

  if (!T)
    head->lchild = head; // 若二叉树为空，则左指针回指
  else {
    head->lchild = T;
    pre = head;

    InThreading(T); // 中序遍历进行中序线索化

    pre->rchild = head;
    pre->RTag = 1;

    // 最后一个结点线索化
    head->rchild = pre;
  }

  return 1;
}

void InThreading(BiThrTree p) {
  if (p) {
    // 左子树线索化
    InThreading(p->lchild);

    /*
    *   前驱线索
    */
    if (!p->lchild) {
      p->LTag = 1;
      p->lchild = pre;
    }

    /*
    *   后继线索
    */
    if (!pre->rchild) {
      pre->RTag = 1;
      pre->rchild = p;
    }

    // 右子树线索化
    pre = p;
    InThreading(p->rchild);
  }
}

// 二叉排序树

// 递归算法
BiTree SearchBST(BiTree b, KeyType key) {
  if (!b)
    return NULL;
  else if (key == b->key) // 查找成功
    return b;
  else if (key < b->key)
    return SearchBST(b->lchild, key); // 左子树中继续查找
  else
    return SearchBST(b->rchild, key); // 右子树中继续查找
}

// 非递归算法
BiTree SearchBST(BiTree b, KeyType key) {
  BiTree q = b;

  while (q) {
    if (q->key == k) // 查找成功
      return q;
    if (key < q->data.key)
      q = q->lchild; // 左子树中查找
    else
      q = q->rchild; // 右子树中查找
  }

  return NULL; // 查找失败
}

// 二叉排序树插入
void InsertBST(BiTree &b, KeyType key) {
  BiTree s;

  if (b == NULL) // 递归结束条件
  {
    s = (BiTNode *)malloc(sizeof(BiTNode));
    s->key = key;
    s->lchild = NULL;
    s->rchild = NULL;
    b = s;
  } else if (key < b->key)
    InsertBST(b->lchild, key); // 将s插入左子树
  else if (key > b->key)
    InsertBST(b->rchild, key); // 将s插入右子树
}

// 平衡二叉树

// 哈夫曼树
