/*
该头文件为自定义的双向链表
*/
#ifndef MYLIST_H  /* 防止文件被重复包含 */
#define MYLIST_H

#include <iostream>
using namespace std;


template <typename Type> /* 生成模板节点 */
struct pnode
{
public:  /* 节点内含数值以及指向上一节点和下一节点的指针 */
	Type val;
	pnode<Type>* next;
	pnode<Type>* last;
public:
	pnode() = default; /* 默认构造函数,给节点赋值 */

	pnode(Type _val)
	{
		val = _val;
		next = last = nullptr;
	}

	pnode(pnode<Type>* node) /* 复制构造函数 */
	{
		val = node->val;
		last = node->last;
		next = node->next;
	}
};

template <typename Type> /* 利用模板类生成双向链表结构 */
class mylist
{
private:
	int count; /* 节点个数以及头节点 */
	pnode<Type>* phead;

private:      /* 封装给内部使用的私有方法 */
	pnode<Type>* getnode(int index); 

public:
	mylist();
	~mylist();

	int size()
	{
		return count;
	}

	bool isempty()
	{
		return count == 0;
	}

	bool insert(int index, Type value);
	bool push_front(Type value);
	bool push_back(Type value);

	Type pop_front();       /* 删除头结点之外的第一个节点 */
	Type pop_back();		/* 删除最后一个节点 */
	Type Delete(int index);	/*删除指点位置节点	*/

	int  find(Type value);   /* 返回指定值的索引,还未实现 */
	int  findindex_mid();    /* 返回中点索引	*/
	Type back();			 /* 返回最后一个值	*/
	Type get_val(int index); /* 根据索引得到值  */

	void reverse();			/* 反转				*/
	void change_parity();	/* 奇偶索引元素互换 */
	bool is_circled();		/* 判断是否成环		*/
	void print();
};

template <typename Type>
mylist<Type>::mylist()
{
	count = 0;
	phead = new pnode<Type>();
	phead->last = phead; /* 头结点不储存数值 */
	phead->next = nullptr;
}

template <typename Type>
mylist<Type>::~mylist(){}

template <typename Type>
bool mylist<Type>::insert(int index, Type value)
{
	if (index == 0)
	{
		if (phead->next == nullptr)
		{
			this->push_back(value);
			count++;
			return true;
		}
		else
		{
			this->push_front(value);
			count++;
			return true;
		}
	}
	else if(index != 0)
	{
		if (getnode(index) == nullptr)   /* 哎,这个错误debug了三个小时才发现,痛苦,getnode返回的是插入的后一个节点,若为NULL需注意 */
		{										
			this->push_back(value);
		}
		else
		{
			pnode<Type>* piter = getnode(index);
			pnode<Type>* node = new pnode<Type>(value);

			node->next = piter;
			node->last = piter->last;

			piter->last->next = node;
			piter->last = node;
			count++;
			return true;
		}
	}
	else
		return false;
}

template <typename Type>
bool mylist<Type>::push_front(Type value)
{
	if (phead->next != nullptr) /* 判断头指针的下一节点是否为空 */
	{
		pnode<Type>* node = new pnode<Type>(value); /* 创建一个新的节点 */
		node->next = phead->next; 
		node->last = phead; 

		phead->next->last = node;
		phead->next = node;
		count++;
		return true;
	}
	else
	{
		cout << "链表为空,操作无效!" << endl; /* 空链表应为push_back() */
		return false;
	}
}

template <typename Type>
bool mylist<Type>::push_back(Type value)
{
	pnode<Type>* node = new pnode<Type>(value);
	pnode<Type>* iter = new pnode<Type>();     /* 负责迭代的两个指针 */
	pnode<Type>* preiter = new pnode<Type>(); 
	iter = phead;

	while (iter != nullptr)
	{
		preiter = iter;
		iter = iter->next;
	}
	node->next = iter;
	node->last = preiter;
	preiter->next = node;
	count++;
	return true;
}

template <typename Type>
Type mylist<Type>::get_val(int index)
{
	return getnode(index)->val;
}

template <typename Type>
Type mylist<Type>::back()
{
	return getnode(count - 1)->val;
}

template <typename Type>
Type mylist<Type>::Delete(int index)
{
	if (index<0 || index>count)  /* 判断下标 */
		return 0;
	pnode<Type>* node = getnode(index);
	Type t = node->val;
	node->next->last = node->last;
	node->last->next = node->next;
	delete node;
	count--;
	return t;
}

template <typename Type>
Type mylist<Type>::pop_front()
{
	return Delete(0);
}

template <typename Type>
Type mylist<Type>::pop_back()
{
	return Delete(count - 1);
}

template <typename Type>
pnode<Type>* mylist<Type>::getnode(int index) /* 输入下标,得到节点 */
{
	if (index<0 || index>count)
	{
		cout << "索引错误! 索引不在链表范围内." << endl;
		return nullptr;
	}
	else
	{
		int i = 0;
		pnode<Type>* iter = phead;   /* 用到了许多迭代指针,由于只需单向迭代,所以只需设置next指针 */
		while (i <= index)  /* 把索引为0处定义为头节点的下一节点 */
		{
			iter = iter->next;
			i++;
		}
		return iter;
	}
}

template <typename Type>
void mylist<Type>::print() /* 打印链表 */
{
	int i = 0;
	while (i < count)
	{
		cout << getnode(i)->val << " ";
		i++;
	}
	cout << endl;
}

template <typename Type> 
void mylist<Type>::reverse()  /* 反转双向链表,尝试了很久,解决了很多的bug才得以实现,此外,用纸和笔debug真的也很重要 */
{
	pnode<Type>* cur = phead;
	pnode<Type>* temp  = nullptr;
	pnode<Type>* left  = nullptr;
	pnode<Type>* right = nullptr;
	while (cur != nullptr)
	{
		right = cur->next;
		if (right == nullptr)
		{
			temp = cur;
		}
		cur->next = left;
		cur->last = right;
		left = cur;
		cur = right;
	}
	phead->next = temp;
	temp->last = phead;
}

template <typename Type>
int mylist<Type>::findindex_mid() /* 找到中点 */
{
	if (count % 2 == 0)
	{
		return (count / 2 + 1 / 2) - 1;
	}
	else
	{
		return ((count + 1) / 2) - 1;
	}
}

template <typename Type>
bool mylist<Type>::is_circled() /* 判断双向链表是否有环,fast和slow,分别同时从前往后和从后往前移动 */
{
	pnode<Type>* fast;
	pnode<Type>* slow;
	fast = slow = phead;
	bool front = false, behind = false; /* 从前往后和从后往前 */
	while ((fast != nullptr) && (fast->next != nullptr))
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			front = true;
	}
	fast = slow = getnode(count - 1);
	while (fast != nullptr && fast->last != nullptr)
	{
		fast = fast->last->last;
		slow = slow->last;
		if (slow == fast)
			behind = true;
	}
	return front && behind;  /* 两真才真 */
}

template <typename Type>
void mylist<Type>::change_parity()
{

}

#endif