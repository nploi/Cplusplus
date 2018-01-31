//http://codeforces.com/problemset/problem/898/A

#include <string>
#include <iostream>

using namespace std;

unsigned long rounding(unsigned long number){
    int round = (number%10);
    number/=10;
    if(round>5){
        int neerFinaly = number%10;
        number/=10;
        neerFinaly++;
        number = number*10 + neerFinaly;
    }
    number = number*10;
    return number;
}

int main(){
    unsigned long number;
    cin >> number;
    cout << rounding(number);
    return 0;
}
