//code by NGUYEN PHUC LOI
//HCMUS - 2017

#pragma once

#include<iostream>
#include<algorithm>

using namespace std;


#define BALANCE 0
#define LEFT 1
#define RIGHT 2

template<class T>

struct AVLNODE {
	T key;
	int bal;//thuộc tính cho biết giá trị cân bằng
			//0: cân bằng, 1: lệch trái, 2: lệch phải
	AVLNODE<T> *pLeft;
	AVLNODE<T> *pRight;
	AVLNODE() {

		pLeft = pRight = NULL;
	}
	/*~AVLNODE() {

	if (pLeft != NULL) {
	delete pLeft;
	}
	if (pRight!= NULL) {
	delete pRight;
	}
	key = bal = 0;
	pLeft = NULL;
	pRight = NULL;
	}*/
	AVLNODE *CreateNODE(T x) {
		AVLNODE *p = new AVLNODE<T>;
		if (p == NULL) {
			return NULL;
		}
		p->key = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		p->bal = BALANCE;//Khi tao một cây mới thì left và right trỏ NULL
						 //nên bal = 0 là cây được cân bằng mặc định
		return p;
	}
};

template<class T>
class AVL {
public:

	AVL() {
		m_pTree = NULL;
	}
	~AVL() {
		if (m_pTree != NULL) {
			removeAll(m_pTree);
		}
	}


	//chèn một giá trị vào cây
	bool insert(int x) {

		Insert_(m_pTree, x);
		if (m_pTree == NULL)
		{
			return false;
		}
		return true;
	}

	//kiểm tra rỗng
	bool empty() {
		return (m_pTree == NULL) ? 0 : 1;
	}

	//xóa node mang giá trị x
	bool Delete(int x) {
		if (m_pTree == NULL)
			return false;
		Delete_(m_pTree, x);
		return true;
	}

	void print() {
		Traverse(m_pTree);
	}

	//tìm x có trong node hay khong
	bool search(T x, int &sophepss) {
		if(m_pTree==NULL)
			return false;
		sophepss = search_(m_pTree, x);
		return true;
	}

private://các phương thức riêng

	void leftRotate(AVLNODE<T> *&P) {
		AVLNODE<T> *Q;
		Q = P->pRight;
		P->pRight = Q->pLeft;
		Q->pLeft = P;
		P = Q;
	}

	void rightRotate(AVLNODE<T> *&P) {
		AVLNODE<T> *Q;
		Q = P->pLeft;
		P->pLeft = Q->pRight;
		Q->pRight = P;
		P = Q;
	}

	void leftBalance(AVLNODE<T> *&P) {
		switch (P->pLeft->bal) {
		case LEFT: //mất cân bằng trái trái
			rightRotate(P);
			P->bal = BALANCE;
			P->pRight->bal = BALANCE;
			break;

		case RIGHT: //mất cân bằng phải
			leftRotate(P->pLeft);
			rightRotate(P);
			switch (P->bal) {
			case 0:
				P->pLeft->bal = BALANCE;
				P->pRight->bal = BALANCE;
				break;
			case 1:
				P->pLeft->bal = BALANCE;
				P->pRight->bal = RIGHT;
				break;
			case 2:
				P->pLeft->bal = LEFT;
				P->pRight->bal = BALANCE;
				break;
			}
			P->bal = BALANCE;
			break;
		case BALANCE:
			rightRotate(P);
			P->bal = RIGHT;
			P->pRight->bal = LEFT;
			break;
		}

	}

	void rightBalance(AVLNODE<T> *&P) {
		switch (P->pRight->bal) {
		case LEFT: //Mất cân bằng bên phải
			rightRotate(P->pRight);
			leftRotate(P);
			switch (P->bal) {

			case BALANCE:
				P->pLeft->bal = BALANCE;
				P->pRight->bal = BALANCE;
				break;

			case LEFT:
				P->pLeft->bal = LEFT;
				P->pRight->bal = BALANCE;
				break;

			case RIGHT:
				P->pLeft->bal = BALANCE;
				P->pRight->bal = RIGHT;
				break;
			}
			P->bal = BALANCE;
			break;
		case RIGHT:
			leftRotate(P);
			P->bal = BALANCE;
			P->pLeft->bal = BALANCE;
			break;
		case BALANCE:
			leftRotate(P);
			P->bal = LEFT;
			P->pLeft->bal = RIGHT;
			break;
		}

	}

	

