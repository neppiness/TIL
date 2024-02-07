#include <iostream>
using namespace std;

int N, K; 
int comb[1002][1002];
int MOD = 10007;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;

    comb[1][0] = comb[1][1] = 1;
    for(int i = 2; i <= N; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
        }
    }
    
    cout << comb[N][K];
}