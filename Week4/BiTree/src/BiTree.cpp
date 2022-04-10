/*********************************
* FileName		:	BiTree.cpp
* Author		:	Chen Runyu
* Revision time :	2022/4/10
* ---------Introduce-------------
* 二叉排序树ADT头文件的实现部分
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
void BiTree<Type>::Insert(Type _val) // 寻找插入位置并插入数据
{
	BiNode<Type> *preNode = nullptr; // 用来保存现在的节点的上一个节点,即双亲节点
	BiNode<Type> *pNode = root;		 // 现在的节点

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

	// 执行插入操作
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

// 遍历并打印二叉树
template <typename Type>
void BiTree<Type>::PreTraver()
{
	cout << endl;
	cout << "前序遍历为:" << endl;
	preTraver(root);
}

template <typename Type>
void BiTree<Type>::MidTraver()
{
	cout << endl;
	cout << "中序遍历为:" << endl;
	midTraver(root);
}

template <typename Type>
void BiTree<Type>::BehTraver()
{
	cout << endl;
	cout << "后序遍历为:" << endl;
	behTraver(root);
}

template <typename Type>
void BiTree<Type>::LevelTraver()
{
	cout << endl;
	cout << "层序遍历为:" << endl;
	levelTraver(root);
}

template <typename Type>
void BiTree<Type>::NodeCount() // 计算节点个数
{
	int n = NodeCount(this->root);
	cout << endl;
	cout << "节点个数为: " << n;
}

template <typename Type>
void BiTree<Type>::LeafCount()
{
	int n = LeafCount(this->root);
	cout << endl;
	cout << "树节点的个数为:" << n;
}

template <typename Type>
void BiTree<Type>::Destroytree()
{
	cout << "树已清空!";
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
void BiTree<Type>::Search(Type _val)  // 查找指定节点是否存在
{
	if (search(root, _val) == false)
	{
		cout << "树中不存在这个数!" << endl;
	}
	else if (search(root, _val) == true)
	{
		cout << "树中存在这个数." << endl;
	}
}

// 以下是私有方法的实现

template <typename Type>
void BiTree<Type>::preTraver(BiNode<Type> *p) // 前序遍历,即递归调用根左右
{
	if (p != nullptr)
	{
		cout << p->val << " ";
		preTraver(p->lchild);
		preTraver(p->rchild);
	}
}

template <typename Type>
void BiTree<Type>::midTraver(BiNode<Type> *p) // 中序遍历,即左根右
{
	if (p != nullptr)
	{
		preTraver(p->lchild);
		cout << p->val << " ";
		preTraver(p->rchild);
	}
}

template <typename Type>
void BiTree<Type>::behTraver(BiNode<Type> *p) // 后序遍历,即左右根
{
	if (p != nullptr)
	{
		preTraver(p->lchild);
		preTraver(p->rchild);
		cout << p->val << " ";
	}
}

template <typename Type>
void BiTree<Type>::preTraverI(BiNode<Type> *p)  // 前序遍历,非递归
{
	if (p == nullptr)
	{
		cout << "该树不存在!" << endl;
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
void BiTree<Type>::midTraverI(BiNode<Type> *p)  // 中序遍历,非递归
{
	if (p == nullptr)
	{
		cout << "该树不存在!" << endl;
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
void BiTree<Type>::behTraverI(BiNode<Type> *p)  // 后序遍历,非递归,利用双栈实现
{
	if (p == nullptr)
	{
		cout << "该树不存在!" << endl;
	}
	else
	{
		stack<BiNode<Type> *> s1, s2;
		BiNode<Type> *temp;
		s1.push(p);
		while (s1.empty() != true)
		{
			temp = s1.top();
			s2.push(temp);     // 数据在左右栈之间转移
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
void BiTree<Type>::levelTraver(BiNode<Type> *p)   // 层序遍历
{
	if (p == nullptr)
	{
		cout << "该树为空树!" << endl;
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
int BiTree<Type>::NodeCount(BiNode<Type> *p) // 使用递归计算节点个数
{

	if (p == nullptr)
		return 0;

	int lnum = NodeCount(p->lchild);
	int rnum = NodeCount(p->rchild);
	int num = lnum + rnum + 1;  // 加上根节点

	return num;
}

template <typename Type>
int BiTree<Type>::LeafCount(BiNode<Type> *p) // 叶子节点的个数
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
void BiTree<Type>::destroytree(BiNode<Type> *&p) // 确保删除的是p本身
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
void BiTree<Type>::DeleteNode(BiNode<Type> *pNode, Type _val) // 删除指定节点,三种情况
{
	if (search(this->root,_val) == true)
	{
		if (pNode != nullptr)
		{
			if (pNode->val == _val)
			{
				BiNode<Type> *deleNode = nullptr;
				if (pNode->lchild == nullptr || pNode->rchild == nullptr) // 只有一个孩子或没有孩子
				{
					deleNode = pNode;
				}
				else // 有两个孩子
				{
					deleNode = frontNode(pNode);
				}
				BiNode<Type> *childNode = nullptr; // 孩子节点,用来保存待删节点的孩子节点

				if (pNode->lchild != nullptr)
				{
					childNode = deleNode->lchild;
				}
				else if (pNode->rchild == nullptr)
				{
					childNode = deleNode->rchild;
				}
				// 设置孩子节点的双亲
				if (childNode != nullptr)
					childNode->parent = deleNode->parent;
				// 设置待删节点的双亲节点指向孩子节点
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
				// 执行删除节点操作
				if (deleNode->val != pNode->val)
					pNode->val = deleNode->val;
				delete deleNode; // 删除一个节点struct

			}
			// 递归删除
			else if (pNode->val > _val)
			{
				DeleteNode(pNode->lchild, _val);
			}
			else if (pNode->val < _val)
			{
				DeleteNode(pNode->rchild, _val);
			}
		}
		cout << "已成功删除!";
	}
	else
	{
		cout << "不存在该数!";
	}
}

template <typename Type>
BiNode<Type> *BiTree<Type>::frontNode(BiNode<Type> *pNode) // 寻找中序遍历的前驱节点
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
		parentNode = parentNode->parent; // 找到第一个有右子树的双亲节点
	}
	return parentNode;
}

template <typename Type>
BiNode<Type> *BiTree<Type>::behindNode(BiNode<Type> *pNode) // 寻找中序遍历的后继节点
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
		parentNode = parentNode->parent;//找到第一个有左子树的双亲节点
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
		return search(p->lchild, _val);  // 尾递归
	}
	else
	{
		return search(p->rchild, _val);
	}
}