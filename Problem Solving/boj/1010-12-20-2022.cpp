#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cache[32][32];

void init() {
  for(int i = 0; i < 31; i++) {
    fill(cache[i], cache[i] + 31, -1);
    cache[i][0] = 1;
    cache[i][i] = 1;
  }
}

ll comb(int n, int m) {
  ll &ret = cache[n][m];
  if(ret != -1) return ret;
  return ret = comb(n-1, m) + comb(n-1, m-1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();
  int t; cin >> t;
  while(t--) {
    int m, n; cin >> m >> n;
    cout << comb(n, m) << '\n';
  }
}