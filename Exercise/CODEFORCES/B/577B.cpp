//http://codeforces.com/contest/557/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int a[200005];
    int n;
    int w;
    double Min;
    double result;
    cin >> n >> w;

    if(w == 1){
        cout << w;
        return 0;
    }

    for (int i = 0; i < n * 2; ++i) {
        cin >> a[i];
    }

    sort(a, a + (2*n));

    Min = min(a[0]*2, a[n]);

    result = Min*1.0*n + Min/2.0*n;

    result = min(result, w*1.0);

    printf("%.6lf\n", result);

    return 0;
}
