#include <bits/stdc++.h>
using namespace std;

int n, m;
int cx, cy, dir;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool oob(int x, int y) {
  return x < 0 || x > n || y < 0 || y > n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  cx = cy = 0;
  while (m--) {
    string s; int no;
    cin >> s >> no;
    if (s == "MOVE") {
      int nx = cx + no * dx[dir];
      int ny = cy + no * dy[dir];
      if (oob(nx, ny)) {
        cout << -1;
        return 0;
      }
      cx = nx;
      cy = ny;
    } else {
      if (no == 1) dir = (dir + 1) % 4;
      else dir = (dir + 3) % 4;
    }
  }
  cout << cy << ' ' << cx;
}
