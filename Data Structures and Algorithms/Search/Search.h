#pragma once
#include<iostream>
#include<algorithm>

//Tìm phần tử nhỏ nhất trong dãy sử dụng Min-heap
int SearchForMinimum(int* a, int n);

//Tìm phần tử nhỏ thứ k trong dãy, sử dụng phân hoạch Lomuto
int SearchForMinimum(int* a, int n, int k);

//hàm có tác dụng phân loại nữa trái và nữa phải, 
//các phần từ nhỏ hơn arr[p] thì là phần trái, ngược lại phần phải
//và trả về vị trí của phần tử cuối phần trái
int partition(int arr[], int left, int right, int p);

//ta xét, nếu n == 1 thì nó là kết quả
//ngược lại, ta gọi hàm partition để phân hoạch là lấy vị trí r(là kích thước phần trái)
//if k < r(là vị trí phần) gọi đệ qui tiếp tục với phần nữa trái
// else if k < r gọi đệ qui tiếp tục phần nữa phải
//else return a[r]
int QuickSelect(int arr[], int left, int right, int k);

//Sắp xếp dãy số tăng dần.Tìm vị trí của số nguyên x có trong dãy bằng thuật toán
//tìm kiếm tuyến tính và nhị phân
int LinearSearch(int* a, int n, int x);
int BinarySearch(int* a, int n, int x);

template<class T>
void Heapify(T * a, int n, int i, bool(*compare)(T, T));


//tạo một heap chuẩn
template<class T>
void CreateHeap(T * a, int n, bool(*compare)(T, T));

template<class T>
bool max(T a, T b);

template<class T>
bool min(T a, T b);
template<class T>

void swap(T& a, T& b);
