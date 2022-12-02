#include <bits/stdc++.h>
using namespace std;

const int MOD = 15746;

int ans[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ans[0] = 1;
  ans[1] = 1;
  for(int i = 2; i <= 1'000'000; i++) {
    ans[i] = ans[i - 1] % MOD + ans[i - 2] % MOD;
    ans[i] %= MOD;
  }

  int i; cin >> i;
  cout << ans[i];
}