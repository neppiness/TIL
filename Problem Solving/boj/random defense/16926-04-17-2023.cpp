#include <bits/stdc++.h>
using namespace std;

const int MX = 300;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, r;
int b[MX + 2][MX + 2], tmp[MX + 2][MX + 2];

int mnx, mny, mxx, mxy;

bool oob(int x, int y) {
  return (x < mnx || x >= mxx || y < mny || y >= mxy);
}

void rotate() {
  mnx = 0, mny = 0, mxx = n, mxy = m;
  while(mnx < mxx && mny < mxy) {
    int cx = mnx, cy = mny;
    int dir = 0;
    while(dir < 4) {
      int nx = cx + dx[dir]; 
      int ny = cy + dy[dir];
      if(oob(nx, ny)) { dir++; continue; }
      tmp[nx][ny] = b[cx][cy];
      swap(cx, nx); swap(cy, ny);
    }
    mnx++; mxx--; mny++; mxy--;
  }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      b[i][j] = tmp[i][j];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];

  while(r--) rotate();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      cout << b[i][j] << ' ';
    cout << '\n';
  }
}