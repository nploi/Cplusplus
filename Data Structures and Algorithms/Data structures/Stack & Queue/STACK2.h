#pragma once
#include"NODE.h"

template<class T>
class STACK2
{
public:

	STACK2();

	~STACK2();

	bool empty();
	int size();
	T top();
	bool push(T x);
	bool pop();
private:
	NODE<T> *m_pHead;
	NODE<T> *m_pTail;
};

template<class T>
inline STACK2<T>::STACK2()
{
	m_pHead = m_pTail = NULL;
}

template<class T>
inline STACK2<T>::~STACK2()
{
	if (m_pHead != NULL) {
		NODE<T> *p;
		while (m_pHead->pNext != NULL) {
			p = m_pHead;
			m_pHead = m_pHead->pNext;
			delete p;
		}
		m_pHead = m_pTail = NULL;
	}
}

template<class T>
inline bool STACK2<T>::empty()
{
	return (m_pHead == NULL);
}

template<class T>
inline int STACK2<T>::size()
{
	int c = 0;
	for (NODE<T> * p = m_pHead; p != NULL; p = p->pNext) {
		c++;
	}
	return c;
}

template<class T>
inline T STACK2<T>::top()
{
	if (m_pHead != NULL) {
		return m_pTail->data;
	}
}

template<class T>
inline bool STACK2<T>::push(T x)
{
	NODE<T> *p = NULL;
	p = p->CreateNODE(x);
	if (m_pHead == NULL) {
		m_pHead = m_pTail = p;
		return true;
	}
	else {
		m_pTail->pNext = p;
		m_pTail = p;
		return true;
	}
	return false;
}


template<class T>
inline bool STACK2<T>::pop()
{
	if (m_pHead == NULL) {
		return false;
	}
	if (m_pHead == m_pTail) {
		NODE<T> *p = m_pHead;
		m_pHead = m_pTail = NULL;
		delete p;
		return true;
	}
	else {
		NODE<T> *p = m_pHead;
		while (p->pNext != m_pTail)
		{
			p = p->pNext;
		}
		NODE<T> *q = m_pTail;
		p->pNext = NULL;
		m_pTail = p;
		delete q;
		return true;
	}
	return NULL;
}