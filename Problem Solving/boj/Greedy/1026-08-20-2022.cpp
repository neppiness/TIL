#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[52], B[52];
int idx[52];

bool cmp(int a, int b) {return B[a] <  B[b];}
bool cmpA(int a, int b) {return a > b;}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) idx[i] = i;

    sort(A, A+N, cmpA);
    sort(idx, idx+N, cmp);

    int ans = 0;
    for(int i = 0; i < N; i++) ans += A[i]*B[idx[i]];
    cout << ans;
}