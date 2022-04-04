/*****************************
* @filename		:LinkStack.c
* @version		:1.0
* @author		:Runyu Chen
* @created time	:2022/3/27
*
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

int flag = 0;

/* 初始化链栈 */
STATUS InitLstack(Linkstack *s)
{
	if (!s)
	{
		printf("\t该链栈不存在!\n");
		return FALSE;
	}
	else
	{
		s->top = (Node *)malloc(sizeof(Node));
		if (!s->top)
		{
			return FALSE;
		}

		s->top = NULL;  /* 这一步很重要 */
		s->count = 0;

		return TRUE;
	}
}

/* 判断栈是否为空 */
STATUS isempty(Linkstack *s)
{
	if (s == NULL)
	{
		printf("\t链栈不存在!");
		return;
	}
	else if (s->count == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/* 得到栈顶元素 */
STATUS GetTop(Linkstack *s, Type *e) /* 若栈不为空,则用e返回s的栈顶元素 */
{
	if (s == NULL || s->top == NULL)
	{
		printf("\t链栈不存在!\n");
		return FALSE;
	}
	else
	{
		*e = s->top->date;
		return TRUE;
	}
}

/* 检测栈长度 */
STATUS GetLength(Linkstack *s)
{
	if (NULL == s)
	{
		printf("\t该链栈不存在!\n");
		return FALSE;
	}
	else
	{
		printf("\t该栈的长度为: %d", s->count);
		return TRUE;
	}
}

/* 入栈 */
STATUS PushLstack(Linkstack *s, Type val)
{
	if (NULL == s)
	{
		printf("\t该链栈不存在!\n");
		return FALSE;
	}
	else
	{
		Node *pnode = (Node *)malloc(sizeof(Node));
		pnode->date = val;
		pnode->next = s->top;  /* 将原有的top节点设为新节点的后继 */
		s->top = pnode;
		s->count++;
		flag = 1;

		return TRUE;
	}
}

/* 出栈 */
STATUS PopLstack(Linkstack *s, Type *value) /* 传入value指针,因为value的值发生改变 */
{
	if (isempty(s) == TRUE)
	{
		printf("\t该链栈为空链栈!\n");
		return FALSE;
	}
	else
	{
		Node *pnode = (Node *)malloc(sizeof(Node));
		(*value) = s->top->date;  /* 记录栈顶的值				*/
		pnode = s->top;			  /* 将top指向的节点交给pnoed	*/
		s->top = s->top->next;	  /* top指针下移				*/
		free(pnode);			  /* 释放出栈节点				*/
		s->count--;				  /* 计数器减一					*/

		return TRUE;
	}
}

/* 清空栈 */
STATUS ClearLstack(Linkstack *s)
{
	if (NULL == s)
	{
		printf("\t该链栈不存在!\n");
		return FALSE;
	}


	Node *pnode = (Node *)malloc(sizeof(Node));
	pnode = s->top;
	while (pnode != NULL)
	{
		s->top = s->top->next;
		free(pnode);
		pnode = s->top;
	}
	s->count = 0;
	return TRUE;
}


/* 销毁栈 */
STATUS DestroyLstack(Linkstack *s)
{
	if (NULL == s)
	{
		printf("\t该链栈不存在!\n");
		return FALSE;
	}
	
	if (ClearLstack(s) == TRUE)   /* 判断并清空链栈 */
	{
		free(s->top);
		flag = 0;
	}
	
	return TRUE;
}

/* 打印栈 */
STATUS PrintInt(Linkstack *s)  /* 该函数可以对储存int数值的链栈进行打印 */
{
	if (NULL == s)
	{
		printf("\t该链栈不存在!\n");
		return FALSE;
	}

	if (flag == 0)
	{
		printf("\t该链栈已被销毁!\n");
		return FALSE;
	}

	Node *pnode = (Node *)malloc(sizeof(Node));
	pnode = s->top;
	printf("\t栈顶\n\t");
	while (NULL != pnode)
	{
		printf("%d--> ", pnode->date);
		pnode = pnode->next;
	}
	printf("NULL");
	printf("\n");

	return TRUE;
}