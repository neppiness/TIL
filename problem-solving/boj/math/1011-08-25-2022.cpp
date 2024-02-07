#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--){
        int a, b; cin >> a >> b;
        int len = b - a;

        long long N = sqrt(len); N--;
        while(len > N*N) N++;
        N--;
        if(len > N*N + N) cout << 2*N + 1 << '\n';
        else cout << 2*N << '\n';
    }
}