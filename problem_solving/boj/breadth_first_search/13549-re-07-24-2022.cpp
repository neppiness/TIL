#include <iostream>
#include <queue>

using namespace std;

int dx[2] = {-1, 1};
const int MX = 200001;
bool vis[MX] = {false};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, K; cin >> N >> K;

    queue<int> Q1, Q2;
    int cnt = 0;

    if(N == K) {cout << cnt; return 0;}
    else Q1.push(N);

    while(true) {
        while(!Q1.empty()) {
            auto cur = Q1.front(); Q1.pop();
            for(;cur < MX; cur *= 2){
                if(cur == K) {cout << cnt; return 0;}
                Q2.push(cur); vis[cur] = true;
            }
        }

        cnt++;

        while(!Q2.empty()){
            auto cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 2; dir++){
                int nx = cur + dx[dir];
                if(nx > MX || nx < 0) continue;
                if(vis[nx] == true) continue;

                if(nx == K) {cout << cnt; return 0;}
                Q1.push(nx); vis[nx] = true;
            }
        }
    }
}