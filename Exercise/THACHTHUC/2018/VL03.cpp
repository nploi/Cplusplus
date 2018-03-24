/*
 * Tam giác Pascal được xây dựng như sau:

Dòng 1:	1
Dòng 2:	1 1
Dòng 3:	1 2 1
Dòng 4:	1 3 3 1
Dòng 5:	1 4 6 4 1
...

Các phần tử trên mỗi dòng được đánh thứ tự tăng dần liên tiếp từ 1 trở đi. Hãy cho biết giá trị của phần tử thứ j trên dòng thứ i với 1 <= j <= i <= 40

Input Format

Nhập vào từ bàn phím hai số nguyên dương i và j, cách nhau bằng ký tự khoảng trắng.

Constraints

1 <= j <= i <= 40

Output Format

Xuất ra màn hình một số nguyên dương là giá trị của phần tử thứ j trên dòng thứ i của tam giác Pascal.

Sample Input 0

3 2

Sample Output 0

2


 */


#include<iostream>


using namespace std;
void tgPascal(int i, int j);

int main() {
    int i, j;
    cin >> i >> j;
    tgPascal(i, j);

    return 0;

}

//http://vietjack.com/bai_tap_cplusplus_co_giai/in-tam-giac-pascal-trong-cplusplus.jsp
void tgPascal(int i, int j) {
    long long PascalTr[40][40];
    long hang, cot;
    //gan gia tri 0 cho moi phan tu mang
    for (hang = 0; hang < 40; hang++)
        for (cot = 0; cot < 40; cot++) PascalTr[hang][cot] = 0;

    PascalTr[0][0] = 1;
    PascalTr[1][0] = 1;
    PascalTr[1][1] = 1;

    for (hang = 2; hang < i; hang++) {
        PascalTr[hang][0] = 1;
        for (cot = 1; cot < j; cot++) {
            PascalTr[hang][cot] = PascalTr[hang - 1][cot - 1] + PascalTr[hang - 1][cot];
        }
    }
    cout << PascalTr[i - 1][j - 1];
}
