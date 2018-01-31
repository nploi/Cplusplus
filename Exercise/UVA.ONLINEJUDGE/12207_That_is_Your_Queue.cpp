//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3359

#include<iostream>
#include<queue>

using namespace std;

int number = 1;

bool thatIsYourQueue() {
    queue<int> Queue;
    int P, C;
    char Char;
    cin >> P >> C;
    if (P == 0 && C == 0) {
        return false;
    }
    cout <<"Case "<<number<<":\n";
    number++;
    int Min = min(P, C);

    for (int i = 1; i <= Min; i++) {
        Queue.push(i);
    }

    for (int i = 0; i < C; i++) {
        char command;
        int x;
        cin >> command;
        if (command == 'N') {
            cout << Queue.front() << endl;
            Queue.push(Queue.front());
            Queue.pop();

        } else {
            cin >> x;
            queue<int> Qtemp;
            Qtemp.swap(Queue);
            Queue.push(x);
            while (!Qtemp.empty()) {
                if (Qtemp.front() != x) {
                    Queue.push(Qtemp.front());
                    Qtemp.pop();
                    continue;
                }
                Qtemp.pop();
            }
        }
    }
    return true;
}

int main(){

    while(thatIsYourQueue());
    return 0;
}
