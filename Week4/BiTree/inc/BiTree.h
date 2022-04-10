/*********************************
* FileName		:	BiTree.h
* Author		:	Chen Runyu
* Revision time :	2022/4/10
* ---------Introduce-------------
* 二叉排序树ADT
*********************************/

#ifndef BITREE_H_
#define BITREE_H_

#define true  1
#define false 0

#include <iostream>

using namespace std;

// 树节点的定义
template <typename Type>
struct BiNode
{
	Type val;
	BiNode<Type>* rchild;   // 右孩子
	BiNode<Type>* lchild;	// 左孩子
	BiNode<Type>* parent;	// 双亲节点

	BiNode(Type T):val(T),rchild(nullptr),lchild(nullptr),parent(nullptr) // 结构体初始化
	{  }

	BiNode() = default;     // 使用默认初始化
	
};



// 二叉排序树的定义
template <typename Type>
class BiTree
{

public:   // 提供供用户使用的接口

	BiTree();   // 构造函数
	~BiTree();  // 析构函数

	void Insert(Type _val);   // 插入节点

	void PreTraver();		  // 前序遍历,递归

	void MidTraver();		  // 中序遍历,递归

	void BehTraver();		  // 后序遍历,递归

	void LevelTraver();		  // 层序遍历

	void NodeCount();		  // 获得节点个数

	void LeafCount();		  // 获得叶子节点个数

	void Destroytree();       // 销毁树

	void DeleteNode(Type _val);	 // 删除指定节点数

	void CopyTree(BiNode<Type> *p);  // 复制构造

	void Search(Type _val);		// 查找指定节点是否存在

private:
	BiNode<Type>* root;

private:  // 供类内部使用的方法
	void preTraver(BiNode<Type> *p); // 递归型前序遍历,即根左右

	void midTraver(BiNode<Type> *p); // 递归型中序遍历,即左根右

	void behTraver(BiNode<Type> *p); // 递归型后序遍历,即左右根

	void preTraverI(BiNode<Type> *p); // 前序遍历,非递归

	void midTraverI(BiNode<Type> *p);  // 中序遍历,非递归

	void behTraverI(BiNode<Type> *p);  // 后序遍历,非递归

	void levelTraver(BiNode<Type> *p); // 层序遍历

	int NodeCount(BiNode<Type> *p);

	int LeafCount(BiNode<Type> *p); // 叶子节点的个数

	void destroytree(BiNode<Type> *&p); // 确保删除的是p本身

	void DeleteNode(BiNode<Type> *pNode, Type _val); // 删除指定节点,三种情况

	BiNode<Type> *frontNode(BiNode<Type> *pNode); // 寻找中序遍历的前驱节点

	BiNode<Type> *behindNode(BiNode<Type> *pNode); // 寻找中序遍历的后继节点

	bool search(BiNode<Type> *&p, Type _val);

};





#endif // BITREE_H_
