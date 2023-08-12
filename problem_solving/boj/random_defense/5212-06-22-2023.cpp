#include <bits/stdc++.h>
using namespace std;

int n, m;
char b[12][12];
int vcnt[12][12];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] == '.') continue;
      vcnt[i][j] = 4;
      for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];
        if (OOB(ni, nj) || b[ni][nj] == '.') continue;
        vcnt[i][j]--;
      }
    }
  }

  int mx = 12, my = 12, Mx = 0, My = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] == '.') continue;
      if (vcnt[i][j] >= 3) { b[i][j] = '.'; continue; }
      mx = min(mx, i); Mx = max(Mx, i);
      my = min(my, j); My = max(My, j);
    }
  }
  
  for (int i = mx; i <= Mx; i++) {
    for (int j = my; j <= My; j++)
      cout << b[i][j];
    cout << '\n';
  }
}