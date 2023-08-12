#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    N--;

    int fir; cin >> fir;
    while(N--) {
        int res; cin >> res;
        int GCD = gcd(fir, res);
        cout << fir/GCD << '/' << res/GCD << '\n';
    }
}