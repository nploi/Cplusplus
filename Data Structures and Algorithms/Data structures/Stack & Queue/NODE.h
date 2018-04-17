#pragma once
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
			std::cout << "Khong du o nho !!\n";
			return NULL;
		}
		pN->data = x;
		pN->pNext = NULL;
		return pN;
	}
};