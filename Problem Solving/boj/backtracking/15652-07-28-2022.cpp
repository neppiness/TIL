#include <iostream>

using namespace std;

int N, M;
int ans[10];

void search(int m, int min){
    if (m == M) {
        for (int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for (int num = min; num <= N; num++) {
            ans[m] = num;
            search(m+1, num);
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    search(0, 1);
}