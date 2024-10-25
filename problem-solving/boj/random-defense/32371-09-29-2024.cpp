#include <bits/stdc++.h>
using namespace std;

int m;
string key[4];
unordered_map<char, bool> memo;

int dx[] = {0, 1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};

bool oob(int x, int y) {
  return x >= 4 || x < 0 || y >= m || y < 0;
}

bool is_solved(int cx, int cy) {
  for (int dir = 0; dir < 9; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    if (oob(nx, ny) || !memo[key[nx][ny]]) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 4; i++)
    cin >> key[i];
  string s; cin >> s;
  for (char c : s) {
    memo[c] = 1;
  }

  m = key[0].size();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < m; j++) {
      if (!is_solved(i, j)) continue;
      cout << key[i][j];
      return 0;
    }
  }
}
