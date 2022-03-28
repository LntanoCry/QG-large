/*********************************************
*	The header file is used to achieve LQueue
*	filename			 : Lqueue.h
*	version				 : 1.0
*	system				 : windows
*	programming language : C
*--------------------------------------------	
*	anthor				 : Runyu Chen
*	created date		 : 2022/3/26
* 
*********************************************/

#ifndef LQUEUE_H_
#define LQUEUE_H_

#include <stdlib.h>
#include <string.h>

#define TRUE     1
#define FALSE	 0
#define STATUS   int
#define MAXTYPE  30

/* 链式队列的节点定义 */
typedef struct node
{
	void *date;			/* 指针数据域 */
	struct node *next;	/* 指针域	  */
}node;

/* 构建链式队列 */
typedef struct Lqueue
{
	node *top;     /* 指向队首 */
	node *rear;	   /* 指向队尾 */
	int  length;
}Lqueue;

int valuetype[MAXTYPE];  /* 用来储存数据类型 */

enum   /* 定义类型常量 */
{
	DOUBLE = 1,
	CHAR   = 2,
	INT	   = 3,
	STRING = 4,
};

/* 队列初始化 */
STATUS InitLqueue(Lqueue **queue);

/* 销毁队列 */
STATUS DestroyLqueue(Lqueue **queue);

/* 判断队列是否为空 */
STATUS isempty(Lqueue *queue);

/* 入队操作 */
STATUS PushLqueue(Lqueue *queue, void *value);

/* 交互式执行入队 */
STATUS EnLqueue(Lqueue *queue);

/* 出队操作 */
STATUS PopLqueue(Lqueue *queue); 

/* 清空队列 */
STATUS ClearLqueue(Lqueue *queue);

/* 获得队列长度 */
int GetLength(Lqueue *queue);

/* 打印队列节点的数据域 */
void LPrint(void *value, int valuetype);

/* 遍历队列 */
STATUS TraverseLqueue(const Lqueue *queue, void(*func)(void *value,int valuetype)); /* func指要对队列执行的函数操作,有点类似于map */

/* 得到队首的值 */
STATUS GetHeadLqueue(Lqueue *queue); /* e用来储存得到的值 */


#endif  /* LQUEUE_H_ */
