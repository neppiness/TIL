#include <iostream>
#include <algorithm>

using namespace std;

int N, M, L;
int ST[152], DIST[152];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> L;

    ST[0] = 0; ST[N+1] = L;
    for(int i = 1; i <= N; i++) cin >> ST[i];
    sort(ST, ST+N+2);

    for(int i = 0; i <= N; i++) DIST[i] = ST[i+1] - ST[i];

    for(int SZ = N+1; SZ <= N + M; SZ++) {
        int mIDX = max_element(DIST, DIST+SZ) - DIST;
        int mDIST = DIST[mIDX];
        DIST[mIDX] /= 2;
        DIST[SZ] = mDIST - DIST[mIDX];
    }
    cout << *max_element(DIST, DIST+M+N+1);
}