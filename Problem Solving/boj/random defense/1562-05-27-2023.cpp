#include <bits/stdc++.h>
using namespace std;

const int full = 1023;
const int mod = 1'000'000'000;
int cache[102][full + 2][10];

int solve(int lv, int no, int st) {
  if (lv == 0) { return st == full; }
  int &ret = cache[lv][st][no];
  if (ret != -1) return ret;
  
  ret = 0;
  if (no != 0) {
    ret += solve(lv - 1, no - 1, st | (1 << (no - 1)));
    if (ret > mod) ret -= mod;
  }
  if (no != 9) {
    ret += solve(lv - 1, no + 1, st | (1 << (no + 1)));
    if (ret > mod) ret -= mod;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  memset(cache, -1, sizeof(cache));

  int sum = 0;
  for (int i = 1; i < 10; i++) {
    sum += solve(n - 1, i, (1 << i));
    if (sum > mod) sum -= mod;
  }
  cout << sum;
}