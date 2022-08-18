#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
char board[1002][1002];

queue<pair<int, int>> Q;

bool solve(int L) {
    int cycle = Q.size();

    while(cycle--) {
        auto cur = Q.front(); Q.pop();
        int cx = cur.first, cy = cur.second;
        int nx = cx + L, ny = cy + L;
        if(nx > n || ny > m) continue;

        bool isValid = true;
        for(int row = cx; row < nx; row++) {
            for(int col = cy; col < ny; col++) {
                if(board[row][col]-'0' < L-1) {isValid = false; break;}
            }
            if(!isValid) break;
        }
        if(isValid) {
            for(int row = cx; row < nx; row++)
                for(int col = cy; col < ny; col++) board[row][col] = '0' + L;
            Q.push(cur);
        }
    }
    if(!Q.empty()) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    for(int row = 0; row < n; row++) cin >> board[row];
    
    for(int row = 0; row < n; row++)
        for(int col = 0; col < m; col++)
            if(board[row][col] == '1') Q.push({row, col});

    int len = 1;
    for(; len < 1000; len++) {
        if(!solve(len + 1)) break;
    }

    cout << len * len;
}