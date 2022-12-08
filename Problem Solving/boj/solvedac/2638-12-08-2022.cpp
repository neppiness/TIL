#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[102][102];
int cnt;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int, int>> chs; // 치즈 위치를 저장하는 벡터

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void setext() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  b[0][0] = 2;

  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(b[nx][ny] != 0) continue;
      b[nx][ny] = 2;
      q.push({nx, ny});
    }
  }
}

void setmeltchs() {
  chs.clear();
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(b[i][j] == 1) chs.push_back({i, j});

  for(auto [cx, cy] : chs) {
    int extcnt = 0;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(b[nx][ny] == 2) extcnt++;
    }
    if(extcnt >= 2) b[cx][cy] = 3;
  }
}

void melt() {
  for(auto [cx, cy] : chs)
    if(b[cx][cy] == 3)
      b[cx][cy] = 0;
}

void resetBoard() {
  int board[n][m];

  for(int i = 0; i < n; i++)
    fill(board[i], board[i] + m, 0);

  for(auto [cx, cy] : chs)
    if(b[cx][cy] == 1)
      board[cx][cy] = 1;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      b[i][j] = board[i][j];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];

  while(true) {
    setext();
    setmeltchs();
    if(chs.empty()) break;
    melt();
    cnt++;
    resetBoard();
  }
  cout << cnt;
}
/*
b에 저장된 정수의 의미
0: 공기
1: 치즈
2: 외부 공기
3: 녹을 예정인 치즈
*/