#include <bits/stdc++.h>
using namespace std;

int n, k, q, m;
bool is_checked[5004];
bool is_sleeping[5004];
int ps[5004];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> q >> m;
  while (k--) {
    int x; cin >> x;
    is_sleeping[x] = 1;
  }

  while (q--) {
    int x; cin >> x;
    if (is_sleeping[x]) continue;
    for (int cur = x; cur <= n + 2; cur += x) {
      is_checked[cur] = 1;
    }
  }

  for (int i = 3; i <= n + 2; i++) {
    ps[i] += (!is_checked[i] || is_sleeping[i]) + ps[i - 1];
  }

  while (m--) {
    int a, b; cin >> a >> b;
    cout << ps[b] - ps[a - 1] << '\n';
  }
}
