/*********************************
* FileName		:	BiTree.h
* Author		:	Chen Runyu
* Revision time :	2022/4/10
* ---------Introduce-------------
* ����������ADT
*********************************/

#ifndef BITREE_H_
#define BITREE_H_

#define true  1
#define false 0

#include <iostream>

using namespace std;

// ���ڵ�Ķ���
template <typename Type>
struct BiNode
{
	Type val;
	BiNode<Type>* rchild;   // �Һ���
	BiNode<Type>* lchild;	// ����
	BiNode<Type>* parent;	// ˫�׽ڵ�

	BiNode(Type T):val(T),rchild(nullptr),lchild(nullptr),parent(nullptr) // �ṹ���ʼ��
	{  }

	BiNode() = default;     // ʹ��Ĭ�ϳ�ʼ��
	
};



// �����������Ķ���
template <typename Type>
class BiTree
{

public:   // �ṩ���û�ʹ�õĽӿ�

	BiTree();   // ���캯��
	~BiTree();  // ��������

	void Insert(Type _val);   // ����ڵ�

	void PreTraver();		  // ǰ�����,�ݹ�

	void MidTraver();		  // �������,�ݹ�

	void BehTraver();		  // �������,�ݹ�

	void LevelTraver();		  // �������

	void NodeCount();		  // ��ýڵ����

	void LeafCount();		  // ���Ҷ�ӽڵ����

	void Destroytree();       // ������

	void DeleteNode(Type _val);	 // ɾ��ָ���ڵ���

	void CopyTree(BiNode<Type> *p);  // ���ƹ���

	void Search(Type _val);		// ����ָ���ڵ��Ƿ����

private:
	BiNode<Type>* root;

private:  // �����ڲ�ʹ�õķ���
	void preTraver(BiNode<Type> *p); // �ݹ���ǰ�����,��������

	void midTraver(BiNode<Type> *p); // �ݹ����������,�������

	void behTraver(BiNode<Type> *p); // �ݹ��ͺ������,�����Ҹ�

	void preTraverI(BiNode<Type> *p); // ǰ�����,�ǵݹ�

	void midTraverI(BiNode<Type> *p);  // �������,�ǵݹ�

	void behTraverI(BiNode<Type> *p);  // �������,�ǵݹ�

	void levelTraver(BiNode<Type> *p); // �������

	int NodeCount(BiNode<Type> *p);

	int LeafCount(BiNode<Type> *p); // Ҷ�ӽڵ�ĸ���

	void destroytree(BiNode<Type> *&p); // ȷ��ɾ������p����

	void DeleteNode(BiNode<Type> *pNode, Type _val); // ɾ��ָ���ڵ�,�������

	BiNode<Type> *frontNode(BiNode<Type> *pNode); // Ѱ�����������ǰ���ڵ�

	BiNode<Type> *behindNode(BiNode<Type> *pNode); // Ѱ����������ĺ�̽ڵ�

	bool search(BiNode<Type> *&p, Type _val);

};





#endif // BITREE_H_
