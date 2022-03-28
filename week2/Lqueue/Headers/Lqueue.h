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

/* ��ʽ���еĽڵ㶨�� */
typedef struct node
{
	void *date;			/* ָ�������� */
	struct node *next;	/* ָ����	  */
}node;

/* ������ʽ���� */
typedef struct Lqueue
{
	node *top;     /* ָ����� */
	node *rear;	   /* ָ���β */
	int  length;
}Lqueue;

int valuetype[MAXTYPE];  /* ���������������� */

enum   /* �������ͳ��� */
{
	DOUBLE = 1,
	CHAR   = 2,
	INT	   = 3,
	STRING = 4,
};

/* ���г�ʼ�� */
STATUS InitLqueue(Lqueue **queue);

/* ���ٶ��� */
STATUS DestroyLqueue(Lqueue **queue);

/* �ж϶����Ƿ�Ϊ�� */
STATUS isempty(Lqueue *queue);

/* ��Ӳ��� */
STATUS PushLqueue(Lqueue *queue, void *value);

/* ����ʽִ����� */
STATUS EnLqueue(Lqueue *queue);

/* ���Ӳ��� */
STATUS PopLqueue(Lqueue *queue); 

/* ��ն��� */
STATUS ClearLqueue(Lqueue *queue);

/* ��ö��г��� */
int GetLength(Lqueue *queue);

/* ��ӡ���нڵ�������� */
void LPrint(void *value, int valuetype);

/* �������� */
STATUS TraverseLqueue(const Lqueue *queue, void(*func)(void *value,int valuetype)); /* funcָҪ�Զ���ִ�еĺ�������,�е�������map */

/* �õ����׵�ֵ */
STATUS GetHeadLqueue(Lqueue *queue); /* e��������õ���ֵ */


#endif  /* LQUEUE_H_ */
