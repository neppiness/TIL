#include <bits/stdc++.h>
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

string com;

void solve() {
  int mx = 0, my = 0, Mx = 0, My = 0;
  cin >> com;
  int cx = 0, cy = 0, dir = 0;
  for (char c : com) {
    switch(c) {
      case 'R': dir = (dir + 1) % 4; break;
      case 'L': dir = (dir + 3) % 4; break;
      case 'F': cx += dx[dir]; cy += dy[dir]; break;
      default : cx -= dx[dir]; cy -= dy[dir];
    }
    mx = min(mx, cx); my = min(my, cy);
    Mx = max(Mx, cx); My = max(My, cy);
  }
  cout << (Mx - mx) * (My - my) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}