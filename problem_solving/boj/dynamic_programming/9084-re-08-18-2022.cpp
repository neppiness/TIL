#include <iostream>
using namespace std;

int CO[22];
int ans[10002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int n = 0; n < N; n++) cin >> CO[n];

        int M; cin >> M;

        fill(ans, ans+M+1, 0); ans[0] = 1;
        for(int co = 0; co < N; co++)
            for(int m = CO[co]; m <= M; m++)
                ans[m] += ans[m-CO[co]];

        cout << ans[M] << '\n';
    }
}