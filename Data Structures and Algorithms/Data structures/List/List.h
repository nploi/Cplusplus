/*
@author
    nploi1998@gmail.com
@date
    11/03/2018
*/

#pragma once
#include<iostream>
#include<string>

using namespace std;


template<class T>
struct NODE
{
	T data;
	NODE *pNext;
public:
	NODE() {
		pNext = NULL;
	}
	NODE* CreateNODE(T x) {
		struct NODE *pN = new NODE;//Xin cấp phát vùng nhớ cho phần tử mới
		if (pN == NULL) {
			cout << "Khong du o nho !!\n";
			return NULL;
		}
		pN->data = x;
		pN->pNext = NULL;
		return pN;
	}
};

 

template<class T>
class List
{
public:
	List();
	~List();

	bool addHead(T data);
	bool addTail(T data);

	void RemoveAll();
    bool RemoveHead();
    bool RemoveTail();

    /*
    * if return T(nullptr) is emtpy
    */
    T getHead() {
        if (m_pHead != NULL) {
            return m_pHead->data;
        }
        return T();
    }

    /*
     * if return T(nullptr) is emtpy
     */
    T getTail() {
        if (m_pHead != NULL) {
            for (NODE<T> *p = m_pHead, *t;; p = p->pNext) {
                if (p->pNext == NULL) {
                    return p->data;
                }
                t = p;
            }
        }
        return T();
    }

    /*
     * Add some Methods
     */
	long SumList();
	long MaxList();
	int CountList();
	int CountListSame(T x);

	void Split_X(T x, List<T> &a, List<T> &b);

private:
	NODE<T> *m_pHead;
};


template<class T>
inline List<T>::List()
{
	m_pHead = NULL;
}

template<class T>
inline List<T>::~List()
{
    if(m_pHead != NULL) {
        this->RemoveAll();
    }
}

template<class T>
inline bool List<T>::addHead(T data)
{
	NODE<T> *pN = NULL;
	pN = pN->CreateNODE(data);
	if(pN == NULL){
		return false;
	}
	if (m_pHead == NULL) {
		m_pHead = pN;
	}
	else {
		pN->pNext = m_pHead;
		m_pHead = pN;
	}
	return true;
}

template<class T>
inline bool List<T>::addTail(T data) {
    if (m_pHead == NULL) {
        return this->addHead(data);
    } else {
        NODE<T> *pN = NULL;

        pN = pN->CreateNODE(data);
        if (pN == NULL)
            return false;
        NODE<T> *p = m_pHead;
        while (p->pNext != NULL) {
            p = p->pNext;
        }
        p->pNext = pN;
        pN->pNext = NULL;
    }
    return true;
}

template<class T>
inline bool List<T>::RemoveHead() {
    NODE<T> *p = NULL;
    if (m_pHead != NULL) {
        p = m_pHead;
        m_pHead = m_pHead->pNext;
        delete p;
        return true;
    }
    delete p;
    return false;
}

//chua xong
template<class T>
inline bool List<T>::RemoveTail()
{
	if(m_pHead!= NULL) {
		for (NODE<T> *p = m_pHead, *t;; p = p->pNext) {
			if (p->pNext == NULL) {
                if(t!=NULL) {
                    t->pNext = NULL;
                }
				delete p;
                p = NULL;
				return true;
			}
			t = p;
		}
	}
	return false;
}

template<class T>
inline void List<T>::RemoveAll() {
    NODE<T> *pNode;
    while (m_pHead != NULL) {
        pNode = m_pHead;
        if (m_pHead->pNext == NULL)
            break;
        m_pHead = m_pHead->pNext;

        delete pNode;
    }
    pNode = m_pHead;
    delete pNode;
    m_pHead = NULL; //đánh dấu mảng rỗng
}

template<class T>
inline long List<T>::SumList()
{
	int s = 0;
	NODE<T> *p = m_pHead;
	while (p != NULL) {
		s = s + p->data;
		p = p->pNext;
	}
	return s;
}

template<class T>
inline long List<T>::MaxList()
{
	if (m_pHead == NULL)
		return NULL;
	NODE<int> * p = m_pHead;
	int max = p->data;
	p = p->pNext;
	while (p != NULL) {
		if (p->data > max) {
			max = p->data;
		}
		p = p->pNext;
	}
	return max;
}

template<class T>
inline int List<T>::CountList()
{
	int c = 0;
	for (NODE<int> * p = m_pHead; p != NULL; p = p->pNext) {
		c++;
	}
	return c;
}

template<class T>
inline int List<T>::CountListSame(T x)
{
	int c = 0;
	for (NODE<T> *p = m_pHead; p != NULL; p = p->pNext) {
		if (p->data == x) {
			c++;
		}
	}
	return c;
}

template<class T>
inline void List<T>::Split_X(T x, List<T> &a, List<T> &b)
{
	//a->m_pHead = NULL;
	//b->addHead = NULL;
	for (NODE<T> *p = m_pHead; p != NULL; p = p->pNext) {
		if (p->data < x) {
			a.addHead(p->data);
		}
		if (p->data > x) {
			b.addHead(p->data);
		}
	}
}
