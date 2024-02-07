#include <bits/stdc++.h>
using namespace std;

int depth(int x) {
  int cnt = 0;
  while (x) {
    x /= 2;
    cnt++;
  }
  return cnt;
}

int move(int x, int d) {
  while (d--) x /= 2;
  return x;
}

int solve() {
  int x, y; cin >> x >> y;
  if (x > y) swap(x, y); // x는 항상 작은 수
  int dx = depth(x);
  int dy = depth(y);
  y = move(y, dy - dx);
  while (x != y) {
    x /= 2;
    y /= 2;
  }
  return x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
    cout << solve() * 10 << '\n';
}
