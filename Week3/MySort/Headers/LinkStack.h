/*****************************
* @filename		:LinkStack.h
* @version		:1.0
* @author		:Runyu Chen
* @created time	:2022/3/27
* 
*****************************/

#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#define TRUE    1
#define FALSE   0
#define STATUS	int
#define Type int



typedef struct Node
{
	Type date;
	struct Node *next;
}Node;

typedef struct Linkstack
{
	Node *top;
	int count;
}Linkstack;

/* ��ʼ����ջ */
STATUS InitLstack(Linkstack *s);


/* �ж�ջ�Ƿ�Ϊ�� */
STATUS isempty(Linkstack *s);

/* �õ�ջ��Ԫ�� */
STATUS GetTop(Linkstack *s, Type *e); 

/* ���ջ */
STATUS ClearLstack(Linkstack *s);

/* ����ջ */
STATUS DestroyLstack(Linkstack **s);

/* ���ջ���� */
STATUS GetLength(Linkstack *s);

/* ��ջ */
STATUS PushLstack(Linkstack *s, Type val);

/* ��ջ */
STATUS PopLstack(Linkstack *s, Type *value);

/* ��ӡջ */
STATUS Print(Linkstack *s);

#endif /* LINKSTACK_H_ */
