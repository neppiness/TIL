#include <bits/stdc++.h>
using namespace std;

const int MX = 50 + 2;

int n, m;
bool a[MX][MX], b[MX][MX];

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

bool toggleMat(int x, int y) {
  if(oob(x + 2, y + 2)) return 0;
  for(int i = x; i < x + 3; i++)
    for(int j = y; j < y + 3; j++)
      a[i][j] = !a[i][j];
  return 1;
}

int solve() {
  int cnt = 0;
  for(int i = 0; i < n - 2; i++)
    for(int j = 0; j < m - 2; j++) {
      if(a[i][j] == b[i][j]) continue;
      cnt++;
      bool is_valid = toggleMat(i, j);
      if(!is_valid) return -1;
    }

  // 마지막 확인
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(a[i][j] != b[i][j]) return -1;
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      a[i][j] = c - '0';
    }
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      char c; cin >> c;
      b[i][j] = c - '0';
    }
  cout << solve();
}