/*********************************
* FileName		:	BiTree.cpp
* Author		:	Chen Runyu
* Revision time :	2022/4/10
* ---------Introduce-------------
* ����������ADTͷ�ļ���ʵ�ֲ���
*********************************/

#include <iostream>
#include <queue>
#include <stack>
#include "BiTree.h"

using namespace std;


template <typename Type>
BiTree<Type>::BiTree()
{
	root = nullptr;
}

template <typename Type>
BiTree<Type>::~BiTree()
{
	destroytree(root);
}

template <typename Type>
void BiTree<Type>::Insert(Type _val) // Ѱ�Ҳ���λ�ò���������
{
	BiNode<Type> *preNode = nullptr; // �����������ڵĽڵ����һ���ڵ�,��˫�׽ڵ�
	BiNode<Type> *pNode = root;		 // ���ڵĽڵ�

	while (pNode != nullptr)
	{
		preNode = pNode;
		if (_val < pNode->val)
		{
			pNode = pNode->lchild;
		}
		else if (_val > pNode->val)
		{
			pNode = pNode->rchild;
		}
		else
			break;
	}

	BiNode<Type> *newNode = new BiNode<Type>(_val);

	// ִ�в������
	if (preNode == nullptr)
	{
		root = newNode;
	}
	else
	{
		if (_val < preNode->val)
		{
			preNode->lchild = newNode;
		}
		else if (_val > preNode->val)
		{
			preNode->rchild = newNode;
		}
	}
	newNode->parent = preNode;

}

// ��������ӡ������
template <typename Type>
void BiTree<Type>::PreTraver()
{
	cout << endl;
	cout << "ǰ�����Ϊ:" << endl;
	preTraver(root);
}

template <typename Type>
void BiTree<Type>::MidTraver()
{
	cout << endl;
	cout << "�������Ϊ:" << endl;
	midTraver(root);
}

template <typename Type>
void BiTree<Type>::BehTraver()
{
	cout << endl;
	cout << "�������Ϊ:" << endl;
	behTraver(root);
}

template <typename Type>
void BiTree<Type>::LevelTraver()
{
	cout << endl;
	cout << "�������Ϊ:" << endl;
	levelTraver(root);
}

template <typename Type>
void BiTree<Type>::NodeCount() // ����ڵ����
{
	int n = NodeCount(this->root);
	cout << endl;
	cout << "�ڵ����Ϊ: " << n;
}

template <typename Type>
void BiTree<Type>::LeafCount()
{
	int n = LeafCount(this->root);
	cout << endl;
	cout << "���ڵ�ĸ���Ϊ:" << n;
}

template <typename Type>
void BiTree<Type>::Destroytree()
{
	cout << "�������!";
	destroytree(root);
	cout << endl;
}

template <typename Type>
void BiTree<Type>::DeleteNode(Type _val)
{
	DeleteNode(root, _val);
	cout << endl;
}

template <typename Type>
void BiTree<Type>::Search(Type _val)  // ����ָ���ڵ��Ƿ����
{
	if (search(root, _val) == false)
	{
		cout << "���в����������!" << endl;
	}
	else if (search(root, _val) == true)
	{
		cout << "���д��������." << endl;
	}
}

// ������˽�з�����ʵ��

template <typename Type>
void BiTree<Type>::preTraver(BiNode<Type> *p) // ǰ�����,���ݹ���ø�����
{
	if (p != nullptr)
	{
		cout << p->val << " ";
		preTraver(p->lchild);
		preTraver(p->rchild);
	}
}

template <typename Type>
void BiTree<Type>::midTraver(BiNode<Type> *p) // �������,�������
{
	if (p != nullptr)
	{
		preTraver(p->lchild);
		cout << p->val << " ";
		preTraver(p->rchild);
	}
}

template <typename Type>
void BiTree<Type>::behTraver(BiNode<Type> *p) // �������,�����Ҹ�
{
	if (p != nullptr)
	{
		preTraver(p->lchild);
		preTraver(p->rchild);
		cout << p->val << " ";
	}
}

