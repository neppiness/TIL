#include <iostream>
using namespace std;

int T, N, M;
int CO[22];
int noCO[22];
int cnt;

void solve(int n, int res) {
    if(n == 0) {
        if(!res) cnt++;
        return;
    }

    n--;
    noCO[n] = res/CO[n];
    do {
        res -= noCO[n]*CO[n];
        solve(n, res);
        res += noCO[n]*CO[n];
    } while(noCO[n]--);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;

    while(T--) {
        cnt = 0;
        cin >> N;
        for(int co = 0; co < N; co++) cin >> CO[co];

        cin >> M;

        solve(N, M);
        cout << cnt << '\n';
    }
}