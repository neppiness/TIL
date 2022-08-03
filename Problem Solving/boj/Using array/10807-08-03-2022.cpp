#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, v; cin >> N;
    int num[N];

    for(int i = 0; i < N; i++) cin >> num[i];

    cin >> v;

    int ans = 0;
    for(int i = 0; i < N; i++) ans += (num[i] == v);

    cout << ans;
}