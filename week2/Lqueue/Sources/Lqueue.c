/*********************************************
*	The file is used to achieve the functions
*	in header file
*	filename			 : Lqueue.c
*	version				 : 1.0
*	system				 : windows
*	programming language : C
*--------------------------------------------
*	anthor				 : Runyu Chen
*	created date		 : 2022/3/26
*
*********************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Lqueue.h"

char c;		   /* 用来接收getchar的返回值 */

double val ;   /* 用来储存数值的变量一定要声明为全局变量! */
char ch ;
int num;
char str[20];

/* 队列初始化 */
STATUS InitLqueue(Lqueue **queue)
{
	(*queue) = (Lqueue *)malloc(sizeof(Lqueue)); /* 动态分配内存 */
	if ( !(*queue) ) /* 判断内存分配是否成功 */
	{
		printf("队列初始化失败!");
		return FALSE;
	}
	else
	{
		(*queue)->top = (node *)malloc(sizeof(node));
		(*queue)->top->next = NULL;  /* 设置队首往队尾的下一个节点 */
		(*queue)->rear = (*queue)->top;
		(*queue)->length = 0;
		return TRUE;
	}
}

/* 销毁队列 */
STATUS DestroyLqueue(Lqueue **queue)
{
	if ((*queue) != NULL)
	{
		if (isempty((*queue)) == FALSE)
		{
			ClearLqueue((*queue));
		}
		free(*queue);
		*queue = NULL;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/* 清空队列元素但保留队列 */
STATUS ClearLqueue(Lqueue *queue)
{
	node *p = queue->top->next;

	while (p != NULL)
	{
		queue->top->next = p->next;
		free(p);
		p = queue->top->next;
	}

	queue->top->next = queue->rear;
	queue->length = 0;
	return TRUE;
}

/* 判断队列是否为空 */
STATUS isempty(Lqueue *queue)
{
	if (queue == NULL)
	{
		printf("该队列不存在!\n");
		return FALSE;
	}

	if (queue->length == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/* 获得队列长度 */
int GetLength(Lqueue *queue)
{
	if (queue == NULL)
	{
		printf("该队列已被销毁或不存在!\n");
		return FALSE;
	}
	else
	{
		printf("队列的长度为: %d\n", queue->length);
		return queue->length;
	}
}

/* 入队操作 */
STATUS PushLqueue(Lqueue *queue, void *value)
{
	if (queue == NULL)		/* 判断待插入对列是否存在 */
	{
		printf("插入错误!");
		return FALSE;
	}

	node *p = (node *)malloc(sizeof(node));  /* 构造新节点 */
	p->date = value;
	memcpy(p->date, value, 20);
	p->next = NULL;
	
	if (isempty(queue) == TRUE)  /* 判断队列是否为空 */
	{
		queue->top->next = p;
		queue->rear = p;
		(queue->length)++;
	}
	else
	{
		queue->rear->next = p;
		queue->rear = p;
		(queue->length)++;
	}

	return TRUE;
}

STATUS EnLqueue(Lqueue *queue)
{
	if (queue == NULL)
	{
		printf("该队列已被销毁或不存在!\n");
		return FALSE;
	}

	printf("\t1-----double类型\t2-----char类型\n");
	printf("\t3-----int类型   \t4-----string类型\n");
	printf("请输入您想入队的类型: ");
	int choice = 0;
	scanf_s("%d", &choice, sizeof(choice));
	printf("\n");

	while (choice > 4 || choice < 1)
	{
		printf("应该输入1-4之间的整数!\n");
		printf("请重新输入您想入队的类型: ");
		scanf_s("%d", &choice, sizeof(choice));
		printf("\n");
	}


	printf("您想入队的数据为: ");
	c = getchar();
	switch (choice)   /* 为类型数组设置类型常量并读取数值 */
	{
	case 1:
		
		scanf_s("%lf", &val, sizeof(double));
		valuetype[queue->length] = DOUBLE;
		PushLqueue(queue,&val);
		break;

	case 2:
		
		scanf_s("%c", &ch, sizeof(char));
		valuetype[queue->length] = CHAR;
		PushLqueue(queue, &ch);
		break;

	case 3:

		scanf_s("%d", &num, sizeof(int));
		valuetype[queue->length] = INT;
		PushLqueue(queue, &num);
		break;

	case 4:

		printf("只能输入20个字符喔!\n");
		scanf_s("%s", str, 20);
		valuetype[queue->length] = STRING;
		PushLqueue(queue, str);
		break;

	default:
		return FALSE;
	}
	printf("\n");
	return TRUE;
}


/* 出队操作 */
STATUS PopLqueue(Lqueue *queue)   
{
	if (queue == NULL)
	{
		printf("该队列已被销毁或不存在!\n");
		return FALSE;
	}

	if (isempty(queue) == TRUE)
	{
		printf("队列为空,无法进行出队操作.\n");
		return FALSE;
	}
	else
	{
		int t;
		for (t = 0; t < (queue->length); t++)
		{
			valuetype[t] = valuetype[t+1];
		}

		node *p = (node *)malloc(sizeof(node));
		p = queue->top->next;
		queue->top->next = queue->top->next->next; /* 此时top指向头结点 */
		(queue->length)--;
		free(p);

		return TRUE;
	}
}

/* 打印队列节点的数据域 */
void LPrint(void *value, int valuetype) /* valuetype决定打印类型 */
{
	if (valuetype == DOUBLE)
	{
		printf("%.4f ->", *(double *)value); /* 对无类型指针进行强制类型转换 */
	}
	if (valuetype == CHAR)
	{
		printf("%c ->", *(char *)value);
	}
	if (valuetype == INT)
	{
		printf("%d ->", *(int *)value);
	}
	if (valuetype == STRING)
	{
		printf(" %s ->", (char *)value);
	}
}


/* 遍历队列并进行指定的函数操作 */
STATUS TraverseLqueue(const Lqueue *queue, void(*func)(void *value, int valuetype))
{
	if (NULL == queue)
	{
		return FALSE;
	}

	node *p = queue->top->next;
	int iter = 0; /* 用来在储存类型的数组中迭代 */

	while (NULL != p)
	{
		func(p->date, valuetype[iter]);
		iter++;
		p = p->next;
	}

	printf("NULL(队尾)\n");

	return TRUE;
}

/* 得到队首的值 */
STATUS GetHeadLqueue(Lqueue *queue)
{
	if (queue == NULL || isempty(queue) == TRUE)  /* 判断是否存在和是否为空 */
	{
		printf("该队列为空队列或不存在!\n");
		return FALSE;
	}
	else
	{
		printf("队首的值为: \n");
		//void *value = (void *)malloc(sizeof(queue->top->next->date));
		//value = queue->top->next->date;
		LPrint(queue->top->next->date, valuetype[0]);
		return TRUE;
	}
}
