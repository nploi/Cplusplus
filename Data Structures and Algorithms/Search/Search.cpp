/*
@author
    nploi1998@gmail.com
@date
    11/03/2018
*/

#include "Search.h"


int SearchForMinimum(int * a, int n)
{
	CreateHeap(a, n, min);//tạo heap min
	return a[0];
}

int SearchForMinimum(int * a, int n, int k)
{
	return QuickSelect(a, 0, n - 1, k);
}

int partition(int arr[], int left, int right, int p)
{
	//duyệt từ left đến right - 1
	int l = left, r = right - 1;
	swap(arr[p], arr[right]);//cố định vị trí p
	//trong khi l và r còn hợp lệ thì xử lý tiếp
	while (l <= r) {

		while (arr[l] < arr[right] &&l <= r)
			l++;
		while (arr[r] >= arr[right] &&l <= r)
			r--;
		if (l < r) {
			swap(arr[l], arr[r]);
		}
	}
	swap(arr[l], arr[right]);
	return l;
}

int QuickSelect(int arr[], int left, int right, int k)
{
	int r, p;
	if (right<=left) {
		return arr[left];
	}
	else {
		p = (right + left) / 2;
		r = partition(arr, left, right, p);
		if (k < r) {
			return QuickSelect(arr, left, r - 1, k);
		}
		if (k > r) {
			return QuickSelect(arr, r + 1, right, k);
		}
		return arr[r];
	}
}

int LinearSearch(int * a, int n, int x)
{
	int i = 0;
	while ( i < n && a[i] != x)
		i++;
	return (i < n) ? i : -1;
}

int BinarySearch(int * a, int n, int x)
{
	int l = 0, r = n - 1, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (a[mid] == x) {
			return mid;
		}
		if (a[mid] < x)
			l = mid + 1;
		else 
			r = mid - 1;
	}
	return -1;
}

template<class T>
void Heapify(T * a, int n, int i, bool(*compare)(T, T))
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
		swap(a[i], a[vitri]);
		Heapify(a, n, vitri, compare);
	}
}


//tạo một heap chuẩn
template<class T>
void CreateHeap(T * a, int n, bool(*compare)(T, T))
{
	//vì node chỉ bất đầu từ (n/2-1)
	//nên ta duyệt từ n/2 - 1

	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(a, n, i, compare);
	}
}

template<class T>
bool max(T a, T b)
{
	return a > b;
}

template<class T>
bool min(T a, T b)
{
	return a < b;
}

