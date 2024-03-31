#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int nc, id, sc;
    cin >> nc >> id >> sc;
    a[i] = {sc, nc, id};
  }

  sort(a, a + n, greater<tuple<int, int, int>>());
  int cnt[102] = {};
  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto [sc, nc, id] = a[i];
    if (cnt[nc] == 2) continue;
    cout << nc << ' ' << id << '\n';
    cnt[nc]++; ans++;
    if (ans == 3) break;
  }
}
