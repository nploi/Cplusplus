//http://codeforces.com/problemset/problem/914/A

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool perfectSquare(long number){
    double sqr = sqrt(number)*1.0;
    double decimal = sqr - (int)sqr;
    if(decimal == 0.00){
        return true;
    }
    return false;
}

long findMax(vector<long> arr){
    long index = -1;
    for(int i = 0; i < arr.size(); i++){
        if(!perfectSquare(arr[i])){
            index = i;
            break;
        }
    }
    if(index == -1)
        return -1;

    for (int i = index; i < arr.size(); i++) {
        if(!perfectSquare(arr[i]) && arr[i] > arr[index]){
            index = i;
        }
    }

    return index;
}

int main(){
    vector<long> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    cout << arr[findMax(arr)];
    return 0;
}
