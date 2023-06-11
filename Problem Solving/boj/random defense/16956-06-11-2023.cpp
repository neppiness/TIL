#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
char b[502][502];

queue<pair<int, int>> q;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

bool SheepChk(int x, int y) {
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny)) continue;
    if (b[nx][ny] == 'S') return 1;
  }
  return 0;
}

void setwall(int x, int y) {
  for (int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (OOB(nx, ny)) continue;
    if (b[nx][ny] == '.') b[nx][ny] = 'D';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (b[i][j] == 'W' && SheepChk(i ,j)) {
        cout << 0; return 0;
      }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (b[i][j] == 'S') setwall(i, j);

  cout << 1 << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << b[i][j];
    cout << '\n';
  }
}