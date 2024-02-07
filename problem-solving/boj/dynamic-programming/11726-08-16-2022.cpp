#include <iostream>

using namespace std;

int cases[1002];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    cases[1] = 1; cases[2] = 2;
    
    for(int i = 3; i <= n; i++) {
        cases[i] = cases[i-1] + cases[i-2];
        cases[i] %= 10007;
    }
    cout << cases[n];
}