#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N, M, H;
bool isFailed;
bool hLine[32][11];

int MIN = 0x7f7f7f7f;

void progress() {
    for(int idx = 0; idx < N; idx++) {
        int tmp = idx;
        for(int row = 0; row < H; row++) {
            if(tmp-1 >= 0 && hLine[row][tmp-1]) tmp--;
            else if(hLine[row][tmp]) tmp++;
        }
        if(tmp != idx) {isFailed = true; return;}
    }
}

void solve(int times, vector<pair<int,int>>& cand, vector<pair<int,int>>::iterator it) {
    if(times > 3) {return;}

    isFailed = false;
    progress();
    if(isFailed) {
        for(; it < cand.end(); it++) {
            auto cur = *it;
            int cx = cur.first, cy = cur.second;

            if(hLine[cx][cy]) continue;

            if((cy-1 < 0 || !hLine[cx][cy-1]) && (cy + 1 >= N || !hLine[cx][cy+1])){
                hLine[cx][cy] = 1;
                solve(times+1, cand, it);
                hLine[cx][cy] = 0;
            } else {continue;}
        }
    } else {MIN = min(times, MIN); return;}
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> H;

    for(int row = 0; row < H; row++) fill(hLine[row], hLine[row] + N - 1, 0);

    int temp[2];
    for(int i = 0; i < M; i++) {
        cin >> temp[0] >> temp[1];
        hLine[temp[0] - 1][temp[1] - 1] = 1;
    }

    vector <pair<int,int>> candV;
    for(int row = 0; row < H; row++)
        for(int col = 0; col < N-1; col++)
            if(hLine[row][col] == 0) candV.push_back({row, col});

    solve(0, candV, candV.begin());

    if(MIN == 0x7f7f7f7f) cout << -1;
    else cout << MIN;
}