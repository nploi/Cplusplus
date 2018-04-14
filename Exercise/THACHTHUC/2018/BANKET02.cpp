
/*

Mỗi ngày, bạn đều tập chạy bộ để rèn luyện thể lực. Bạn có đeo đồng hồ thông minh
 giúp ghi nhận lại quá trình tập luyện. Trong nhật ký của đồng hồ thông minh có N
 dòng dữ liệu. Dòng dữ liệu thứ i (1 <= i <= N – 1) gồm có thời điểm ghi nhận t[i]
 và vận tốc tức thời v[i] tại thời điểm này. Giả sử bạn chạy với vận tốc ổn định
 là v[i] từ thời điểm t[i] đến t[i+1]. Dòng thứ N chỉ có thông tin thời điểm cuối
 khi bạn chấm dứt việc luyện tập và không có thông tin vận tốc.

Yêu cầu: Hãy tính độ dài quãng đường mà bạn đã tập luyện.

Input Format

Dòng đầu tiên là số nguyên dương N <= 100. Mỗi dòng trong số N – 1 dòng tiếp theo
 là thời điểm đo vận tốc, dưới dạng hh:mm:ss (với 0 <= hh <= 23), sau đó là vận tốc
 đo được, là một số nguyên dương (đơn vị tính: m/s). Dòng cuối cùng là thời điểm bạn
 chấm dứt luyện tập (và không có thông tin vận tốc). Giá trị vận tốc không vượt quá 100.

Lưu ý: các thời điểm t[i] được ghi nhận trong cùng 1 ngày.

Constraints

1 <= N <= 100 0 <= hh <= 23 Giá trị vận tốc không vượt quá 100.

Output Format

Một số nguyên dương là độ dài quãng đường mà bạn đã chạy bộ (đơn vị tính là m).

Sample Input 0

5
00:00:01 3
00:05:01 6
00:10:01 6
00:30:01 5
01:00:01

Sample Output 0

18900

Explanation 0

5 phút đầu: 3m/s => 900m
5 phút sau: 6m/s => 1800m
20 phút sau: 6m/s => 7200m
30 phút cuối: 5m/s => 9000m

 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long sum = 0;
    long long h, m, s, v;
    vector<pair<long, long> > vv;
    cin >> n;
    while (n--) {
        char c[2], d;
        string str;
        cin >> str;
        c[0] = str[0];
        c[1] = str[1];
        h = atoi(c);
        c[0] = str[3];
        c[1] = str[4];
        m = atoi(c);
        c[0] = str[6];
        c[1] = str[7];
        s = atoi(c);
        if (n == 0) {
            vv.push_back(make_pair(h * 60 * 60 + m * 60 + s, 0));
            continue;
        }
        cin >> v;
        vv.push_back(make_pair(h * 60 * 60 + m * 60 + s, v));
    }

    for (int i = 1; i < vv.size(); ++i) {
        sum += (vv[i].first - vv[i - 1].first) * vv[i - 1].second;
    }
    cout << sum;
    return 0;
}


