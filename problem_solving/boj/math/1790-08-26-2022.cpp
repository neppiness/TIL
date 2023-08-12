#include <iostream>
using namespace std;

int N, k;
int tot[11];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> k;

    int nine = 9;
    for(int i = 1; i < 9; i++) {
        tot[i] = i * nine;
        nine *= 10;
    }
    tot[9] = 9;

    int idx = k;
    int lev = 1;
    for(; lev < 9; lev++) {
        if(idx - tot[lev] <= 0) break;
        idx -= tot[lev];
    }
    
    int noIdx = (idx - 1) / lev;
    int num = 1;

    for(int i = 1; i < lev; i++) num *= 10;
    num += noIdx;

    if(num > N) {cout << -1; return 0;}

    int digitIdx = idx - (noIdx) * lev - 1;

    int p10 = 1;
    for(int i = 1; i < lev - digitIdx; i++) p10 *= 10;

    int ans = (num % (p10*10)) / p10;
    cout << ans;
}