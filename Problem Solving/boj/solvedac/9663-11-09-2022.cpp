#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool c[17], m[32], p[32];

bool onQ(int x, int y) { return (c[y] || m[x - y + n] || p[x + y]); }

void occ(int x, int y, bool code) {
  c[y] = code;
  m[x - y + n] = code;
  p[x + y] = code;
}

void solve(int row) {
  if(row == n) {
    cnt++;
    return;
  }
  for(int col = 0; col < n; col++) {
    if(onQ(row, col)) continue;
    occ(row, col, 1);
    solve(row + 1);
    occ(row, col, 0);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  solve(0);

  cout << cnt;
}