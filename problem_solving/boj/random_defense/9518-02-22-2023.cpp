#include <bits/stdc++.h>
using namespace std;

const int MX = 50 + 2;

int r, s;
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

char b[MX][MX];
bool vis[MX][MX];

bool oob(int x, int y) { return (x >= r || x < 0 || y >= s || y < 0); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> s;
  for(int i = 0; i < r; i++)
    cin >> b[i];

  int cnt = 0, cand = 0;
  for(int i = 0; i < r; i++)
    for(int j = 0; j < s; j++) {
      if(b[i][j] == '.') {
        int tmp = 0;
        for(int dir = 0; dir < 8; dir++) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if(oob(nx, ny)) continue;
          if(b[nx][ny] == '.') continue;
          tmp++;
        }
        cand = max(tmp, cand);
      } else {
        vis[i][j] = 1;
        for(int dir = 0; dir < 8; dir++) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if(oob(nx, ny) || vis[nx][ny]) continue;
          if(b[nx][ny] == '.') continue;
          cnt++;
        }
      }
    }
  cout << cnt + cand;
}