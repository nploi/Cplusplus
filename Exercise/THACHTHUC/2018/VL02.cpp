/*
 * 
 * Mỗi chữ số trên bảng điện tử được biểu diễn bằng tối đa 7 đèn led. Dấu trừ (của số âm) cần dùng 1 đèn led.
 *
 * Hãy cho biết cần dùng bao nhiêu đèn led để biểu diễn số nguyên N gồm tối đa 20 ký tự.
 * Input Format
 * Nhập vào từ bàn phím số nguyên N gồm tối đa 20 ký tự.
 * Constraints
 * Số nguyên N gồm tối đa 20 ký tự.
 * Output Format
 * Xuất ra màn hình một số nguyên dương là số lượng đèn led tối thiểu dùng để biểu diễn số nguyên N.
 * Sample Input 0
 * 123
 * Sample Output 0
 * 12
 *
 * by Le Yen Thanh
 */

#include <iostream>

using namespace std;

long a[10] = {6, 2, 5, 5, 4 , 5, 6 , 3, 7, 6};

int main() {
    long long n, sum = 0;
    cin >> n;
    if ( n < 0){
        sum =1;
        n = abs(n);
    }

    while(n!=0){
        sum += a[n%10];
        n/=10;
    }

    cout << sum;

    return 0;
}
