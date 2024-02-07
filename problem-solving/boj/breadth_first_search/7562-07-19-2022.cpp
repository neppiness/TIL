#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int dat[300][300];

int dX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dY[8] = {2, 1, -1, -2, 2, 1, -1, -2};

void clr(int l) {
    for (int i = 0; i < l; i++) {
        for(int j = 0; j < l; j++) {
            dat[i][j] = -1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int noCases; cin >> noCases;

    while(noCases--) {
        int l; cin >> l; clr(l);

        pair<int,int> current; cin >> (current.X) >> (current.Y);
        pair<int,int> target; cin >> (target.X) >> (target.Y);

        bool isFound = false;

        queue<pair<int,int>> Q;
        dat[current.X][current.Y] = 0;

        if((current.X == target.X) && (current.Y == target.Y)) {
            cout << 0 << '\n'; continue;
        }

        Q.push(current);

        while(!Q.empty()) {
            pair<int,int> cur;
            cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dX[dir];
                int ny = cur.Y + dY[dir];

                if(nx >= l || nx < 0 || ny >= l || ny < 0) continue;
                if(dat[nx][ny] != -1) continue;

                dat[nx][ny] = dat[cur.X][cur.Y] + 1;
                if(nx == target.X && ny == target.Y) {
                    isFound = true;
                    cout << dat[nx][ny] << '\n';
                    break;
                }
                Q.push({nx,ny});
            }
            if(isFound) break;
        }
    }
}