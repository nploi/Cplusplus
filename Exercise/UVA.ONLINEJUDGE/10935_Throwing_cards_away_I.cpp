//
// Created by nguyenphucloi on 1/18/18.
//
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;


int main() {
    int n;
    do {

        queue<int> queueDiscardedCrads, queueRemainCard;
        cin >> n;

        if(n==0)
            break;

        for (int i = 1; i <= n; i++) {
            queueRemainCard.push(i);
        }

        while (queueRemainCard.size() > 1) {

            if (queueRemainCard.size() > 2) {

                int val1 = queueRemainCard.front();
                queueRemainCard.pop();

                int val2 = queueRemainCard.front();
                queueRemainCard.pop();

                queueDiscardedCrads.push(val1);

                queueRemainCard.push(val2);

            } else {

                if(queueRemainCard.size() == 2){

                    int val1 = queueRemainCard.front();

                    queueRemainCard.pop();

                    queueDiscardedCrads.push(val1);

                    break;

                }
            }
        }
        if(queueDiscardedCrads.empty()){
            cout << "Discarded cards:";
        }else {
            cout << "Discarded cards: " << queueDiscardedCrads.front();

            queueDiscardedCrads.pop();


            while (!queueDiscardedCrads.empty()) {

                cout << ", " << queueDiscardedCrads.front();

                queueDiscardedCrads.pop();

            }
        }
        cout << "\nRemaining card: " << queueRemainCard.front() <<"\n";

        queueRemainCard.pop();

    } while (n != 0);

    return 0;
}


