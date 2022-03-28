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

/* 初始化链栈 */
STATUS InitLstack(Linkstack *s);


/* 判断栈是否为空 */
STATUS isempty(Linkstack *s);

/* 得到栈顶元素 */
STATUS GetTop(Linkstack *s, Type *e); 

/* 清空栈 */
STATUS ClearLstack(Linkstack *s);

/* 销毁栈 */
STATUS DestroyLstack(Linkstack **s);

/* 检测栈长度 */
STATUS GetLength(Linkstack *s);

/* 入栈 */
STATUS PushLstack(Linkstack *s, Type val);

/* 出栈 */
STATUS PopLstack(Linkstack *s, Type *value);

/* 打印栈 */
STATUS Print(Linkstack *s);

#endif /* LINKSTACK_H_ */
