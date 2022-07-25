#include <iostream>

using namespace std;

int moving(int n, int cur, int nxt){
    if(n == 1) {cout << cur << ' ' << nxt << '\n'; return 0;}
    int rest = 6 - nxt - cur;

    return moving(n-1, cur, rest) + moving(1, cur, nxt) + moving(n-1, rest, nxt);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    cout << ((1 << N) - 1) << '\n';
    
    moving(N, 1, 3);
}