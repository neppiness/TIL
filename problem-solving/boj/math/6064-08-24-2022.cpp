#include <iostream>
using namespace std;

int M, N;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm() {return M / gcd(M, N) * N;}

int solve() {
    int x, y;
    cin >> M >> N >> x >> y;
    int limit = lcm()/M;
    for(int i = 0; i <= limit; i++) {
        int num = M * i + x - 1;
        if((num % N) + 1 == y) return num + 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    while(T--) cout << solve() << '\n';
}