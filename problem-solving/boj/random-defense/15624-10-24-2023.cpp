#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int p[1'000'002];

int pibo(int n) {
  int &ret = p[n];
  if (ret != -1) return ret;
  return ret = (pibo(n - 1) + pibo(n - 2)) % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  p[0] = 0; p[1] = 1; p[2] = 1;

  int n; cin >> n;
  cout << pibo(n);
}
