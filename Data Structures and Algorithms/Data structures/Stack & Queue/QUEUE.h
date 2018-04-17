#pragma once
#include<iostream>
#include"NODE.h"

template<class T>
class QUEUE
{
public:
	QUEUE();
	~QUEUE();
	bool empty();
	bool push(T x);
	bool pop();
	T front();

private:
	NODE<T> *m_pHead;
	NODE<T> *m_pTail;
};

template<class T>
inline QUEUE<T>::QUEUE()
{
	m_pHead = m_pTail = NULL;
}

template<class T>
inline QUEUE<T>::~QUEUE()
{
	if (m_pHead != NULL) {
		NODE<T> *p;
		while (m_pHead != NULL) {
			p = m_pHead;
			m_pHead = m_pHead->pNext;
			delete p;
		}
		m_pHead = m_pTail = NULL;
	}
}

template<class T>
inline bool QUEUE<T>::empty()
{
	return (m_pHead == NULL);
}

template<class T>
inline bool QUEUE<T>::push(T x)
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
inline bool QUEUE<T>::pop()
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

template<class T>
inline T QUEUE<T>::front()
{
	if (m_pHead != NULL) {
		return m_pTail->data;
	}
}
