#include <bits/stdc++.h>
using namespace std;

int n;
int cache[10'000'002][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cache[1][0] = 1;
  cache[1][1] = 0;
  for (int i = 2; i <= n; i++) {
    cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
    if (cache[i][0] > 10) cache[i][0] -= 10;
    cache[i][1] = cache[i - 1][0];
    if (cache[i][0] > 10) cache[i][0] -= 10;
  }
  int ans = cache[n][0] + cache[n][1];
  if (ans > 10) ans -= 10;
  cout << ans;
}