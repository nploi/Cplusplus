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

	bool addHead(T data);//them vao dau
	bool addTail(T data);//them vao cuoi

	bool RemoveHead();//xoa dau
	bool RemoveTail();//xoa cuoi




	//xuat
	template<class T>
	friend ostream &operator<<(ostream &outdev, const List<T> &l);

	//=>tham chiếu giá trị trả về
	void RemoveAll();

	//*******************************
	//Nang cao
	long SumList();
	long MaxList();
	int CountList();

	int CountList_Same(T x);

	void Split_X(T x, List<T> &a, List<T> &b);
private:
	NODE<T> *m_pHead;
};


//********************************************

template<class T>
inline List<T>::List()
{
	m_pHead = NULL;
}

template<class T>
inline List<T>::~List()
{
	if (m_pHead != NULL) {
		delete m_pHead;
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
inline bool List<T>::addTail(T data)
{
	if (m_pHead == NULL) {
		return this->addHead(data);
	}
	else {
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
inline bool List<T>::RemoveHead()
{
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
	for (NODE<T> *p = m_pHead,*t;; p = p->pNext) {
		if (p->pNext == NULL) {
			t->pNext = NULL;
			delete p;
			return true;
		}
		t = p;
	}
	return false;
}

template<class T>
inline void List<T>::RemoveAll()
{
	NODE<T> *pNode;
	while (m_pHead != NULL)
	{
		pNode = m_pHead;
		m_pHead = m_pHead->pNext;
		delete pNode;
	}
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
inline ostream &operator<<(ostream & outdev,const List<T> &l)
{
	NODE<T> *p = l.m_pHead;
	while (p != NULL) {

		outdev << p->data << " ";
		p = p->pNext;//để duyệt node tiếp theo
	}
	return outdev;
}

//template<class T>
//inline istream & operator>>(istream & indev, List<T>& l)
//{
//	T Data;
//	do
//	{
//		cout << "Nhap vao du lieu, -1 de ket thuc: ";
//		indev >> Data;
//		if (Data == -1)
//			break;
//		l.addHead(Data);
//	} while (Data != -1);
//	cout << "\nDu lieu da duoc nhap: \n";
//	return indev;
//}

template<class T>
inline int List<T>::CountList_Same(T x)
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
