// 第3章 栈、队列和数组

// 栈、队列、数组

// 顺序栈

// 静态分配
#define STACKSIZE 100

struct SqStack {
  SElemType elem[STACKSIZE]; // 用数组存储顺序栈
  int top;                   // 栈顶下标
};
// 一般情况下，非空栈时top始终在栈顶元素的位置

// 动态分配
#define STACK_INIT_SIZE 100   // 栈初始大小
#define STACKSIZEINCREMENT 10 // 栈增长大小

struct SqStack {
  SElemType *base; // 栈底位置
  SElemType *top;  // 栈顶位置
  int stacksize;
};
// 一般情况下，非空栈是top始终在栈顶元素的下一个位置。

// 顺序栈上基本操作的实现

// （1）入栈

// 静态分配
Status Push(SqStack &S, SElemType e) {
  if (S.top == STACKSIZE - 1) // 栈满不能入栈
    return ERROR;
  else {
    /*
    * 重要
    */
    S.elem[++S.top] = e; // top始终在栈顶元素位置
    return OK;
  }
}

// 动态分配
Status Push(SqStack &S, SElemType e) {
  if (S.top - S.base >= S.stacksize) {
    ... // 栈满追加存储空间
  }

  /*
  * 重要
  */
  *S.top++ = e; // top始终在栈顶元素的下一个位置

  return OK;
}

// （2）出栈

// 静态分配
Status Pop(SqStack &s, SElemType &e) {
  if (S.top == -1)
    return ERROR;
  /*
  * 重要
  */
  e = S.elem[S.top--];

  return OK;
}

// 动态分配
Status Pop(SqStack &S, SElemType &e) {
  if (S.top == S.base)
    return ERROR;
  /*
  * 重要
  */
  e = *--S.top;

  return OK;
}

// 链栈
typedef struct StackNode {
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStack;

// 链队列
typedef struct Qnode // 结点类型
{
  QElemType data;
  struct QNode *next;
} Qnode, *QueuePtr;

struct LinkQueue {
  QueuePtr front; // 队头指针
  QueuePtr rear;  // 队尾指针
};

/*
* 重要
*/

// 顺序队列

#define MAXQSIZE 100

struct SeQueue {
  ElemType data[MAXQSIZE]; // 队列元素的存储空间
  int rear, front;         // 队头队尾指针
};
/*
* 设队头指针指向队头元素的前面一个位置，队尾指针指向队尾元素。
*/

// （1）入队
sq->data[++sq->rear] = x;

// （2）出队
x = sq->data[++sq->front];

// 循环队列

/*
*   “假上溢”现象，判断循环队列的“空”和“满”，不能以头指针和尾指针是否相等来确定，一般可以通过以下几种方法：
*   （1）另设一个标志位来区别队列的空和满；
*   （2）设置一个计数器记录队列中元素总数，不仅可以判断空和满，还可以得知队列中元素的个数；
*   （3）少用一个元素的空间，每次入队前测试入队后头尾指针是否会重合，如果会重合就认为队列已满。
*/

#define MAXQSIZE 100

struct SqQueue {
  QElemType *base; // 动态分配存储空间

  int front; // 头指针，若队列不空，指向队头元素
  int rear; // 尾指针，对队列不空，指向队尾元素的下一个元素
};

// 循环队列上基本操作的实现

// （1）入队
Status EnQueue(SqQueue &Q, QElemType e) {
  if ((Q.rear + 1) % MAXQSIZE == Q.front)
    return ERROR;

  /*
  *   重要
  */
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXQSIZE;

  return OK;
}

// （2）出队
Status DeQueue(SqQueue &Q, QElemType &e) {
  if (Q.front == Q.rear)
    return ERROR;

  /*
  *   重要
  */
  e = Q.base[Q.front];
  Q.front = (Q.front + 1) % MAXQSIZE;

  return OK;
}

// （3）循环队列元素个数
(Q.rear - Q.front + MAXQSIZE) % MAXQSIZE
