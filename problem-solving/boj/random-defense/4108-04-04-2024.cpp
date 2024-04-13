#include <bits/stdc++.h>
using namespace std;

int n, m; 
char b[102][102];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (n != 0) {
    for (int i = 0; i < n; i++)
      cin >> b[i];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (b[i][j] == '*') continue;
        b[i][j] = '0';
        for (int dir = 0; dir < 8; dir++) {
          int ni = i + dx[dir];
          int nj = j + dy[dir];
          if (oob(ni, nj)) continue;
          b[i][j] += (b[ni][nj] == '*');
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cout << b[i][j];
      cout << '\n';
    }
    cin >> n >> m;
  }
}
