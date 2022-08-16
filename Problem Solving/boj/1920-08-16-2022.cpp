#include <algorithm>
#include <iostream>

using namespace std;

int A[100002], B[100002];
int N, M;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);

    cin >> M;
    for(int i = 0; i < M; i++) cin >> B[i];

    
}