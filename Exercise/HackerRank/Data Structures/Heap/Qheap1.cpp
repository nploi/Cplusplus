//https://www.hackerrank.com/challenges/qheap1/problem

#include<iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

class Heap{

    vector<ll> h;
    /*
     * delete a element in the heap at index
    */
public:
    void pop(ll val){
        int i = find(val);
        h[i] = h[h.size() - 1];
        h.pop_back();
        heapify(i);
    }

    /*
     * add a element in the heap
     */
    void push(ll val){
        h.push_back(val);
        int i = h.size() - 1;
        while (i!=0 && h[(i-1)/2] > h[i]){
            swap(h[i], h[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    
    /*
     * get top in the heap
     */
    ll top(){
        return h[0];
    }


private:

    /*
     * Find a val in the heap
     */
    int find(int val){
        for (int i = 0; i < h.size(); ++i) {
            if(h[i] == val){
                return i;
            }
        }
        return -1;
    }

    /*
     * Min heap or max heap
     * 
     */
    void heapify(int i){
        int index = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < h.size() && h[left] < h[index]){
            index = left;
        }
        if(right < h.size() && h[right] < h[index]){
            index = right;
        }
        if(index!=i){
            swap(h[i], h[index]);
            heapify(index);
        }
    }

};

int main(){
    Heap h;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x == 1){
            ll val;
            cin >> val;
            h.push(val);
        }else{
            if(x == 2){
                ll val;
                cin >> val;
                h.pop(val);
            }else{
                cout << h.top() << endl;
            }
        }
    }

    return 0;
}

