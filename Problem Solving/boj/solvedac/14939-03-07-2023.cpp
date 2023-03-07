#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 1, 1, 2};
int dy[] = {0, -1, 0, 1, 0};

bool b[10][10];

void toggle(int cx, int cy) {
  for(int dir = 0; dir < 5; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    b[nx][ny] = !b[nx][ny];
  }
}

int solve() {
  int cnt = 0;
  for(int i = 0; i < 8; i++) // i, i + 1, i + 2
    for(int j = 1; j < 9; j++) { // j - 1, j, j + 1
      if(!b[i][j]) continue;
      toggle(i, j);
      cnt++;
    }
  
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      if(b[i][j]) return -1;
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++) {
      char c; cin >> c;
      b[i][j] = (c == 'O');
    }
  cout << solve();
}