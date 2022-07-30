#include <iostream>

using namespace std;

int WEIGHT[10], HP[10];
int target[10];
int N, mxBE = 0;

void strike() {
    int brokenEgg = 0;

    int weight[N], hp[N];
    for(int i = 0; i < N; i++) {weight[i] = WEIGHT[i]; hp[i] = HP[i];}

    for(int i = 0; i < N; i++) {
        int OP = i, DP = target[OP];
        
        if(hp[OP] <= 0 || hp[DP] <= 0) continue;
        hp[OP] -= weight[DP]; hp[DP] -= weight[OP];
        brokenEgg += (hp[OP] <= 0) + (hp[DP] <= 0);
    }
    mxBE = (mxBE >= brokenEgg) ? mxBE : brokenEgg;
}

void targetting(int m) {
    if(m == N) {strike(); return;}

    for(int tgIdx = 0; tgIdx < N; tgIdx++) {
        if(tgIdx == m) continue;
        target[m] = tgIdx;
        targetting(m + 1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N;

    for(int idx = 0; idx < N; idx++)
        cin >> HP[idx] >> WEIGHT[idx];

    targetting(0);

    cout << mxBE;
}