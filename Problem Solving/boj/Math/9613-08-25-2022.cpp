#include <iostream>
using namespace std;

int num[102];

int GCD(int a, int b) {
    if(a == 0) return b;
    return GCD(b%a, a);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i = 0; i < N; i++) cin >> num[i];

        long long ans = 0;
        for(int i = 0; i < N-1; i++)
            for(int j = i+1; j < N; j++)
                ans += GCD(num[i], num[j]);
        cout << ans << '\n';
    }
}