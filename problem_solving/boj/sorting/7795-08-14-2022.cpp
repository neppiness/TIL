#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    int arrA[20002], arrB[20002];
    while(T--) {
        int N, M; cin >> N >> M;

        for(int i = 0; i < N; i++) cin >> arrA[i];
        for(int i = 0; i < M; i++) cin >> arrB[i];

        sort(arrA, arrA+N); sort(arrB, arrB+M);

        int cnt = 0, ans = 0;
        int idx = 0;
        for(int i = 0; i < N; i++) {
            for(;idx < M; idx++) {
                if(arrA[i] > arrB[idx]) cnt++;
                else break;
            }
            ans += cnt;
        }
        cout << ans << '\n';
    }
}