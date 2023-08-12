#include <iostream>

using namespace std;

int main(){
    ios:: sync_with_stdio(0); cin.tie(0);

    int N, indices;
    cin >> N >> indices;

    // arr init.
    int arr[N];
    for (int i = 0; i < N; i++) arr[i] = i + 1;

    int cursor = 0, answer = 0;
    int length = N;

    while(indices--) {
        int num, count = 0;
        cin >> num;

        while(arr[cursor] != num) {
            if(arr[cursor] != -1) count++;
            cursor++;
            cursor %= N;
        }

        arr[cursor++] = -1;
        cursor %= N;
        answer += min(count, length - count);
        length--;
    }

    cout << answer;
}