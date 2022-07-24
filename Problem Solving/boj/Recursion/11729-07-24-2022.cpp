#include <iostream>

using namespace std;

int moving(int n, int cur, int nxt){
    if(n == 1) {cout << cur << ' ' << nxt << '\n'; return 0;}
}

int count(int N) {
    if(N == 1) return 1;
    return count(N-1)*2 + 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    cout << count(N) << '\n';
}