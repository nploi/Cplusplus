#pragma once
#include<iostream>
#include"NODE.h"
template<class T>
class STACK
{
public:
	
	STACK();
	
	~STACK();

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
inline STACK<T>::STACK()
{
	m_pHead = m_pTail = NULL;
}

template<class T>
inline STACK<T>::~STACK()
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
inline bool STACK<T>::empty()
{
	return (m_pHead == NULL);
}

template<class T>
inline int STACK<T>::size()
{
	int c = 0;
	for (NODE<T> * p = m_pHead; p != NULL; p = p->pNext) {
		c++;
	}
	return c;
}

template<class T>
inline T STACK<T>::top()
{
	if (m_pHead != NULL) {
		return m_pHead->data;
	}
}

template<class T>
inline bool STACK<T>::push(T x)
{
	NODE<T> *pN = NULL;
	pN = pN->CreateNODE(x);
	if (pN == NULL) {
		return false;
	}
	if (m_pHead == NULL) {
		m_pHead = m_pTail = pN;
	}
	else {
		pN->pNext = m_pHead;
		m_pHead = pN;
	}
	return true;
}

template<class T>
inline bool STACK<T>::pop()
{
	T x;
	if (m_pHead == NULL)
	{
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
		m_pHead = m_pHead->pNext;
		delete p;
		return true;
	}
}
