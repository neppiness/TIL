#include <iostream>
using namespace std;

int N, M;
int num;
int sum[100002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> num;
        sum[i] = num + sum[i-1];
    }

    while(M--) {
        int begin, end;
        cin >> begin >> end;

        cout << sum[end] - sum[begin-1] << '\n';
    }
}