#include <bits/stdc++.h>
using namespace std;

int a[1002];
unordered_map<int, bool> fr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    fr[x] = 1;
  }

  int ans = 0;
  for (int i = 0; i < m; i++)
    ans += !fr[a[i]];
  cout << ans;
}
