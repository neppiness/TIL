#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100002];
int RES = 2123123123;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int st, en = 0;
    for(st = 0; st < N; st++) {
        while(A[en] - A[st] < M && en < N) en++;
        if(en >= N) break;
        RES = min(RES, A[en] - A[st]);
    }
    cout << RES;
}