template <typename Type>
void BiTree<Type>::preTraverI(BiNode<Type> *p)  // ǰ�����,�ǵݹ�
{
	if (p == nullptr)
	{
		cout << "����������!" << endl;
	}
	stack<BiNode<Type> *>s;
	BiNode<Type> *temp;
	s.push(p);
	while (s.empty() == false)
	{
		temp = s.top();
		cout << " " << temp->val << " ";
		s.pop();
		if (temp->lchild != nullptr)
		{
			s.push(temp->lchild);
		}
		if (temp->rchild != nullptr)
		{
			s.push(temp->rchild);
		}
	}
	cout << endl;
}

template <typename Type>
void BiTree<Type>::midTraverI(BiNode<Type> *p)  // �������,�ǵݹ�
{
	if (p == nullptr)
	{
		cout << "����������!" << endl;
	}
	else
	{
		stack<BiNode<Type> *>s;
		BiNode<Type> *temp = p;
		while (s.empty() != true || temp != nullptr)
		{
			if (temp != nullptr)
			{
				s.push(temp->val);
				temp = temp->lchild;
			}
			else
			{
				temp = s.top();
				cout << temp->val << " ";
				s.pop();
				temp = temp->rchild;
			}
		}
	}
	cout << endl;
}

template <typename Type>
void BiTree<Type>::behTraverI(BiNode<Type> *p)  // �������,�ǵݹ�,����˫ջʵ��
{
	if (p == nullptr)
	{
		cout << "����������!" << endl;
	}
	else
	{
		stack<BiNode<Type> *> s1, s2;
		BiNode<Type> *temp;
		s1.push(p);
		while (s1.empty() != true)
		{
			temp = s1.top();
			s2.push(temp);     // ����������ջ֮��ת��
			s1.pop();
			if (temp->lchild != nullptr)
			{
				s1.push(temp->lchild);
				
			}
			if (temp->rchild != nullptr)
			{
				s1.push(temp->rchild);
			}
		}
		while (!s2.empty())
		{
			cout << s2.top()->val << " ";
			s2.pop();
		}
	}
	cout << endl;
}

template <typename Type>
void BiTree<Type>::levelTraver(BiNode<Type> *p)   // �������
{
	if (p == nullptr)
	{
		cout << "����Ϊ����!" << endl;
	}
	else
	{
		queue<BiNode<Type> *>q;
		BiNode<Type> *temp;
		q.push(p);
		while (q.empty() == false)
		{
			temp = q.front();
			cout << temp->val << " ";
			if (temp->lchild != nullptr)
			{
				q.push(temp->lchild);
			}
			if (temp->rchild != nullptr)
			{
				q.push(temp->rchild);
			}
			q.pop();
		}
	}
}

template <typename Type>
int BiTree<Type>::NodeCount(BiNode<Type> *p) // ʹ�õݹ����ڵ����
{

	if (p == nullptr)
		return 0;

	int lnum = NodeCount(p->lchild);
	int rnum = NodeCount(p->rchild);
	int num = lnum + rnum + 1;  // ���ϸ��ڵ�

	return num;
}

template <typename Type>
int BiTree<Type>::LeafCount(BiNode<Type> *p) // Ҷ�ӽڵ�ĸ���
{
	if (p == nullptr)
	{
		return 0;
	}
	else if (p->lchild == nullptr && p->rchild == nullptr)
	{
		return 1;
	}
	else
	{
		int rnum = LeafCount(p->rchild);
		int lnum = LeafCount(p->lchild);
		int num = rnum + lnum;
		return num;
	}
}

template <typename Type>
void BiTree<Type>::destroytree(BiNode<Type> *&p) // ȷ��ɾ������p����
{
	if (p != nullptr)
	{
		if (p->lchild != nullptr) destroytree(p->lchild);
		if (p->rchild != nullptr) destroytree(p->rchild);
	}
	delete p;
	p = nullptr;
}

