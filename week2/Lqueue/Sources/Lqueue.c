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

char c;		   /* ��������getchar�ķ���ֵ */

double val ;   /* ����������ֵ�ı���һ��Ҫ����Ϊȫ�ֱ���! */
char ch ;
int num;
char str[20];

/* ���г�ʼ�� */
STATUS InitLqueue(Lqueue **queue)
{
	(*queue) = (Lqueue *)malloc(sizeof(Lqueue)); /* ��̬�����ڴ� */
	if ( !(*queue) ) /* �ж��ڴ�����Ƿ�ɹ� */
	{
		printf("���г�ʼ��ʧ��!");
		return FALSE;
	}
	else
	{
		(*queue)->top = (node *)malloc(sizeof(node));
		(*queue)->top->next = NULL;  /* ���ö�������β����һ���ڵ� */
		(*queue)->rear = (*queue)->top;
		(*queue)->length = 0;
		return TRUE;
	}
}

/* ���ٶ��� */
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

/* ��ն���Ԫ�ص��������� */
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

/* �ж϶����Ƿ�Ϊ�� */
STATUS isempty(Lqueue *queue)
{
	if (queue == NULL)
	{
		printf("�ö��в�����!\n");
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

/* ��ö��г��� */
int GetLength(Lqueue *queue)
{
	if (queue == NULL)
	{
		printf("�ö����ѱ����ٻ򲻴���!\n");
		return FALSE;
	}
	else
	{
		printf("���еĳ���Ϊ: %d\n", queue->length);
		return queue->length;
	}
}

/* ��Ӳ��� */
STATUS PushLqueue(Lqueue *queue, void *value)
{
	if (queue == NULL)		/* �жϴ���������Ƿ���� */
	{
		printf("�������!");
		return FALSE;
	}

	node *p = (node *)malloc(sizeof(node));  /* �����½ڵ� */
	p->date = value;
	memcpy(p->date, value, 20);
	p->next = NULL;
	
	if (isempty(queue) == TRUE)  /* �ж϶����Ƿ�Ϊ�� */
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
		printf("�ö����ѱ����ٻ򲻴���!\n");
		return FALSE;
	}

	printf("\t1-----double����\t2-----char����\n");
	printf("\t3-----int����   \t4-----string����\n");
	printf("������������ӵ�����: ");
	int choice = 0;
	scanf_s("%d", &choice, sizeof(choice));
	printf("\n");

	while (choice > 4 || choice < 1)
	{
		printf("Ӧ������1-4֮�������!\n");
		printf("����������������ӵ�����: ");
		scanf_s("%d", &choice, sizeof(choice));
		printf("\n");
	}


	printf("������ӵ�����Ϊ: ");
	c = getchar();
	switch (choice)   /* Ϊ���������������ͳ�������ȡ��ֵ */
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

		printf("ֻ������20���ַ��!\n");
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


/* ���Ӳ��� */
STATUS PopLqueue(Lqueue *queue)   
{
	if (queue == NULL)
	{
		printf("�ö����ѱ����ٻ򲻴���!\n");
		return FALSE;
	}

	if (isempty(queue) == TRUE)
	{
		printf("����Ϊ��,�޷����г��Ӳ���.\n");
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
		queue->top->next = queue->top->next->next; /* ��ʱtopָ��ͷ��� */
		(queue->length)--;
		free(p);

		return TRUE;
	}
}

/* ��ӡ���нڵ�������� */
void LPrint(void *value, int valuetype) /* valuetype������ӡ���� */
{
	if (valuetype == DOUBLE)
	{
		printf("%.4f ->", *(double *)value); /* ��������ָ�����ǿ������ת�� */
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


/* �������в�����ָ���ĺ������� */
STATUS TraverseLqueue(const Lqueue *queue, void(*func)(void *value, int valuetype))
{
	if (NULL == queue)
	{
		return FALSE;
	}

	node *p = queue->top->next;
	int iter = 0; /* �����ڴ������͵������е��� */

	while (NULL != p)
	{
		func(p->date, valuetype[iter]);
		iter++;
		p = p->next;
	}

	printf("NULL(��β)\n");

	return TRUE;
}

/* �õ����׵�ֵ */
STATUS GetHeadLqueue(Lqueue *queue)
{
	if (queue == NULL || isempty(queue) == TRUE)  /* �ж��Ƿ���ں��Ƿ�Ϊ�� */
	{
		printf("�ö���Ϊ�ն��л򲻴���!\n");
		return FALSE;
	}
	else
	{
		printf("���׵�ֵΪ: \n");
		//void *value = (void *)malloc(sizeof(queue->top->next->date));
		//value = queue->top->next->date;
		LPrint(queue->top->next->date, valuetype[0]);
		return TRUE;
	}
}
