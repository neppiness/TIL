#include <algorithm>
#include <iostream>
using namespace std;

int N;
int A[10002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);
    long long cnt = 0;
    for(int i = 0; i < N-2; i++)
        for(int j = i+1; j < N-1; j++) {
            int tar = -A[i]-A[j];
            cnt += upper_bound(A+j+1, A+N, tar) - lower_bound(A+j+1, A+N, tar);
        }
    cout << cnt;
}