	int Insert_(AVLNODE<T> *&tree, T x) {
		int res;
		if (tree == NULL) { //Ghi chú: cho biết ý nghĩa của câu lệnh này
			tree = tree->CreateNODE(x);
			if (tree == NULL) {
				return -1; //thêm ko thành công vì thiếu bộ nhớ
			}
			return 2;//thêm thành công và làm tăng chiều cao cây
		}
		else {
			if (tree->key == x) {
				return 0; //khóa này đã tồn tại trong cây
			}
			else if (tree->key > x) {
				res = Insert_(tree->pLeft, x);
				if (res < 2) {
					return res;
				}
				switch (tree->bal) { //Kiểm tra cây đang lệch bên nào
				case BALANCE:
					tree->bal = LEFT;
					return 2;
				case LEFT:
					leftBalance(tree);
					return 1;
				case RIGHT:
					tree->bal = BALANCE;
					return 1;
				}
			}
			else {
				res = Insert_(tree->pRight, x);
				if (res<2) {
					return res;
				}
				switch (tree->bal) {
				case BALANCE:
					tree->bal = RIGHT;
					return 2;
				case LEFT:
					tree->bal = BALANCE;
					return 1;
				case RIGHT:
					rightBalance(tree);
					return 1;
				}
			}
		}
	}

	int Delete_(AVLNODE<T> *&p, T x) {
		int res;
		if (p == NULL) {
			return 2;
		}
		else {
			if (x < p->key) {

				res = Delete_(p->pLeft, x);
				if (res == 2) {
					return 2;
				}
				switch (p->bal)
				{
				case LEFT:
					p->bal = BALANCE;
					return 1;
					break;

				case BALANCE:
					p->bal = RIGHT;
					return 2;
					break;

				case RIGHT:
					rightBalance(p);
					return 1;
					break;

				}
			}
			else {
				if (x > p->key) {
					res = Delete_(p->pRight, x);
					if (res == 2) {
						return 2;
					}
					switch (p->bal)
					{
					case LEFT:
						leftBalance(p);
						return 1;
						break;

					case BALANCE:
						p->bal = LEFT;
						return 2;
						break;

					case RIGHT:
						p->bal = BALANCE;
						return 1;
						break;

					}
				}
				AVLNODE<T> *q = p;
				if (p->pLeft == NULL) {
					p = p->pRight;
				}
				else {
					if (p->pRight == NULL) {
						p = p->pLeft;
					}
					else {
						q = searchStandFor(p->pRight, p);
					}

				}
				delete q;
				q = NULL;
				return 1;//xoa thanh cong giam 1
			}

		}

	}

	void Traverse(AVLNODE<T> *t) {
		if (t != NULL) {
			Traverse(t->pLeft);
			printf("Khoa: %d, can bang: %d\n", t->key, t->bal);
			Traverse(t->pRight);
		}
	}

	int search_(AVLNODE<T> *p, T x) {
		if (p == NULL) {
			return 0;
		}
		else {
			if (x == p->key) {
				return 1;
			}
			else {
				if (x > p->key) {
					return 1 + search_(p->pRight, x);
				}
				else {
					return 1 + search_(p->pLeft, x);
				}
			}
		}
	}

	bool removeAll(AVLNODE<T> *&t) {
		if (t != NULL) {
			removeAll(t->pLeft);
			removeAll(t->pRight);
			delete t;
		}
		return true;
	}

	//tìm phần tử thay thế nút xóa
	//tìm phần tử lớn nhất bên phải
	AVLNODE<T>* searchStandFor(AVLNODE<T>*&p, AVLNODE<T>*pCurr)
	{
		if (p->pLeft != NULL) {
			return searchStandFor(p->pLeft, pCurr);
		}
		else {
			pCurr->key = p->key;
			AVLNODE<T> *temp = p;
			p = p->pRight;
			return temp;
		}
	}

private://các thuộc tính riêng
	AVLNODE<T> * m_pTree;
};
