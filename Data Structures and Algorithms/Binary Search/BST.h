//code by NGUYEN PHUC LOI
//HCMUS - 2017

#pragma once
#include<iostream>
#include<algorithm>

template<class T>
class NODE 
{

public:
	NODE *m_pLeft;
	NODE *m_pRight;
	T data;
	int m_count;
	NODE() {
		m_pLeft = NULL;
		m_pRight = NULL;
	}
	~NODE() {
		if (m_pLeft != NULL) {
			delete m_pLeft;
		}
		if (m_pRight != NULL) {
			delete m_pRight;
		}
		m_pLeft = NULL;
		m_pRight = NULL;
	}
	NODE(T x){//khoi tao node
		data = x;
		//cho node trai va phai bang null
		m_pLeft = NULL;
		m_pRight = NULL;
		m_count = 1;
	}
};

//Binary search tree
template<class T>
class BST
{
public:
	BST();
	~BST();

	
	bool empty();

	bool insert(T x);

	bool Delete(T x);

	bool search(T x);
	
	void print();

	int getHeight(T x);

	int sum();

	int countNode();

	int countLeaf();

	T MIN();
	T MAX();

	int getNumberOf(T x);


private:

	NODE<T> *MAX_(NODE<T> *p);

	NODE<T> *MIN_(NODE<T> *p);

	int countLeaf_(NODE<T> *p);

	int height(NODE<T> *p);

	bool delAll(NODE<T> *&p);
	//if x > p->data add right, else add left
	bool insert_(NODE<T> *pNode, T x);

	//tim node trong mang, neu tim thay tra ve node do, khong tra ve null
	NODE<T>* search_(NODE<T> *pNode, T x);

	void print_(NODE<T> *pNode);

	//tim phan tu truoc node x
	NODE<T>* search__(NODE<T> *pNode, T x);

	NODE<T>* Max_Left(NODE<T> *pNode);

	bool delete_(NODE<T>* &pNode, T x);

	NODE<T>* searchStandFor(NODE<T> *&p, NODE<T> *pCurr);

	int sum_(NODE<T> *p);

private: 
	NODE<T> *m_pRoot;//node root

	int m_count;//count number node
};



template<class T>
inline BST<T>::BST()
{
	m_pRoot = NULL;
	m_count = 0;
}

template<class T>
inline BST<T>::~BST()
{
	if (m_pRoot != NULL) {
		delAll(m_pRoot);
	}
}

template<class T>
inline bool BST<T>::empty()
{
	return (m_pRoot == NULL&&m_count == 0);
}

template<class T>
inline bool BST<T>::insert(T x)
{
	//if empty is add x->root
	if (this->empty()) {
		m_pRoot = new NODE<T>(x);
		m_count++;
		return true;
	}
	else {
		m_count++;
		return insert_(m_pRoot, x);//tra ve true or false
	}
	return false;
}

template<class T>
inline bool BST<T>::Delete(T x)
{
	return delete_(m_pRoot,x);
}

template<class T>
inline NODE<T>* BST<T>::search_(NODE<T> *pNode, T x)
{
	//if found is return node
	//else if x > node->data
	//recursion
	//is inspect node->right, else inspect right
	if (pNode == NULL)
	{
		return NULL;
	}
	if (x == pNode->data) {
		return pNode;
	}
	else {
		if (x > pNode->data) {
			return search_(pNode->m_pRight, x);//recursion, right
		}
		else {
			return search_(pNode->m_pLeft, x);//recursion, left
		}
	}
}

template<class T>
inline bool BST<T>::search(T x)
{
	//if BST empty is return false
	//else call function search_
	if (this->empty()) {
		return false;
	}
	return (search_(m_pRoot,x) != NULL);
}

template<class T>
inline void BST<T>::print()
{
	if (this->empty())
		return;
	print_(m_pRoot);
}

template<class T>
inline int BST<T>::getHeight(T x)
{
	NODE<T> *p = search_(m_pRoot, x);
	return height(p);
}

template<class T>
inline int BST<T>::sum()
{
	int s = sum_(m_pRoot);
	return s;
}

template<class T>
inline int BST<T>::countNode()
{
	return m_count;
}

template<class T>
inline int BST<T>::countLeaf()
{
	if (this->empty())
		return 0;
	return countLeaf_(m_pRoot);
}

template<class T>
inline T BST<T>::MAX()
{
	if (m_pRoot == NULL)
		return NULL;
	NODE<T> *p = MAX_(m_pRoot);
	return p->data;
}

template<class T>
inline T BST<T>::MIN()
{
	if (m_pRoot == NULL)
		return NULL;
	NODE<T> *p = MIN_(m_pRoot);
	return p->data;
}

