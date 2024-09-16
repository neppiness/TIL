#include <bits/stdc++.h>
using namespace std;

int cnt[150];
int st[150];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int x;
    string cmd;
    int h, m;
    cin >> x >> cmd >> h >> m;
    if (cmd == "START") {
      st[x] = h * 60 + m;
    } else {
      cnt[x] += (h * 60 + m - st[x]);
    }
  }
  for (int i = 1; i <= n; i++)
    cout << cnt[i] / 60 << ' ' << cnt[i] % 60 << '\n';
}
