#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 5005;
int nxt[MX], pre[MX], dat[MX];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    fill(nxt, nxt+MX, -1);
    fill(pre, pre+MX, -1);
    
    int N, K;

    cin >> N >> K;

    // Initialize
    for (int i = 1; i <= N; i++) {
        dat[i] = i;
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    nxt[0] = 1;
    pre[1] = N;
    nxt[N] = 1;

    cout << '<';

    int idx = 0;
    while(N--) {
        int k = K;
        while(k--) idx = nxt[idx];
        
        nxt[pre[idx]] = nxt[idx];
        pre[nxt[idx]] = pre[idx];

        cout << dat[idx];
        if(N != 0) cout << ", ";
    }
    cout << '>';
}