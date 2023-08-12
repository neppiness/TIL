#include <iostream>
using namespace std;

int N;
int T[1500002], P[1500002], A[1500002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> T[i] >> P[i];

    for(int i = 0; i < N; i++) {
        A[i+1] = max(A[i], A[i+1]);
        if(T[i] + i <= N)
            A[T[i] + i] = max(A[T[i] + i], A[i] + P[i]);
    }
    cout << A[N];
}