#include <iostream>
#include <algorithm>

using namespace std;

int n, w, L;

int trW[12];
int trSt[12] = {0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> n >> w >> L;

    for(int i = 0; i < n; i++) cin >> trW[i];

    fill(trSt + 1, trSt + 12, -1);

    int beReadyIdx = 1, movingTrIdx = 0;
    int time = 0, weight;

    do {
        weight = 0;
        for(int i = movingTrIdx; i < beReadyIdx; i++) {
            trSt[i]++;
            if(trSt[i] == w) {movingTrIdx++; continue;}
            weight += trW[i];
        }
        if(weight + trW[beReadyIdx] <= L) {trSt[beReadyIdx]++; beReadyIdx++;}
        time++;
    } while(trSt[n] != w);

    cout << time;
}