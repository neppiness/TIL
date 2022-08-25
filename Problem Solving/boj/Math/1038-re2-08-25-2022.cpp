#include <iostream>
#include <algorithm>
using namespace std;

long long num[10];
int len;
int seq = 1;
int N;
long long ans = 0;

void solve(int m) {
    if(m == len) {
        seq++;
        if(seq == N) {
            int p10 = 1;
            for(int i = len; i > 0; i--) {
                ans += num[i-1] * p10;
                p10 *= 10;
            }
        }
        return;
    }
    if(m == 0) {
        for(int i = 1; i < 10; i++) {
            num[m] = i;
            solve(m+1);
        }
    } else for(int i = 0; i < num[m-1]; i++) {
        num[m] = i;
        solve(m+1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    if(N == 0) {cout << 0; return 0;}

    seq = 0;
    for(len = 1; len <= 10; len++) solve(0);
    if(ans == 0) cout << -1;
    else cout << ans;
}