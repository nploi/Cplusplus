//https://www.hackerrank.com/challenges/sparse-arrays/problem

#include <bits/stdc++.h>

using namespace std;


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int strings_itr = 0; strings_itr < strings_count; strings_itr++) {
        string strings_item;
        getline(cin, strings_item);

        strings[strings_itr] = strings_item;
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    map<string, int> m;
    for (int i = 0; i < strings.size(); ++i) {
        m[strings[i]]++;
    }
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string queryString;
        getline(cin, queryString);
        int res = m[queryString];

        cout << res << "\n";
    }

    fout.close();

    return 0;
}