template<class T>
inline int BST<T>::getNumberOf(T x)
{
	NODE<T> *p = search_(m_pRoot, x);
	return p->m_count;
}

template<class T>
inline NODE<T>* BST<T>::MAX_(NODE<T>* p)
{
	if (p->m_pRight == NULL) {
		return p;
	}
	else {
		return MAX_(p->m_pRight);
	}
	return NULL;
}

template<class T>
inline NODE<T>* BST<T>::MIN_(NODE<T>* p)
{
	if (p->m_pLeft == NULL) {
		return p;
	}
	else {
		return MIN_(p->m_pLeft);
	}
	return NULL;
}

template<class T>
inline int BST<T>::countLeaf_(NODE<T>* p)
{
	if (p == NULL)
		return 0;
	if (p->m_pLeft == NULL&&p->m_pRight == NULL) {
		return 1;
	}
	else {
		int c = countLeaf_(p->m_pLeft) + countLeaf_(p->m_pRight);
		return c;
	}
}

template<class T>
inline int BST<T>::height(NODE<T> *p)
{
	if (p == NULL)return 0;
	int HL, HR;

	HL = height(p->m_pLeft);
	HR = height(p->m_pRight);
	return (HL > HR) ? (1 + HL) : (1 + HR);
}

template<class T>
inline bool BST<T>::delAll(NODE<T>*& p)
{
	if (p != NULL) {
		return delAll(p->m_pLeft);
		return delAll(p->m_pRight);
		delete p;
	}
	else {
		return true;
	}
}

template<class T>
inline bool BST<T>::insert_(NODE<T> * pNode, T x)
 {
	//if x > node->
	//add right
	//else add left
	if (x == pNode->data) {
		pNode->m_count++;
		return true;
	}
	if (x > pNode->data) {
		if (pNode->m_pRight == NULL) {
			pNode->m_pRight = new NODE<T>(x);
			return true;
		}
		else {
			insert_(pNode->m_pRight, x);
		}
	}
	else {
		if (pNode->m_pLeft == NULL) {
			pNode->m_pLeft = new NODE<T>(x);
			return true;
		}
		else {
			insert_(pNode->m_pLeft, x);
		}
	}
}


//print NLR
template<class T>
inline void BST<T>::print_(NODE<T>* pNode)
{
	if (pNode == NULL)
		return;
	else {
		std::cout << pNode->data << " ";
		print_(pNode->m_pLeft);
		print_(pNode->m_pRight);
	}
}

//error 
template<class T>
inline NODE<T>* BST<T>::search__(NODE<T>* pNode, T x)
{
	if (pNode == NULL)
		return NULL;
	if (x > pNode->data) {
		if (pNode->m_pRight != NULL)
		{
			if (x == pNode->m_pRight->data) {
				return pNode;
			}
			else {

				return search__(pNode->m_pRight, x);
			}
		}
		else {
			return NULL;
		}
	}
	else {
		if (pNode->m_pLeft != NULL)
		{
			if (x == pNode->m_pLeft->data) {
				return pNode;
			}
			else {
				return search__(pNode->m_pLeft, x);
			}
		}
		else {
			return NULL;
		}
	}
	return NULL;
}

template<class T>
inline NODE<T>* BST<T>::Max_Left(NODE<T>* pNode)
{
	if(pNode->m_pLeft==NULL)
	return NULL;
}

template<class T>
inline bool BST<T>::delete_(NODE<T>*& pNode, T x )
{
	if (pNode == NULL) {
		return false;
	}
	if (pNode->data > x) {
		return delete_(pNode->m_pLeft, x);
	}
	else {
		if (pNode->data < x) {
			return delete_(pNode->m_pRight, x);
		}
	}
	NODE<T> *p = pNode;
	if (pNode->m_pLeft == NULL) {//node chi co node phai
		pNode = pNode->m_pRight;
	}
	else {
		if (pNode->m_pRight == NULL) {//node chi co node trai
			pNode = pNode->m_pLeft;
		}
		else {
			//tim phan tu thay the
			p = searchStandFor(pNode->m_pRight, pNode);
		}
	}
	delete p;
	return true;
}

template<class T>
inline NODE<T>* BST<T>::searchStandFor(NODE<T>*&p, NODE<T>*pCurr)
{
	if (p->m_pLeft!=NULL) {
		return searchStandFor(p->m_pLeft, pCurr);
	}
	else {
		pCurr->data = p->data;
		NODE<T> *temp = p;
		p = p->m_pRight;
		return temp;
	}
}

template<class T>
inline int BST<T>::sum_(NODE<T>* p)
{
	if (p!= NULL) {
		return (p->data + sum_(p->m_pLeft) + sum_(p->m_pRight));
	}
	return 0;
}


