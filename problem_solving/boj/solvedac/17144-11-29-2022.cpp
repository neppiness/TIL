#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int board[52][52];
vector<pair<int, int>> pf;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void spr() {
  int b[52][52];

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      b[i][j] = board[i][j];

  for(int cx = 0; cx < r; cx++) {
    for(int cy = 0; cy < c; cy++) {
      if(board[cx][cy] == -1) continue;
      if(!board[cx][cy]) continue;
      
      int cnt = 0;
      for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(nx >= r || nx < 0) continue;
        if(ny >= c || ny < 0) continue;
        if(board[nx][ny] == -1) continue;
        b[nx][ny] += board[cx][cy] / 5;
        cnt++;
      }
      b[cx][cy] -= board[cx][cy] / 5 * cnt;
    }
  }

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      board[i][j] = b[i][j];
}

bool oob(int x, int y, bool code) {
  int limx;
  tie(limx, ignore) = pf[code];
  if(y >= c || y < 0) return true;
  if(code == 0)
    return (limx < x || x < 0);
  else
    return (limx > x || x >= r);
}

void cir() {
  int dx[2][4] = {{-1, 0, 1, 0}, {1, 0, -1, 0}};
  int dy[2][4] = {{0, 1, 0, -1}, {0, 1, 0, -1}};

  for(int idx = 0; idx < 2; idx++) {
    int cx, cy;
    tie(cx, cy) = pf[idx];
    cx += dx[idx][0];
    cy += dy[idx][0];

    int dir = 0;
    int nx, ny;
    while(true) {
      nx = cx + dx[idx][dir];
      ny = cy + dy[idx][dir];
      if(oob(nx, ny, idx)) {
        dir++;
        continue;
      }
      if(board[nx][ny] == -1) {
        board[cx][cy] = 0;
        break;
      }
      board[cx][cy] = board[nx][ny];
      swap(nx, cx); swap(ny, cy);
    }
  }
}

int total() {
  int tot = 0;
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++) {
      if(board[i][j] == -1) continue;
      tot += board[i][j];
    }
  return tot;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> t;

  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++) {
      cin >> board[i][j];
      if(board[i][j] == -1)
        pf.push_back({i, j});
    }

  while(t--) {
    spr();
    cir();
  }
  cout << total();
}
