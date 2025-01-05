#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n; 
int a[752][752];

bool oob(int x, int y) {
  return x >= n || x < 0 || y >= n || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int no = 1, dir = 0;
  int cx = 0, cy = 0;
  while (1) {
    a[cx][cy] = no++;
    int nx, ny;
    bool is_determined = 0;
    for (int d = 0; d < 4; d++) {
      nx = cx + dx[dir];
      ny = cy + dy[dir];
      if (oob(nx, ny) || a[nx][ny]) {
        dir = (dir + 1) % 4;
        continue;
      }
      is_determined = 1;
      break;
    }
    if (!is_determined) break;
    cx = nx; cy = ny;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << ' ';
    cout << '\n';
  }
}
