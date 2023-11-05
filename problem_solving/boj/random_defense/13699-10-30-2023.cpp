#include <bits/stdc++.h>
using namespace std;

long long t[37];

long long solve(int n) {
  long long &ret = t[n];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = 0; i < n; i++) {
    ret += solve(i) * solve(n - i - 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(t, -1, sizeof(t));
  t[0] = 1;

  int n; cin >> n;
  cout << solve(n);
}
