#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'009;
const int MX = 100'000;

int cache[MX + 2][4];

int calc(int sum, int no) {
  int &ret = cache[sum][no];
  if(ret != -1) return ret;

  ret = 0;
  if(sum == no) return ret = 1;
  for(int i = 1; i <= 3; i++) {
    if(no == i || sum - no < 0) continue;
    ret += calc(sum - no, i);
    if(ret >= MOD) ret -= MOD;
  }
  return ret;
}

int solve(int x) {
  return (((calc(x, 1) + calc(x, 2)) % MOD) + calc(x, 3)) % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  int n; cin >> n;
  while(n--) {
    int x; cin >> x;
    cout << solve(x) << '\n';
  }
}