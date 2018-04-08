//https://www.hackerrank.com/challenges/2d-array/problem

#include <bits/stdc++.h>

#define MAX 1e9

using namespace std;

/*
 * Complete the array2D function below.
 */
int array2D(vector<vector<int>> arr) {
    int Max = -MAX, limit = 0, check = 0;
    for (int i = 0; i < 4; ++i) {
        check = 0;
        for (int j = 0; j < 4; ++j) {
            int sum = 0;
            for (int l = j; l < j + 3; ++l) {
                sum += arr[i][l];
            }
            sum += arr[i + 1][j + 1];
            for (int l = j; l < j + 3; ++l) {
                sum += arr[i + 2][l];
            }
            if (sum > Max) {
                Max = sum;
            }
        }
    }
    return Max;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int arr_row_itr = 0; arr_row_itr < 6; arr_row_itr++) {
        arr[arr_row_itr].resize(6);

        for (int arr_column_itr = 0; arr_column_itr < 6; arr_column_itr++) {
            cin >> arr[arr_row_itr][arr_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = array2D(arr);

    cout << result << "\n";

    fout.close();

    return 0;
}

