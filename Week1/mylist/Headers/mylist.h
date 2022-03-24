/*
��ͷ�ļ�Ϊ�Զ����˫������
*/
#ifndef MYLIST_H  /* ��ֹ�ļ����ظ����� */
#define MYLIST_H

#include <iostream>
using namespace std;


template <typename Type> /* ����ģ��ڵ� */
struct pnode
{
public:  /* �ڵ��ں���ֵ�Լ�ָ����һ�ڵ����һ�ڵ��ָ�� */
	Type val;
	pnode<Type>* next;
	pnode<Type>* last;
public:
	pnode() = default; /* Ĭ�Ϲ��캯��,���ڵ㸳ֵ */

	pnode(Type _val)
	{
		val = _val;
		next = last = nullptr;
	}

	pnode(pnode<Type>* node) /* ���ƹ��캯�� */
	{
		val = node->val;
		last = node->last;
		next = node->next;
	}
};

template <typename Type> /* ����ģ��������˫������ṹ */
class mylist
{
private:
	int count; /* �ڵ�����Լ�ͷ�ڵ� */
	pnode<Type>* phead;

private:      /* ��װ���ڲ�ʹ�õ�˽�з��� */
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

	Type pop_front();       /* ɾ��ͷ���֮��ĵ�һ���ڵ� */
	Type pop_back();		/* ɾ�����һ���ڵ� */
	Type Delete(int index);	/*ɾ��ָ��λ�ýڵ�	*/

	int  find(Type value);   /* ����ָ��ֵ������,��δʵ�� */
	int  findindex_mid();    /* �����е�����	*/
	Type back();			 /* �������һ��ֵ	*/
	Type get_val(int index); /* ���������õ�ֵ  */

	void reverse();			/* ��ת				*/
	void change_parity();	/* ��ż����Ԫ�ػ��� */
	bool is_circled();		/* �ж��Ƿ�ɻ�		*/
	void print();
};

template <typename Type>
mylist<Type>::mylist()
{
	count = 0;
	phead = new pnode<Type>();
	phead->last = phead; /* ͷ��㲻������ֵ */
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
		if (getnode(index) == nullptr)   /* ��,�������debug������Сʱ�ŷ���,ʹ��,getnode���ص��ǲ���ĺ�һ���ڵ�,��ΪNULL��ע�� */
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
	if (phead->next != nullptr) /* �ж�ͷָ�����һ�ڵ��Ƿ�Ϊ�� */
	{
		pnode<Type>* node = new pnode<Type>(value); /* ����һ���µĽڵ� */
		node->next = phead->next; 
		node->last = phead; 

		phead->next->last = node;
		phead->next = node;
		count++;
		return true;
	}
	else
	{
		cout << "����Ϊ��,������Ч!" << endl; /* ������ӦΪpush_back() */
		return false;
	}
}

template <typename Type>
bool mylist<Type>::push_back(Type value)
{
	pnode<Type>* node = new pnode<Type>(value);
	pnode<Type>* iter = new pnode<Type>();     /* �������������ָ�� */
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
	if (index<0 || index>count)  /* �ж��±� */
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
pnode<Type>* mylist<Type>::getnode(int index) /* �����±�,�õ��ڵ� */
{
	if (index<0 || index>count)
	{
		cout << "��������! ������������Χ��." << endl;
		return nullptr;
	}
	else
	{
		int i = 0;
		pnode<Type>* iter = phead;   /* �õ���������ָ��,����ֻ�赥�����,����ֻ������nextָ�� */
		while (i <= index)  /* ������Ϊ0������Ϊͷ�ڵ����һ�ڵ� */
		{
			iter = iter->next;
			i++;
		}
		return iter;
	}
}

template <typename Type>
void mylist<Type>::print() /* ��ӡ���� */
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
void mylist<Type>::reverse()  /* ��ת˫������,�����˺ܾ�,����˺ܶ��bug�ŵ���ʵ��,����,��ֽ�ͱ�debug���Ҳ����Ҫ */
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
int mylist<Type>::findindex_mid() /* �ҵ��е� */
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
bool mylist<Type>::is_circled() /* �ж�˫�������Ƿ��л�,fast��slow,�ֱ�ͬʱ��ǰ����ʹӺ���ǰ�ƶ� */
{
	pnode<Type>* fast;
	pnode<Type>* slow;
	fast = slow = phead;
	bool front = false, behind = false; /* ��ǰ����ʹӺ���ǰ */
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
	return front && behind;  /* ������� */
}

template <typename Type>
void mylist<Type>::change_parity()
{

}

#endif