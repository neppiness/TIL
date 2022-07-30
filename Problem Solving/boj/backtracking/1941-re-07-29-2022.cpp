#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

char board[5][5];
bool isUsed[5][5] = {false};

int cnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int nx, int ny) {
    if(nx >= 5 || nx < 0 || ny >= 5 || ny < 0) return 1;
    return 0;
}

void search(int m, int i) {
    if(m == 7) {
        bool isCounted[5][5] = {false};

        int sCnt = 0, length = 1;
        int cx = i / 5; int cy = i % 5;

        queue<pair<int,int>> Q;
        Q.push({cx, cy});
        isCounted[cx][cy] = 1;
        if(board[cx][cy] == 'S') sCnt++;

        while(!Q.empty()) {
            auto coord = Q.front(); Q.pop();
            int cx = coord.first; int cy = coord.second;

            for(int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir]; int ny = cy + dy[dir];
                if(OOB(nx, ny)) continue;
                if(!isUsed[nx][ny] || isCounted[nx][ny]) continue;
                if(board[nx][ny] == 'S') sCnt++;
                isCounted[nx][ny] = 1;
                Q.push({nx, ny}); length++;
            }
        }
        if(length != 7) return;
        if(sCnt >= 4) {cnt++; return;}
    }

    for(int cur = i; cur < 25; cur++) {
        int row = cur / 5; int col = cur % 5;
        if(isUsed[row][col]) continue;
        isUsed[row][col] = 1;
        search(m + 1, cur);
        isUsed[row][col] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string input;
    for(int row = 0; row < 5; row++) {
        cin >> input;
        for(int col = 0; col < 5; col++) {
            board[row][col] = input[col];
        }
    }

    /*
    // For simple input
    for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
    */

    search(0, 0);
    cout << cnt;
}