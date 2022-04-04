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

/* ��ʼ����ջ */
STATUS InitLstack(Linkstack *s)
{
	if (!s)
	{
		printf("\t����ջ������!\n");
		return FALSE;
	}
	else
	{
		s->top = (Node *)malloc(sizeof(Node));
		if (!s->top)
		{
			return FALSE;
		}

		s->top = NULL;  /* ��һ������Ҫ */
		s->count = 0;

		return TRUE;
	}
}

/* �ж�ջ�Ƿ�Ϊ�� */
STATUS isempty(Linkstack *s)
{
	if (s == NULL)
	{
		printf("\t��ջ������!");
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

/* �õ�ջ��Ԫ�� */
STATUS GetTop(Linkstack *s, Type *e) /* ��ջ��Ϊ��,����e����s��ջ��Ԫ�� */
{
	if (s == NULL || s->top == NULL)
	{
		printf("\t��ջ������!\n");
		return FALSE;
	}
	else
	{
		*e = s->top->date;
		return TRUE;
	}
}

/* ���ջ���� */
STATUS GetLength(Linkstack *s)
{
	if (NULL == s)
	{
		printf("\t����ջ������!\n");
		return FALSE;
	}
	else
	{
		printf("\t��ջ�ĳ���Ϊ: %d", s->count);
		return TRUE;
	}
}

/* ��ջ */
STATUS PushLstack(Linkstack *s, Type val)
{
	if (NULL == s)
	{
		printf("\t����ջ������!\n");
		return FALSE;
	}
	else
	{
		Node *pnode = (Node *)malloc(sizeof(Node));
		pnode->date = val;
		pnode->next = s->top;  /* ��ԭ�е�top�ڵ���Ϊ�½ڵ�ĺ�� */
		s->top = pnode;
		s->count++;
		flag = 1;

		return TRUE;
	}
}

/* ��ջ */
STATUS PopLstack(Linkstack *s, Type *value) /* ����valueָ��,��Ϊvalue��ֵ�����ı� */
{
	if (isempty(s) == TRUE)
	{
		printf("\t����ջΪ����ջ!\n");
		return FALSE;
	}
	else
	{
		Node *pnode = (Node *)malloc(sizeof(Node));
		(*value) = s->top->date;  /* ��¼ջ����ֵ				*/
		pnode = s->top;			  /* ��topָ��Ľڵ㽻��pnoed	*/
		s->top = s->top->next;	  /* topָ������				*/
		free(pnode);			  /* �ͷų�ջ�ڵ�				*/
		s->count--;				  /* ��������һ					*/

		return TRUE;
	}
}

/* ���ջ */
STATUS ClearLstack(Linkstack *s)
{
	if (NULL == s)
	{
		printf("\t����ջ������!\n");
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


/* ����ջ */
STATUS DestroyLstack(Linkstack *s)
{
	if (NULL == s)
	{
		printf("\t����ջ������!\n");
		return FALSE;
	}
	
	if (ClearLstack(s) == TRUE)   /* �жϲ������ջ */
	{
		free(s->top);
		flag = 0;
	}
	
	return TRUE;
}

/* ��ӡջ */
STATUS PrintInt(Linkstack *s)  /* �ú������ԶԴ���int��ֵ����ջ���д�ӡ */
{
	if (NULL == s)
	{
		printf("\t����ջ������!\n");
		return FALSE;
	}

	if (flag == 0)
	{
		printf("\t����ջ�ѱ�����!\n");
		return FALSE;
	}

	Node *pnode = (Node *)malloc(sizeof(Node));
	pnode = s->top;
	printf("\tջ��\n\t");
	while (NULL != pnode)
	{
		printf("%d--> ", pnode->date);
		pnode = pnode->next;
	}
	printf("NULL");
	printf("\n");

	return TRUE;
}