
#ifndef SORT_H
#define SORT_H

#include<iostream>
#include<thread>
#include <chrono>
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable




int * arr = NULL;
int N = 0, H[3] = { 3,1 };
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

int *temp;

using namespace std;

template<class T>
bool Greater(T a, T b);

template<class T>
bool Less(T a, T b);

template<class T>
void Swap(T &a, T&b);

template<class T>
void SelectionSort(T *a, int n, bool(*compare)(T, T));

template<class T>
void InsertionSort(T *a, int n, int h, bool(*compare)(T, T));
template<class T>
void HeapSort(T *a, int n, bool(*compare)(T, T));

template<class T>
void Heapify(T *a, int n, int i, bool(*compare)(T, T));

template<class T>
void CreateHeap(T *a, int n, bool(*compare)(T, T));

template<class T>
void QuickSort(T *a, int left, int right, bool(*compare)(T, T));

template<class T>
void MergeSort(T *a, int n, bool(*compare)(T, T));

template<class T>
inline void Merge_Sort(T * a, int left, int right, bool(*compare)(T, T));

template<class T>
void Merge(T * a, int left, int mid, int right, bool(*compare)(T, T));

//shell sort thread
//void ShellSortThread();

template<class T>
void ShellSort(T *a, int n, bool(*compare)(T, T));


void out(int *a, int n);


#endif // !SORT_H

template<class T>
inline bool Greater(T a, T b)
{
	return !Less(a, b);
}

template<class T>
inline bool Less(T a, T b)
{
	return a > b;
}

template<class T>
inline void Swap(T & a, T & b)
{
	T temp = a;
	a = b;
	b = temp;
}



template<class T>
inline void SelectionSort(T * a, int n, bool(*compare)(T, T))
{
	int index = 0;
	for (int i = 0; i < n - 1; i++) {
		index = i;
		for (int j = i + 1; j < n; j++) {
			if (compare(a[index], a[j])) {
				index = j;
			}
		}
        Swap(a[index], a[i]);
	}
}

template<class T>
inline void InsertionSort(T * a, int n, int h, bool(*compare)(T, T))
{
	int temp, j;
	for (int i = 0; i < n; i += h) {
		j = i;
		temp = a[i];
		while ((j > 0) && compare(a[j - h], temp)) {
			a[j] = a[j - h];
			j -= h;
		}
		a[j] = temp;
	}
}

template<class T>
inline void HeapSort(T * a, int n, bool(*compare)(T, T))
{
	//heap sort gồm 2 bước
	//B1: tạo 1 heap chuẩn

	//B2:lấy phần tử đầu, hoán vị với phần tử cuối mảng, và khóa phần tử đó
	//vì phần tử đó đã là lớn nhất trong heap từ 0 đến n - 1

	//B1
	CreateHeap(a, n, compare);

	//B2
	for (int i = n - 1; i >= 1; i--) {
        Swap(a[0], a[i]);
		Heapify(a, i, 0, compare);//vì đã thay đổi chuẩn heap, nên phải chuẩn hóa lại
	}
	//Heapify(a, n, 0);//tạo hiệu ứng lang truyền

}



template<class T>
inline void Heapify(T * a, int n, int i, bool(*compare)(T, T))
{
	int vitri = i;
	if (2 * i + 1 >= n)
		return;
	//nếu lá thứ j còn hợp lệ và ko quá lá thứ 2*i + 1 thì xét tiếp tục
	for (int j = 2 * i + 1; j < n && j <= 2 * i + 2; j++) {
		//tìm giá trị lớn nhất trong 1 là hoặc 2 lá
		if (compare(a[j], a[vitri])) {
			vitri = j;
		}
	}
	//nếu vị trí tìm khác vị trí của i thì swap và lang truyền heap
	if (i != vitri) {
        Swap(a[i], a[vitri]);
		Heapify(a, n, vitri, compare);
	}
}


//tạo một heap chuẩn
template<class T>
inline void CreateHeap(T * a, int n, bool(*compare)(T, T))
{
	//vì node chỉ bất đầu từ (n/2-1)
	//nên ta duyệt từ n/2 - 1

	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(a, n, i, compare);
	}
}


inline void xuat(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

template<class T>
inline void QuickSort(T * a, int left, int right, bool(*compare)(T, T)) {
	int l = left, r = right, X = a[(l + r) / 2];//lấy vị trí giữa làm cột móc để so sánh

	while (l <= r) {
		while (compare(X, a[l]))//Tìm vị trí phần tử lớn hơn a[mid]
			l++;

		while (compare(a[r], X))//tìm vị trí phần tử nhỏ hơn a[mid]
			r--;

		if (l <= r) {//nếu l còn hợp lệ, tức là l phải nhỏ hơn hoặc = r
			if (l != r) {//xét nếu vị trí khác nhau thì mới hoán vị
				Swap(a[l], a[r]);
			}
			l++;//duyệt tiếp vị trí
			r--;//lùi 1 vị trí

		}
	}
	if (left < r)//nếu r lơn hay bằng left thì, thực hiện Quick với mảng bất đâu từ left - r
		QuickSort(a, left, r, compare);
	if (l < right)//nếu l nhỏ hay bằng right thì, thực hiện Quick với mảng bất đâu từ l - right
		QuickSort(a, l, right, compare);

}

template<class T>
inline void MergeSort(T * a, int n, bool(*compare)(T, T))
{
	temp = new T[n];
	Merge_Sort(a, 0, n - 1, compare);
	delete[]temp;
}

template<class T>
inline void Merge_Sort(T * a, int left, int right, bool(*compare)(T, T))
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Merge_Sort(a, left, mid, compare);//nữa bên trái
		Merge_Sort(a, mid + 1, right, compare);//nữa phải
		Merge(a, left, mid, right, compare);
	}
	return;
}

template<class T>
inline void Merge(T * a, int left, int mid, int right, bool(*compare)(T, T))
{
	//trộn
	int i = left, i1 = left, i2 = mid + 1;
	while ((i1 <= mid) && (i2 <= right))
	{
		if (compare(a[i2], a[i1])) {
			temp[i] = a[i1];
			i1++;
		}
		else {
			temp[i] = a[i2];
			i2++;
		}
		i++;
	}
	//nếu mảng i1 còn phần tử thì gán lại cho temp
	while (i1 <= mid) {
		temp[i] = a[i1];
		i1++;
		i++;
	}
	//nếu mảng i2 còn phần tử thì gán lại cho temp
	while (i2 <= right) {
		temp[i] = a[i2];
		i2++;
		i++;
	}
	//copy mảng temp lại cho mảng a 
	for (int j = left; j <= right; j++) {
		a[j] = temp[j];
	}
}

template<class T>
inline void ShellSort(T * a, int n, bool(*compare)(T, T))
{
	int nH = 2, h[2] = { 3,1 };
	for (int i = 0; i < nH; i++) {
		InsertionSort(a, n, h[i], compare);
	}
}


//inline void ShellSortThread()
//{
//
//	std::thread threads[2];
//	// spawn 10 threads:
//	for (int i = 0; i<2; ++i)
//		threads[i] = std::thread(Insertion_sort, H[i]);
//
//	std::cout << "10 threads ready to race...\n";
//	go();                       // go!
//
//	for (auto& th : threads) th.join();
//
//}
