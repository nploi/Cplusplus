//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/description/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Topic {

public:

    long score;
    long id;
    long scoreNew;

    Topic() {}

    Topic(const Topic &t) {
        this->score = t.score;
        this->id = t.id;
        this->scoreNew = t.scoreNew;
    }

    Topic &operator=(const Topic &t) {
        this->score = t.score;
        this->id = t.id;
        this->scoreNew = t.scoreNew;
        return *this;
    }


};
bool operator > (const Topic &a, const Topic &b){
    if(a.score > b.score){
        return true;
    }else{
        if(a.score == b.score && a.id > b.id){
            return true;
        }
    }
    return false;
}

bool operator < (const Topic &a, const Topic &b){
    if(a.score < b.score){
        return true;
    }else{
        if(a.score == b.score && a.id < b.id){
            return true;
        }
    }
    return false;
}

int main() {
    priority_queue<Topic> pq;

    long long id, z, p, l, s, c, n;

    cin >> n;
    while(n--){
        cin >> id >> z >> p >> l >> c >> s;
        Topic t;
        t.id = id;
        t.scoreNew = p*50 + l*5 + c*10 + s*20;
        t.score = ( t.scoreNew - z);
        pq.push(t);
    }

    n = 5;
    if(pq.size()<5){
        n = pq.size();
    }
    while (n--){
        cout << pq.top().id << " " << pq.top().scoreNew << endl;
        pq.pop();
    }
    return 0;
}
