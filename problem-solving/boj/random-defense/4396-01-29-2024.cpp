#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int n; 
char b[12][12];
bool opened[12][12];

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  bool is_mine_found = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c; cin >> c;
      opened[i][j] = (c == 'x');
      is_mine_found |= (opened[i][j] && b[i][j] == '*');
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (b[i][j] == '.' && opened[i][j]) {
        int cnt = 0;
        for (int dir = 0; dir < 8; dir++) {
          int ni = i + dx[dir];
          int nj = j + dy[dir];
          if (oob(ni, nj) || b[ni][nj] == '.') continue;
          cnt++;
        }
        cout << cnt;
      } else if (b[i][j] == '*' && is_mine_found) {
        cout << '*';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
}
