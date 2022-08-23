#include <iostream>
using namespace std;

int N, T;
int num[1000002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while(T--) {
        cin >> N;
        int i = 0;
        for(; i < N; i++) cin >> num[i];

        int MX = 0;
        long long ans = 0;
        while(i--) {
            if(num[i] >= MX) MX = num[i];
            else ans += MX - num[i];
        }
        cout << ans << '\n';
    }
}