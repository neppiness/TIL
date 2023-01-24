#include <bits/stdc++.h>
using namespace std;

const int NMX = 20;
const int MMX = 10'000;

int n, m;
int co[NMX + 2]; // value of ith coin, 1-indexed
int cache[NMX + 2][MMX + 2];

void setup() {
  memset(cache, 0, sizeof(cache));
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> co[i];
  cin >> m;
}

void solve() {
  setup();
  for(int i = 1; i <= n; i++) {
    cache[i][co[i]] = 1;
    for(int k = 1; k <= i; k++)
      for(int j = co[i] + 1; j <= m; j++)
        cache[i][j] += cache[k][j - co[i]];
  }

  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans += cache[i][m];

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}