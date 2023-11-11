#include <bits/stdc++.h>
using namespace std;

int cnt, n, m;
int memo[4];
set<pair<int, int>> banned;

void solve(int picked, int prev) {
  if (picked == 3) {
    int tmp[3];
    for (int i = 0; i < 3; i++)
      tmp[i] = memo[i];
    sort(tmp, tmp + 3);

    auto it = banned.find({tmp[0], tmp[1]});
    if (it != banned.end()) return;

    it = banned.find({tmp[0], tmp[2]});
    if (it != banned.end()) return;

    it = banned.find({tmp[1], tmp[2]});
    if (it != banned.end()) return;

    cnt++;
    return;
  }

  for (int i = prev + 1; i <= n; i++) {
    memo[picked] = i;
    solve(picked + 1, i);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    banned.insert({x, y});
  }
  solve(0, 0);
  cout << cnt;
}