template <typename Type>
void BiTree<Type>::DeleteNode(BiNode<Type> *pNode, Type _val) // ɾ��ָ���ڵ�,�������
{
	if (search(this->root,_val) == true)
	{
		if (pNode != nullptr)
		{
			if (pNode->val == _val)
			{
				BiNode<Type> *deleNode = nullptr;
				if (pNode->lchild == nullptr || pNode->rchild == nullptr) // ֻ��һ�����ӻ�û�к���
				{
					deleNode = pNode;
				}
				else // ����������
				{
					deleNode = frontNode(pNode);
				}
				BiNode<Type> *childNode = nullptr; // ���ӽڵ�,���������ɾ�ڵ�ĺ��ӽڵ�

				if (pNode->lchild != nullptr)
				{
					childNode = deleNode->lchild;
				}
				else if (pNode->rchild == nullptr)
				{
					childNode = deleNode->rchild;
				}
				// ���ú��ӽڵ��˫��
				if (childNode != nullptr)
					childNode->parent = deleNode->parent;
				// ���ô�ɾ�ڵ��˫�׽ڵ�ָ���ӽڵ�
				if (deleNode->parent == nullptr)
				{
					root = childNode;
				}
				else if (deleNode->parent->lchild == deleNode)
				{
					childNode->parent->lchild = childNode;
				}
				else
				{
					childNode->parent->rchild = childNode;
				}
				// ִ��ɾ���ڵ����
				if (deleNode->val != pNode->val)
					pNode->val = deleNode->val;
				delete deleNode; // ɾ��һ���ڵ�struct

			}
			// �ݹ�ɾ��
			else if (pNode->val > _val)
			{
				DeleteNode(pNode->lchild, _val);
			}
			else if (pNode->val < _val)
			{
				DeleteNode(pNode->rchild, _val);
			}
		}
		cout << "�ѳɹ�ɾ��!";
	}
	else
	{
		cout << "�����ڸ���!";
	}
}

template <typename Type>
BiNode<Type> *BiTree<Type>::frontNode(BiNode<Type> *pNode) // Ѱ�����������ǰ���ڵ�
{
	if (pNode->lchild != nullptr)
	{
		pNode = pNode->lchild;
		if (pNode->rchild != nullptr)
		{
			pNode = pNode->rchild;
			return pNode;
		}
	}
	BiNode<Type> *parentNode = pNode->parent;
	while (parentNode != nullptr && pNode == parentNode->rchild)
	{
		pNode = parentNode;
		parentNode = parentNode->parent; // �ҵ���һ������������˫�׽ڵ�
	}
	return parentNode;
}

template <typename Type>
BiNode<Type> *BiTree<Type>::behindNode(BiNode<Type> *pNode) // Ѱ����������ĺ�̽ڵ�
{
	if (pNode->rchild != nullptr)
	{
		pNode = pNode->rchild;
		if (pNode->lchild != nullptr)
		{
			pNode = pNode->lchild;
			return pNode;
		}
	}
	BiNode<Type> *parentNode = pNode->parent;
	while (parentNode != nullptr && pNode == parentNode->lchild)
	{
		pNode = parentNode;
		parentNode = parentNode->parent;//�ҵ���һ������������˫�׽ڵ�
	}
	return parentNode;
}

template <typename Type>
void BiTree<Type>::CopyTree(BiNode<Type> *p)
{
	if (p == nullptr)
	{
		root = nullptr;
	}
	else
	{
		root->val = p->val;
	}
	if (nullptr != p->lchild)
	{
		root->lchild = new BiNode<Type>*(0);
	}
	if (nullptr != p->rchild)
	{
		root->rchild = new BiNode<Type>*(0);
	}

}

template <typename Type>
bool BiTree<Type>::search(BiNode<Type> *&p,Type _val)
{
	if (p == nullptr)
	{
		return false;
	}
	if (p->val == _val)
	{
		return true;
	}
	else if (p->val > _val)
	{
		return search(p->lchild, _val);  // β�ݹ�
	}
	else
	{
		return search(p->rchild, _val);
	}
}