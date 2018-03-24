/*
 * Xin chúc mừng bạn đã được chọn tham gia chương trình giao lưu văn hóa dành cho sinh viên khu vực Đông Nam Á. Ngày khởi hành của chương trình giao lưu là ngày a tháng b trong năm 2018. Biết hôm nay là ngày thứ bảy, 24 tháng 03 năm 2018. Hãy cho biết ngày khởi hành của chương trình giao lưu là ngày thứ mấy.

Input Format

Nhập vào từ bàn phím hai số nguyên dương a và b, cách nhau bởi ký tự khoảng trắng, với 1 <= a <= 31, 3 <= b <= 12. Đây là một ngày hợp lệ trong năm 2018 và sau ngày 24 tháng 03 năm 2018.

Constraints

1 <= a <= 31, 3 <= b <= 12

Output Format

Xuất ra màn hình chính xác một trong những chuỗi ký tự sau đây: "thu hai", "thu ba", "thu tu", "thu nam", "thu sau", “thu bay" hay "chu nhat".

Lưu ý: Kết quả xuất ra KHÔNG có dấu nháy kép, gồm toàn các ký tự thường và 1 ký tự khoảng trắng.

Sample Input 0

1 6

Sample Output 0

thu sau

Explanation 0

Ngày 1 tháng 6 năm 2018 là ngày thứ 6
 *
 *
 */

#include<stdio.h>
#include<iostream>

using namespace std;

string str[7] = {"chu nhat", "thu hai", "thu ba", "thu tu", "thu nam","thu sau", "thu bay"};

//http://mathforum.org/library/drmath/view/66535.html
int thisIsMagic(int year, int month, int day) {

    if (month < 3) {
        year--;
        month += 12;
    }
    return 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306;
}

int main()
{
    int d, m, y;
    cin >> d >> m;
    y = 2018;

    cout << str[thisIsMagic(y, m, d)%7];
    return 0;
}
