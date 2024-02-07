// Wasted solution
#include <iostream>
#include <queue>

using namespace std;

const int MX = 200001;
bool vis[MX] = {false};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;

    int cnt = 0;
    queue<int> qDoubled, qPlusMinus;

    while(N < MX){
        if(N == K) {cout << cnt; return 0;}
        if(vis[N] != true) {
            vis[N] = true;
            qDoubled.push(N);
            N *= 2;
        }
    }

    while(!qDoubled.empty()) {
        cnt++;
        while(!qDoubled.empty()) {
            auto cur = qDoubled.front(); qDoubled.pop();
            if(cur-1 == K || cur+1 == K) {cout << cnt; return 0;}
            if(cur+1 > MX || cur-1 < 0) continue;
            if(vis[cur-1] != true) {vis[cur-1] = true; qPlusMinus.push(cur-1);}
            if(vis[cur+1] != true) {vis[cur+1] = true; qPlusMinus.push(cur+1);}
        }

        while(!qPlusMinus.empty()) {
            auto cur = qPlusMinus.front(); qPlusMinus.pop();
            if(cur*2 > MX) continue;
            if(cur*2 == K) {cout << cnt; return 0;}
            if(vis[cur*2] != true) {vis[cur*2] = true; qDoubled.push(cur*2);}
        }
    }
}