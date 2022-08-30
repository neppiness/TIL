#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long long A[100002];
long long RES = 0x7f7f7f7f7f7f7f;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    for(int i = 0; i < N-1; i++) {
        int idx = lower_bound(A+i+1, A+N, A[i] + M) - A;
        if(idx == N) continue;

        long long res = A[idx] - A[i];
        if(RES > res) RES = res;
    }
    cout << RES;
}